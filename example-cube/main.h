#pragma once

#include "../rtaudio/RtAudio.h"

#define DEBUG

// rtaudio
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

// application - DWindow
#define DCTRLS 10
#define DCTRL_D0_PITCH 0
#define DCTRL_D0_VOL 6
#define DCTRL_D0_PAN 7
#define DCTRL_D0_CUTOFF 8
#define DCTRL_D1_PITCH 1
#define DCTRL_D2_PITCH 2
#define DCTRL_D3_PITCH 3
#define DCTRL_D4_PITCH 4
#define DCTRL_D5_PITCH 5

#define DCTRL_MATRIX0 9
#define MATRIX0_LEN 16 // 16 notes in sequence
#define MATRIX0_PITCH 13 // one octave plus one note