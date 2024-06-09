#include "../rtaudio/RtAudio.h"
#include "../rtDaisySP/src/daisysp.h"
#include "../rtDStudio/src/dstudio.h"
#include <iostream>
#include <cstdlib>
#include <signal.h>

#include "main.h"

#include "rtApp.h"

// RtAudio
rtApp rt_app;

// Interrupt handler function
bool done;
static void finish( int /*ignore*/ )
{
    done = true;
}



// error handler
void errorCallback(RtAudioErrorType /*type*/, const std::string &errorText)
{
	std::cerr << "\nerrorCallback: " << errorText << "\n\n";
}



// ACB interleaved
int audioCallback(void *output_buffer,
				  void * /*inputBuffer*/, 
				  unsigned int frame_count,
         		  double stream_time,
         		  RtAudioStreamStatus status,
         		  void *data)
{

	// audio rate

	MY_TYPE *buffer = (MY_TYPE *)output_buffer;

	if (status)
		std::cout << "Stream underflow detected!" << std::endl;

    for(size_t i = 0; i < frame_count; i++)
	{
        MY_TYPE sigL, sigR;
        rt_app.Process(&sigL, &sigR);
        *buffer = sigL;
        buffer++;
        *buffer = sigR;
        buffer++;
    }

    return 0;
}



// main

int main()
{
	// DStudio setup

    rt_app.Setup();

	// RtAudio setup
	float sample_rate = DSTUDIO_SAMPLE_RATE;
    unsigned int rt_device;
	unsigned int rt_channels = 2;
    unsigned int rt_buffer_frames = DSTUDIO_BUFFER_SIZE;

	RtAudio::StreamParameters rt_params;
 	RtAudio::StreamOptions rt_options;
	double *data;
	RtAudio::DeviceInfo rt_info;

    // Rtaudio init
    RtAudio rt_dac(RtAudio::LINUX_ALSA, &errorCallback);
	
    // output all messages
    rt_dac.showWarnings(true);

    // setup device
	std::vector<unsigned int> deviceIds = rt_dac.getDeviceIds();
	if ( deviceIds.size() < 1 ) {
		std::cout << "\nNo audio devices found!\n";
		goto cleanup;
	}
	
   	std::cout << "\nFound " << deviceIds.size() << " device(s).\n";
	std::cout << "\nAPI: " << RtAudio::getApiDisplayName(rt_dac.getCurrentApi()) << std::endl;

	std::cout << "\n";

	// list device information
	// and set our device id
	rt_device = 0;

	for (unsigned int i = 0; i < deviceIds.size(); i++)
	{
		rt_info = rt_dac.getDeviceInfo(deviceIds[i]);
		if (rt_info.name.rfind("MAX98357A", 0) == 0)
		{
			rt_device = deviceIds[i];
		}

   		std::cout << "Device Name = " << rt_info.name << "\n";
		std::cout << "Device ID = " << deviceIds[i] << "\n";
		std::cout << "Output Channels = " << rt_info.outputChannels << "\n";
		std::cout << "Input Channels = " << rt_info.inputChannels << "\n";
		std::cout << "Duplex Channels = " << rt_info.duplexChannels << "\n";
		if (rt_info.isDefaultOutput)
			std::cout << "Default output device.\n";
		else
			std::cout << "NOT default output device.\n";
		if (rt_info.isDefaultInput)
			std::cout << "Default input device.\n";
		else
			std::cout << "NOT default input device.\n";
		if (rt_info.nativeFormats & RTAUDIO_SINT8)
			std::cout << "  8-bit int\n";
		if (rt_info.nativeFormats & RTAUDIO_SINT16)
			std::cout << "  16-bit int\n";
		if (rt_info.nativeFormats & RTAUDIO_SINT24)
			std::cout << "  24-bit int\n";
		if (rt_info.nativeFormats & RTAUDIO_SINT32)
			std::cout << "  32-bit int\n";
		if (rt_info.nativeFormats & RTAUDIO_FLOAT32)
			std::cout << "  32-bit float\n";
		if (rt_info.nativeFormats & RTAUDIO_FLOAT64)
			std::cout << "  64-bit float\n";

		if (rt_info.sampleRates.size() < 1) {
			std::cout << "No supported sample rates found!";
		} else {
			std::cout << "Supported sample rates = ";
			for (unsigned int j = 0; j < rt_info.sampleRates.size(); j++)
				std::cout << rt_info.sampleRates[j] << " ";
		}
		std::cout << std::endl;
		if (rt_info.preferredSampleRate == 0)
			std::cout << "No preferred sample rate found!" << std::endl;
		else
			std::cout << "Preferred sample rate = " << rt_info.preferredSampleRate << std::endl;
	}
	
    // setup output
	std::cout << "SET Device Name = " << rt_device << "\n";
	rt_params.deviceId = rt_device; //rt_dac.getDefaultOutputDevice();
	rt_params.nChannels = rt_channels;
	rt_params.firstChannel = 0;

	rt_options.flags = RTAUDIO_SCHEDULE_REALTIME;
	rt_options.numberOfBuffers = DSTUDIO_NUM_BUFFERS;
	rt_options.priority = 1;
	
    // data storage
	data = (double *)calloc(rt_channels * rt_buffer_frames, sizeof(double));

    // open stream
    if (rt_dac.openStream(&rt_params, // output
                       NULL, // input
                       FORMAT, // sample data format
                       sample_rate,
                       &rt_buffer_frames, // buffer size in frames
                       &audioCallback,
                       (void *)data,
                       &rt_options)) // flags and number of buffers
    {
        goto cleanup;
    }
  
  	std::cout << "Stream latency = " << rt_dac.getStreamLatency() << "\n"
			  << std::endl;

    // start stream
	if (rt_dac.startStream())
    {
		goto cleanup;
    }

    std::cout << "\nPlaying - quit with Ctrl-C.\n";

    // run until interrupt with CTRL+C
    done = false;
    (void) signal(SIGINT, finish);

    while (!done && rt_dac.isStreamRunning())
    {
		rt_app.ProcessControl();
    }

    // stop stream
    if (rt_dac.isStreamRunning())
    {
        rt_dac.stopStream();
    }

cleanup:
    if (rt_dac.isStreamOpen())
    {
        rt_dac.closeStream();
    }
    free(data);

	return 0;
}
