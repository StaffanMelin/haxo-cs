#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthvar.h"
#include "../rtDStudio/src/dfx.h"
#include "../rtDStudio/src/dhaxo.h"

class rtApp
{

private:
    DSynthVar dsynthmelody;

    DFXFlanger dfxflanger;
    DFXFilter dfxfilter;

    DMixer dmixer;
    DHaxo dhaxo;

public:
    void Setup();

    void Process(float *, float *);
    void ProcessControl();
};
