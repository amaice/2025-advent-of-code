#include "NewSafe.h"
#include <cmath>
#include <iostream>

void NewSafe::turn(const char direction, const int distance) {
    const int direction_scalar = direction == 'L' ? -1 : 1;
    pos += direction_scalar * distance;

    // int division automatically floors (truncates)
    if(pos < 0) {
        pos -= 100;
    }
    times_on_zero += std::abs(pos / 100);

    // please forgive my laziness
    pos = (10000000 + pos) % 100;
}

int NewSafe::password() const {
    return times_on_zero;
}
