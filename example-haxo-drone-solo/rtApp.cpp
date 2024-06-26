#include "rtApp.h"

#include "../rtDStudio/src/dstudio.h"
#include "../rtDStudio/src/dsynthsub.h"

#include "../rtDStudio/src/dfx.h"

#include "../rtDStudio/src/dsettings.h"

#include "../rtDStudio/src/dhaxo.h"

void rtApp::Setup()
{
  // synth melody
  DSynthSub::Config dsynthsub_config;
  DSettings::LoadSetting(DSettings::DSYNTHSUB, DSettings::NONE, "data/sub_melody.xml", &dsynthsub_config);
  dsynthmelody.Init(dsynthsub_config);
  // pad
  DSettings::LoadSetting(DSettings::DSYNTHSUB, DSettings::NONE, "data/sub_pad.xml", &dsynthsub_config);
  dsynthpad.Init(dsynthsub_config);

  // mixer
  DSound *dmix_synth[MIXER_CHANNELS_MAX];
  float dmix_pan[MIXER_CHANNELS_MAX];
  float dmix_level[MIXER_CHANNELS_MAX];
  float dmix_chorus_level[MIXER_CHANNELS_MAX];
  float dmix_reverb_level[MIXER_CHANNELS_MAX];
  bool dmix_mono[MIXER_CHANNELS_MAX];
  uint8_t dmix_group[MIXER_CHANNELS_MAX];
  DMixer::Config dmix_config;

  dmix_synth[0] = &dsynthmelody;
  dmix_synth[1] = &dsynthpad;
  dmix_level[0] = 0.6;
  dmix_level[1] = 0.3;
  dmix_pan[0] = 0.5f;
  dmix_pan[1] = 0.2f;
  dmix_chorus_level[0] = 0.2f;
  dmix_chorus_level[1] = 0.0f;
  dmix_reverb_level[0] = 0.5f;
  dmix_reverb_level[1] = 0.6f;
  dmix_mono[0] = true;
  dmix_mono[1] = true;
  dmix_group[0] = 0;
  dmix_group[1] = 1;
  dmix_config.sample_rate = DSTUDIO_SAMPLE_RATE;
  dmix_config.channels = 2;
  dmix_config.amp = 0.5f;
  dmix_config.synth = dmix_synth;
  dmix_config.pan = dmix_pan;
  dmix_config.level = dmix_level;
  dmix_config.chorus_level = dmix_chorus_level;
  dmix_config.reverb_level = dmix_reverb_level;
  dmix_config.mono = dmix_mono;
  dmix_config.group = dmix_group;
  dmix_config.chorus_return = 0.5;
  dmix_config.reverb_return = 0.5f;
  dmix_config.mix_dry = 0.3;
  dmixer.Init(dmix_config);

  // demo start
  dmixer.SetReverb(0.9f, 2000.0f);

  // Send dmixer obj to be able to send MIDI to mixer
  DHaxo::Config dhaxo_config;
  dhaxo_config.channel = 0; // which channel in mixer
  dhaxo_config.hexo_connected = true;
  dhaxo_config.synth = &dmixer;
  dhaxo.Init(dhaxo_config);

  // start drone
  dmixer.MidiIn(MIDI_MESSAGE_NOTEON + 1, 36, 100);
}



void rtApp::ProcessControl()
{
  dhaxo.Process();
}



void rtApp::Process(float *sigL, float *sigR)
{
  dmixer.Process(sigL, sigR);
}

