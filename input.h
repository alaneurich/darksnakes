//
// Created by alane on 02.01.2018.
//

#ifndef DARKSNAKESTEST_INPUT_H
#define DARKSNAKESTEST_INPUT_H

#include "snakeTypes.h"

Direction convertInputToNewDirection(const char *input);
int getPlayerIndexByInput(const char *input);
int isCollidingDirections(Direction oldDirection, Direction newDirection);

#endif //DARKSNAKESTEST_INPUT_H
