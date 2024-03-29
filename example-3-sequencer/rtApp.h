#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dsynthfm.h"
#include "../rtDStudio/src/dbass.h"
#include "../rtDStudio/src/dsnare.h"
#include "../rtDStudio/src/dseqmidi.h"
#include "../rtDStudio/src/dfx.h"

class rtApp
{

private:
    DSynthSub dsynthbass;
    DSynthSub dsyntharp;
    DSynthFm dsynthsolo;
    DSynthSub dsynthlead;
    DBass dbass;
    DSnare dsnare;

    DFXFlanger dfxflanger;
    DFXDelay dfxdelay;
    DFXDecimator dfxdecimator;
    DFXFilter dfxfilter;

    DMixer dmixer;
    DSeqMidi dseqmidi;

public:
    void Setup();

    void Process(float *, float *);
};
