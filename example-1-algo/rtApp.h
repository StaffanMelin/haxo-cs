#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dsynthfm.h"
#include "../rtDStudio/src/dbass.h"
#include "../rtDStudio/src/dhihat.h"
#include "../rtDStudio/src/dsnare.h"
#include "../rtDStudio/src/dclap.h"
#include "../rtDStudio/src/dcymbal.h"
#include "../rtDStudio/src/ddrum.h"

#include "../rtDaisySP/src/daisysp.h"

class rtApp {

private:
    DSynthSub dsynth0; // chord
    DSynthSub dsynth1; // chord
    DSynthSub dsynth2; // solo portamento
    DSynthSub dsynthb; // bass
    DSynthFm dsynthfm;

    DBass dbass;
    DSnare dsnare;
    DHihat dhihatc;
    DHihat dhihato;
    DClap dclap;
    DCymbal dcrash;
    DCymbal dride;
    DDrum dtomhi;
    DDrum dtomlo;

    DMixer dmixer;
    DMixer ddmixer;

    // test
    uint8_t testcount = 0;
    uint8_t testnote1 = 0;
    uint8_t testnote2 = 0;
    uint8_t testnote3 = 0;
    daisysp::Metro clock;

public:
    void Setup();
    void Process(float *, float *);

};
