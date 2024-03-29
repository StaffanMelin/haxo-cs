#pragma once

#include "../rtDStudio/src/dmixer.h"

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

#include "../rtDStudio/src/dseqmidi.h"

class rtApp
{

private:
    DSynthSub dsynthbass1, dsynthbass2;
    DSynthVar dsynthpad;
    DSynthFm dsyntharp;
    DSynthSub dsynthlead;
    DSynthSub dsynthpiano;
    DSampler dsampler_verse, dsampler_chorus;

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

    DSeqMidi dseqmidi;


public:
    void Setup();
    void Process(float *, float *);
};
