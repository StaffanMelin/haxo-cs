#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dsynthfm.h"
#include "../rtDStudio/src/dsynthvar.h"
#include "../rtDStudio/src/dfx.h"
#include "../rtDStudio/src/dgen.h"
#include "../rtDStudio/src/dhaxo.h"

class rtApp
{

private:
    // haxo
    DSynthSub dsynthhaxo;
    DHaxo dhaxo;

    // gen
    DSynthSub dsynthbass;
    DSynthSub dsynthhi;
    DSynthSub dsynthpad;
    DSynthVar dsynthmelody;
    DSynthSub dsyntharp;
    DSynthFm dsynthembellish;
    DSynthSub dsynthfill;

    DFXFlanger dfxflanger;
    DFXFilter dfxfilter;

    DMixer dmixer;

    DGenDrone dgen;

public:
    void Setup();

    void Process(float *, float *);
    void ProcessControl();
};
