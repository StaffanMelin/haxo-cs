#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsplit.h"

#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dsynthfm.h"
#include "../rtDStudio/src/dsynthvar.h"
#include "../rtDStudio/src/dsampler.h"

#include "../rtDStudio/src/dfx.h"

#include "../rtDStudio/src/dbass.h"
#include "../rtDStudio/src/dhihat.h"
#include "../rtDStudio/src/dsnare.h"
#include "../rtDStudio/src/dclap.h"
#include "../rtDStudio/src/dcymbal.h"
#include "../rtDStudio/src/ddrum.h"

#include "../rtDStudio/src/dseqperm.h"

class rtApp
{

private:
    DSynthSub dsynthbass1;
    DSynthSub dsyntharp1;
    DSynthFm dsyntharp2;
    DSynthSub dsyntharp3;
    DSynthSub dsynthlead;
    DSynthVar dsynthpad;

    DSampler dsampler1, dsampler2, dsampler3, dsampler4;
    DSplit dsplit;

    DFXFlanger dfxflanger;
    DFXDelay dfxdelay;
    DFXDecimator dfxdecimator;
    DFXFilter dfxfilter;

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

    DSeqPerm dseqperm;


public:
    void Setup();

    void Process(float *, float *);
};
