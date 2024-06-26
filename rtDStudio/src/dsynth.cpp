#include "dsynth.h"

#include <iostream>
#include <stdio.h>


void DSynth::Init(const Config& config)
{
	sample_rate_ = config.sample_rate;
	voices_ = config.voices;

    SetType(TUNED);
}



float DSynth::Process()
{
    return (0.0f);

}



void DSynth::Process(float *out_l, float *out_r)
{
//    *out_l = Process();
//    *out_r = *out_l;
}



void DSynth::MidiIn(uint8_t midi_status, uint8_t midi_data0, uint8_t midi_data1 = 0)
{
}



void DSynth::NoteOn(uint8_t midi_note, uint8_t midi_velocity)
{
}



void DSynth::NoteOff(uint8_t midi_note)
{
}	



void DSynth::ChangeParam(Param param, float value)
{
}	



void DSynth::SetLevel(float value)
{
}	



void DSynth::Silence()
{
}

