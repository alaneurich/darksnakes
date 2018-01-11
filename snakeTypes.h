//
// Created by alane on 02.01.2018.
//

#ifndef DARKSNAKESTEST_SNAKETYPES_H
#define DARKSNAKESTEST_SNAKETYPES_H

#include "gameProperties.h"

enum MenuInput {
    ARROW_UP,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT,
    ENTER,
    FALSE_INPUT
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

struct Snake {
    int positions[BOARD_SIZE * BOARD_SIZE][2];
    int currSize = 2;
    Direction currDirection;
    int active = true;
};

#endif //DARKSNAKESTEST_SNAKETYPES_H
