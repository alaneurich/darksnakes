//
// Created by alane on 04.01.2018.
//

#include <cstdlib>
#include "map.h"
#include "gameProperties.h"

int getRandomPos() {
    return rand() % BOARD_SIZE;
}

void setRandomPositionForSnake(Snake *snake, int isPlayer, int index) {
    (*snake).currDirection = RIGHT;
    int randPos = -1;
    while (randPos == -1) {
        randPos = getRandomPos();
        if (randPos + 1 == BOARD_SIZE ||
            isCollidingPoint(randPos, randPos, isPlayer, index) ||
            isCollidingPoint(randPos + 1, randPos, isPlayer, index)) {
            randPos = -1;
        }
    }
    (*snake).positions[0][0] = randPos;
    (*snake).positions[0][1] = randPos;
    (*snake).positions[1][0] = randPos + 1;
    (*snake).positions[1][1] = randPos;
}

void setRandomPositionForSnakes(struct Snake *snakes, int count, int isPlayer) {
    for (int a = 0; a < count; a++) {
        setRandomPositionForSnake(&snakes[a], isPlayer, a);
    }
}

int isCollidingPoint(int x, int y, int isPlayer, int excludeIndex) {
    struct Snake *combSnakes[gPlayerCount + gEnemyCount];
    for(int a = 0; a < gPlayerCount; a++) {
        combSnakes[a] = &gPlayerSnakes[a];
    }
    int enemySnakeIndex = 0;
    for (int b = 0 + gPlayerCount; b < gEnemyCount + gPlayerCount; b++) {
        combSnakes[b] = &gEnemySnakes[enemySnakeIndex];
        enemySnakeIndex++;
    }
    int index = 0;
    if(!isPlayer) excludeIndex += gPlayerCount;
    for (int c = 0; c < gPlayerCount + gEnemyCount; c++) {
        Snake *combSnake = combSnakes[c];
        if (excludeIndex == index) {
            index++;
            continue;
        }
        for (int d = 0; d < (*combSnake).currSize; d++) {
            if (((*combSnake).positions[d][0] == x ||
                 (*combSnake).positions[d][0] == x + 1 ||
                 (*combSnake).positions[d][0] == x - 1) &&
                ((*combSnake).positions[d][1] == y ||
                 (*combSnake).positions[d][1] == y + 1 ||
                 (*combSnake).positions[d][1] == y - 1)) {
                return true;
            }
        }
        index++;
    }
    return false;
}