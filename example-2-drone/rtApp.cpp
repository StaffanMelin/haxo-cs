#include "rtApp.h"

#include "../rtDStudio/src/dstudio.h"
#include "../rtDStudio/src/dsynthsub.h"



void rtApp::Setup()
{

    // synths subtractive
    DSynthSub::Config dsynth_config;

    // synths
    for (uint8_t d = 0; d < DRONES; d++)
    {
        dsynth_config.sample_rate = DSTUDIO_SAMPLE_RATE;
        dsynth_config.voices = 1;
        dsynth_config.waveform0 = DSynthSub::WAVE_SAW;
        dsynth_config.waveform1 = DSynthSub::WAVE_TRI;
        tune[d] = ofRandom(5.0f);
        dsynth_config.tune = tune[d];
        detune[d] = ofRandom(10.0f);
        dsynth_config.detune = detune[d];
        dsynth_config.transpose = 0;
        dsynth_config.osc0_level = 0.5f;
        dsynth_config.osc1_level = 0.5f;
        dsynth_config.noise_level = 0.0f;
        dsynth_config.filter_type = DSynthSub::LOW;
        cutoff[d] = 400.0f + ofRandom(400.0f);
        dsynth_config.filter_cutoff = cutoff[d];
        dsynth_config.filter_res = 0.1f;
        dsynth_config.eg_p_level = 0.0f;
        dsynth_config.eg_p_attack = 0.0f;
        dsynth_config.eg_p_decay = 0.0f;
        dsynth_config.eg_p_sustain = 0.0f;
        dsynth_config.eg_p_release = 0.0f;
        dsynth_config.eg_f_level = 1.0f;
        dsynth_config.eg_f_attack = 0.0f;
        dsynth_config.eg_f_decay = 0.0f;
        dsynth_config.eg_f_sustain = 1.0f;
        dsynth_config.eg_f_release = 0.2f;
        dsynth_config.eg_a_attack = 0.3f;
        dsynth_config.eg_a_decay = 0.01f;
        dsynth_config.eg_a_sustain = 1.0f;
        dsynth_config.eg_a_release = 0.4f;
        dsynth_config.lfo_waveform = DSynthSub::WAVE_TRI;
        dsynth_config.lfo_freq = 0;//ofRandom(0.5f);
        dsynth_config.lfo_amp = 0;//ofRandom(1.0f);
        dsynth_config.lfo_p_level = 0.0f;
        dsynth_config.lfo_f_level = 0.0f;
        dsynth_config.lfo_a_level = 0.0f;
        dsynth_config.portamento = 3.0f;
        dsynth_config.delay_delay = ofRandom(1.0f);
        dsynth_config.delay_feedback = ofRandom(1.0f);
        dsynth_config.overdrive_gain = 0.0f;
        dsynth_config.overdrive_drive = 0.0f; //ofRandom(0.2f);
        ddrone[d].Init(dsynth_config);
    }

    // mixer
    DSound *dmix_synth[MIXER_CHANNELS_MAX];
    float dmix_pan[MIXER_CHANNELS_MAX];
    float dmix_level[MIXER_CHANNELS_MAX];
    float dmix_chorus_level[MIXER_CHANNELS_MAX];
    float dmix_reverb_level[MIXER_CHANNELS_MAX];
    bool dmix_mono[MIXER_CHANNELS_MAX];
    uint8_t dmix_group[MIXER_CHANNELS_MAX];
    DMixer::Config dmix_config;

    for (uint8_t d = 0; d < DRONES; d++)
    {
        dmix_synth[d] = &ddrone[d];
        dmix_pan[d] = ofRandom(1.0f);
        dmix_level[d] = 0.95f / (float)DRONES;
        dmix_chorus_level[d] = ofRandom(0.8f);
        dmix_reverb_level[d] = 0.5f + ofRandom(0.5f);
        dmix_mono[d] = true;
        dmix_group[d] = d;
    }
    dmix_config.sample_rate = DSTUDIO_SAMPLE_RATE;
    dmix_config.channels = DRONES;
    dmix_config.amp = 1.2f;
    dmix_config.synth = dmix_synth;
    dmix_config.pan = dmix_pan;
    dmix_config.level = dmix_level;
    dmix_config.chorus_level = dmix_chorus_level;
    dmix_config.reverb_level = dmix_reverb_level;
    dmix_config.mono = dmix_mono;
    dmix_config.group = dmix_group;
    dmix_config.chorus_return = 0.5;
    dmix_config.reverb_return = 0.8f;
    dmix_config.mix_dry = 0.2;
    dmixer.Init(dmix_config);

    // demo start
    dmixer.SetReverb(0.4f, 6000.0f);
    for (uint8_t d = 0; d < DRONES; d++)
    {
        ddrone[d].NoteOn(18 + 6 * (int)(ofRandom(10.0f)));
    }

    clock.Init(10, DSTUDIO_SAMPLE_RATE);
}



void rtApp::Process(float *sigL, float *sigR)
{
    if (clock.Process())
    {
		for (uint8_t d = 0; d < DRONES; d++)
		{
			// make tuning of synths slowly drift
			if (ofRandom(1.0f) < 0.02)
			{
				tune[d] = ofRandom(15.0f); // 5.0f
				ddrone[d].SetTuning(tune[d], detune[d]);
			}
			// make cutoff of synths drift
			if (ofRandom(1.0f) < 0.01)
			{
				cutoff[d] = 100.0f + ofRandom(2500.0f); // 500.0f
				ddrone[d].SetFilter(DSynthSub::LOW, cutoff[d], 0.1f);
			}
			// pitch drift w portamento
			if (ofRandom(1.0f) < 0.002)
			{
				ddrone[d].NoteOn(18 + 10 * (int)(ofRandom(10.0f)));
			}
		}
	}
	
    dmixer.Process(sigL, sigR);
}

