#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dsynthfm.h"

#include "../rtDaisySP/src/daisysp.h"

#define DRONES 5

class rtApp
{

private:
    DSynthSub ddrone[DRONES];

    DMixer dmixer;

    daisysp::Metro clock;

    float tune[DRONES];
    float detune[DRONES];
    float cutoff[DRONES];

public:
    void Setup();

    void Process(float *, float *);
};
