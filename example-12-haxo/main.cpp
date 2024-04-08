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
static void finish(int /*ignore*/)
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

	for (size_t i = 0; i < frame_count; i++)
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
	unsigned int rt_offset = 0; // channel count offset
	unsigned int rt_buffer_frames = DSTUDIO_BUFFER_SIZE;
	unsigned int rt_frames = 0;

	// Rtaudio init
	RtAudio rt_dac(RtAudio::LINUX_ALSA, &errorCallback);
	/*
	enum Api {
		UNSPECIFIED,
		LINUX_ALSA,
		LINUX_PULSE
		LINUX_OSS,
		UNIX_JACK,
		MACOSX_CORE,
		WINDOWS_WASAPI,
		WINDOWS_ASIO,
		WINDOWS_DS,
		RTAUDIO_DUMMY,
		NUM_APIS
	};
	*/

	// output all messages
	rt_dac.showWarnings(true);

	// setup device
	if (rt_dac.getDeviceCount() < 1)
	{
		std::cout << "\nNo audio devices found!\n";
		exit(1);
	}

	// list device information

	RtAudio::DeviceInfo rt_info;
	std::cout << "\nAPI: " << RtAudio::getApiDisplayName(rt_dac.getCurrentApi()) << std::endl;
	unsigned int device_count = rt_dac.getDeviceCount();
	std::cout << "\nFound " << device_count << " device(s).\n";

//	for (unsigned int i = 0; i < device_count; i++)
//	for (unsigned int i = 0; i < 1; i++)
	unsigned int i = 0;
	{
		rt_info = rt_dac.getDeviceInfo(i);

		std::cout << "\nDevice Name = " << rt_info.name << "\n";
		std::cout << "Device ID = " << i << "\n";
		if (rt_info.probed == false)
			std::cout << "Probe Status = UNsuccessful\n";
		else {
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
		}
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

	// select device
	// Device Name = hw:MAX98357A,0
	// Device ID = 1

	rt_device = 0;

	std::cout << "setup A" << std::endl;

	// setup output
	RtAudio::StreamParameters rt_params;
	if (rt_device == 0)
	{
//		rt_params.deviceId = rt_dac.getDefaultOutputDevice();
	}
	else
	{
		rt_params.deviceId = rt_device;
	}
	rt_params.nChannels = rt_channels;
	rt_params.firstChannel = rt_offset;

	RtAudio::StreamOptions rt_options;
	rt_options.flags = RTAUDIO_SCHEDULE_REALTIME;
	rt_options.numberOfBuffers = DSTUDIO_NUM_BUFFERS;
	rt_options.priority = 1;

	// data storage
	double *data = (double *)calloc(rt_channels, sizeof(double));

	std::cout << "setup B open" << std::endl;

	// open stream
	if (rt_dac.openStream(&rt_params, // output
						  NULL,		  // input
						  FORMAT,	  // sample data format
						  sample_rate,
						  &rt_buffer_frames, // buffer size in frames
						  &audioCallback,
						  (void *)data,
						  &rt_options)) // flags and number of buffers
	{
		goto cleanup;
	}

	if (rt_dac.isStreamOpen() == false)
	{
		goto cleanup;
	}

	std::cout << "setup D latency" << std::endl;

	std::cout << "Stream latency = " << rt_dac.getStreamLatency() << "\n"
			  << std::endl;

	std::cout << "setup E start stream" << std::endl;

	// start stream
	if (rt_dac.startStream())
	{
		goto cleanup;
	}

	std::cout << "\nPlaying - quit with Ctrl-C.\n";

	// run until interrupt with CTRL+C
	done = false;
	(void)signal(SIGINT, finish);

	std::cout << "setup F loop" << std::endl;

	while (!done && rt_dac.isStreamRunning())
	{
		rt_app.ProcessControl();
		SLEEP(100);
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
