#pragma once

/*
Description of sequence data format.

Base constants and types defined in dseq.h.

array of (song steps)
    array of (channels)
        struct (sequence number, length)

    dmidisong_t dsong
    {
        {{0, DT1 * 8}, {5, DT1}, {5, DT1 * 8}, {3, DT1}, {5, DT1}, {6, DT1 * 2}},
        {{0, DT1 * 8}, {1, DT1}, {5, DT1 * 8}, {3, DT1}, {5, DT1}, {6, DT1 * 2}},
        {{0, DT1 * 8}, {1, DT1}, {2, DT1 * 8}, {3, DT1}, {4, DT1}, {6, DT1 * 2}},
        {{5, DT1 * 8}, {5, DT1}, {2, DT1 * 8}, {3, DT1}, {5, DT1}, {6, DT1 * 2}}
    };

array of (sequences)
    array of (notes)
        struct (position, message (eg note on), MIDI note, velocity)

    dmidiseq_t dseq
    {
        {
            {0, DEN, 31, DV7}, {0, DEN, 38, DV7}, {0, DEN, 43, DV7},
            {DT1*4, DEN, 38, DVOFF}, {DT1*4, DEN, 39, DV7}, {DT1*4, DEN, 36, DV7},
            {DT1*5, DEN, 39, DVOFF}, {DT1*5, DEN, 41, DV7},
            {DT1*6, DEN, 31, DVOFF}, {DT1*6, DEN, 43, DVOFF}, {DT1*6, DEN, 38, DVOFF}, {DT1*6, DEN, 39, DV7}, {DT1*6, DEN, 34, DV7},
            {DT1*7, DEN, 39, DVOFF}, {DT1*7, DEN, 34, DVOFF}, {DT1*7, DEN, 38, DV7}, {DT1*7, DEN, 33, DV7},
            {DT1*8-1, DEN, 38, DVOFF}, {DT1*8-1, DEN, 33, DVOFF}, {DT1*8-1, DEN, 41, DVOFF}
        }
        ,


*/

#include <stdint.h>
#include <vector>

#include "dstudio.h"
#include "dmixer.h"
#include "dseq.h"

typedef std::vector<std::vector<DMidiSongStep>> dmidisong_t;
typedef std::vector<std::vector<DMidiSeqStep>> dmidiseq_t;

class DSeqMidi
{
public:

    DSeqMidi() {}
    ~DSeqMidi() {}

    struct Config
    {
        uint8_t bpm; // BPM
        uint16_t rep; // how many times to repeat song
        bool silence; // silence all synths after each song step
        dmidisong_t dmidisong; // vector of vectors with song step data
        dmidiseq_t dmidiseq; // vector of vectors with sequences data
        uint8_t channels; // number of active channels
        DMixer *mixer; // address of mixer so sequencer can send MIDI data
    };

    void Init(const Config&);
    void Start();
    void Stop();
    void Process();
    void SetBPM(uint8_t);

private:

    uint8_t bpm_;
    uint16_t rep_;
    bool silence_;
    dmidisong_t dmidisong_;
    dmidiseq_t dmidiseq_;
    uint8_t channels_;
    DMixer *mixer_;

    uint64_t upt_; // microseconds per tick
    uint64_t now_us_;
    uint64_t prev_us_;
    bool running_;
    uint64_t ticks_[MIXER_CHANNELS_MAX];
    uint16_t note_[MIXER_CHANNELS_MAX];
    uint16_t song_step_;
    uint16_t rep_count_;
    std::vector<uint8_t> channel_max_len_; // channel with seq max len of sequence for each song step

    void CalcTempo();
};
