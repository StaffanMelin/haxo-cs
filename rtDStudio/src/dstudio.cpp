#include "dstudio.h"
#include <stdlib.h>     /* srand, rand */

#include <chrono>
uint64_t ofGetElapsedTimeMicros(){
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

float ofRandom(float max) {
    return (max * rand() / float(RAND_MAX)) * (1.0f - std::numeric_limits<float>::epsilon());
}
