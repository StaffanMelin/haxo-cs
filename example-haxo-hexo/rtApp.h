#pragma once

#include "../rtDStudio/src/dmixer.h"
#include "../rtDStudio/src/dsynthsub.h"
#include "../rtDStudio/src/dfx.h"
#include "../rtDStudio/src/dhaxo.h"

class rtApp
{

private:
    DSynthSub dsynthmelody;

    DMixer dmixer;
    DHaxo dhaxo;

public:
    void Setup();

    void Process(float *, float *);
    void ProcessControl();
};
