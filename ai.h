//
// Created by alane on 04.01.2018.
//

#ifndef DARKSNAKESTEST_AI_H
#define DARKSNAKESTEST_AI_H

#include "snakeTypes.h"

Direction getBestDirection(struct Snake* snake, int index);
void setEnemyDirections();

#endif //DARKSNAKESTEST_AI_H
