//
// Created by amaic on 12/1/2025.
//

#include "Safe.h"

#include <cmath>
#include <iostream>
#include <ostream>

void Safe::turn(char direction, int distance) {
    const bool direction_is_left = direction == 'L';

    // im so sorry for my laziness
    pos += 1000000;

    if (direction_is_left) {
        pos -= distance;
    } else {
        pos += distance;
    }

    pos %= 100;

    if (pos == 0) {
        times_on_zero += 1;
    }
}


int Safe::password() {
    return times_on_zero;
}