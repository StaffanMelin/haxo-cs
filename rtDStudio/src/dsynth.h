#pragma once

#include "dstudio.h"
#include "dsound.h"

// synth engines included in metasynth
#include "dsynthfm.h"
#include "dsynthsub.h"
#include "dsynthvar.h"
#include "dsampler.h"

#include "oscillator.h"
#include "adsr.h"
#include "delayline.h"
#include "overdrive.h"
#include "port.h"
#include "svf.h"
#include "whitenoise.h"

// polyphony
#define DSYNTH_VOICES_MAX 8
// delay
#define DSYNTH_DELAY_MAX_S 2.0f // delay max in seconds
#define DSYNTH_DELAY_MAX static_cast<size_t>(DSTUDIO_SAMPLE_RATE * DSYNTH_DELAY_MAX_S)

// using namespace daisysp;

class DSynth : public DSound
{

	public:

    DSynth() {}
    ~DSynth() {}

    struct Config
    {
    	float sample_rate;
    	uint8_t voices;
        // one obj instance for each engine
        // engine to start with
        // dsound *
    };

    enum Param
    {
        DSYNTH_PARAM_NONE = 0,
        DSYNTH_PARAM_TUNE,
        DSYNTH_PARAM_DETUNE,
        DSYNTH_PARAM_TRANSPOSE,
        DSYNTH_PARAM_FILTER_CUTOFF,
        DSYNTH_PARAM_FILTER_RES,
        DSYNTH_PARAM_AMP,
        DSYNTH_PARAM_LFO_AMP,
        DSYNTH_PARAM_LFO_FREQ,
        DSYNTH_PARAM_DELAY_FEEDBACK,
        DSYNTH_PARAM_DELAY_FREQ,
        DSYNTH_PARAM_OVERDRIVE,
        DSYNTH_PARAM_LAST
    };

	void Init(const Config&);
	float Process();
    void Process(float *, float *);
    void MidiIn(uint8_t, uint8_t, uint8_t);
    void NoteOn(uint8_t midi_note, uint8_t midi_velocity = MIDI_VELOCITY_MAX);
	void NoteOff(uint8_t midi_note);

    void ChangeParam(Param param, float value);
    void Silence();

    /*
    void SetWaveform(Waveform, Waveform);
    void SetTuning(float, float);
    void SetLevel(float, float, float);
    void SetFilter(FilterType, float, float);
    void SetEGLevel(Target, float);
    void SetEG(Target, float, float, float, float);
    void SetLFO(Waveform, float, float, float, float, float);
    void SetPortamento(float);
    */

private:

	float sample_rate_;
   	uint8_t voices_;
    
};
