#pragma once
#include <cstdlib>

namespace BaseTools {

    inline float generateRandomFloat() {
        return (static_cast<float>(rand()) / RAND_MAX) * 200.0f - 100.0f;
    }

    inline int generateRandomInt() {
        return rand() % 101;
    }

   

    
}


