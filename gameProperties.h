//
// Created by alane on 02.01.2018.
//

#ifndef DARKSNAKESTEST_GAMEPROPERTIES_H
#define DARKSNAKESTEST_GAMEPROPERTIES_H

#define BOARD_SIZE 40

#include "snakeTypes.h"

extern struct Snake* gPlayerSnakes;
extern struct Snake* gEnemySnakes;
extern int gCurrRewardPos[2];
extern int gTurnTimeMs;
extern int gEnemyCount;
extern int gPlayerCount;

#endif //DARKSNAKESTEST_GAMEPROPERTIES_H
