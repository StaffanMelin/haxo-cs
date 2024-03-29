#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsampler.h"
#include "../rtDStudio/src/dsynthvar.h"
#include "../rtDStudio/src/dfx.h"

#include "../rtDaisySP/src/daisysp.h"

class rtApp
{

private:
    DSampler dsampler;
    DSynthVar dsynthvar;

    DFXFilter dfxfilter;
    DFXPanner dfxpanner;
    DFXSlicer dfxslicer;

    DMixer dmixer;

    // test
    uint8_t testcount = 0;
    uint8_t testnote1 = 0;
    uint8_t testnote2 = 0;
    daisysp::Metro clock;

public:
    void Setup();
    void Process(float *, float *);
};
