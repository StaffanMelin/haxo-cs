#pragma once

#include "../rtaudio/RtAudio.h"

#define DEBUG

// DaisySP works with 32 bit floats
typedef float MY_TYPE;
#define FORMAT RTAUDIO_FLOAT32

// Platform-dependent sleep routines.
#if defined(WIN32)
#include <windows.h>
#define SLEEP(milliseconds) Sleep((DWORD)milliseconds)
#else // Unix variants
#include <unistd.h>
#define SLEEP(milliseconds) usleep((unsigned long)(milliseconds * 1000.0))
#endif
