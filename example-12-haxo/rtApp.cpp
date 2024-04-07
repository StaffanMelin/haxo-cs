#include "rtApp.h"

#include "../rtDStudio/src/dstudio.h"
#include "../rtDStudio/src/dsynthvar.h"

#include "../rtDStudio/src/dfx.h"

#include "../rtDStudio/src/dsettings.h"

void rtApp::Setup()
{

  // synth melody (dsynthvar)
  DSynthVar::Config dsynthvar_config;
  DSettings::LoadSetting(DSettings::DSYNTHVAR, DSettings::NONE, "data/var_melody.xml", &dsynthvar_config);
  dsynthmelody.Init(dsynthvar_config);

  // filter on var shape osc to remove DC offset
  DFXFilter::Config dfxfilter_config;
  dfxfilter_config.sample_rate = DSTUDIO_SAMPLE_RATE;
  dfxfilter_config.level = 1.0f;
  dfxfilter_config.filter_type = DFXFilter::HIGH;
  dfxfilter_config.filter_cutoff = 200.0f;
  dfxfilter_config.filter_res = 0.0f;
  dfxfilter_config.child = &dsynthmelody;
  dfxfilter.Init(dfxfilter_config);

  // mixer
  DSound *dmix_synth[MIXER_CHANNELS_MAX];
  float dmix_pan[MIXER_CHANNELS_MAX];
  float dmix_level[MIXER_CHANNELS_MAX];
  float dmix_chorus_level[MIXER_CHANNELS_MAX];
  float dmix_reverb_level[MIXER_CHANNELS_MAX];
  bool dmix_mono[MIXER_CHANNELS_MAX];
  uint8_t dmix_group[MIXER_CHANNELS_MAX];
  DMixer::Config dmix_config;

  dmix_synth[0] = &dfxfilter; // dsynthmelody
  dmix_pan[0] = 0.5f;
  dmix_level[0] = 0.5;
  dmix_chorus_level[0] = 0.2f;
  dmix_reverb_level[0] = 0.5f;
  dmix_mono[0] = false;
  dmix_group[0] = 0;
  dmix_config.sample_rate = DSTUDIO_SAMPLE_RATE;
  dmix_config.channels = 1;
  dmix_config.amp = 1.0f;
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
  dhaxo.Init();

  //.Start();
}

void rtApp::Process(float *sigL, float *sigR)
{
  dhaxo.Process();
  dmixer.Process(sigL, sigR);
}
