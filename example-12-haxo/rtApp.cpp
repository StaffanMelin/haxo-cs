#include "rtApp.h"

#include "../rtDStudio/src/dstudio.h"
#include "../rtDStudio/src/dsynthsub.h"

#include "../rtDStudio/src/dfx.h"

#include "../rtDStudio/src/dsettings.h"

#include "../rtDStudio/src/dhaxo.h"

#include <thread>

void rtApp::Setup()
{
  std::cout << "enter setup\n";

  std::cout << "setup synths\n";

  // synth melody
  DSynthSub::Config dsynthsub_config;
  DSettings::LoadSetting(DSettings::DSYNTHSUB, DSettings::NONE, "data/sub_melody.xml", &dsynthsub_config);
  dsynthmelody.Init(dsynthsub_config);
  // pad
  DSettings::LoadSetting(DSettings::DSYNTHSUB, DSettings::NONE, "data/sub_pad.xml", &dsynthsub_config);
  dsynthpad.Init(dsynthsub_config);

  std::cout << "setup mixer\n";

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
  dmix_level[0] = 0.3;
  dmix_level[1] = 0.2;
  dmix_pan[0] = 0.5f;
  dmix_pan[1] = 0.2f;
  dmix_chorus_level[0] = 0.2f;
  dmix_chorus_level[1] = 0.0f;
  dmix_reverb_level[0] = 0.3f;
  dmix_reverb_level[1] = 0.6f;
  dmix_mono[0] = true;
  dmix_mono[1] = true;
  dmix_group[0] = 0;
  dmix_group[0] = 1;
  dmix_config.sample_rate = DSTUDIO_SAMPLE_RATE;
  dmix_config.channels = 2;
  dmix_config.amp = 0.1f;
  dmix_config.synth = dmix_synth;
  dmix_config.pan = dmix_pan;
  dmix_config.level = dmix_level;
  dmix_config.chorus_level = dmix_chorus_level;
  dmix_config.reverb_level = dmix_reverb_level;
  dmix_config.mono = dmix_mono;
  dmix_config.group = dmix_group;
  dmix_config.chorus_return = 0.5;
  dmix_config.reverb_return = 0.5f;
  dmix_config.mix_dry = 0.5;
  dmixer.Init(dmix_config);

  // demo start
  dmixer.SetReverb(0.9f, 2000.0f);

  // TODO end dmixer obj to be able to send MIDI to mixer
  DHaxo::Config dhaxo_config;
  dhaxo_config.sample_rate = DSTUDIO_SAMPLE_RATE;
  dhaxo_config.channels = 1;
  dhaxo_config.synth = &dmixer;
  dhaxo.Init(dhaxo_config);

  dmixer.MidiIn(MIDI_MESSAGE_NOTEON + 1, 36, 100);
  //.Start();
//  std::thread thaxo([dhaxoptr]() { 
    //dhaxoptr->Process();
//  });
  std::cout << "exit setup\n";
}



void rtApp::ProcessControl()
{
  dhaxo.Process();
}



void rtApp::Process(float *sigL, float *sigR)
{
  dmixer.Process(sigL, sigR);
}
