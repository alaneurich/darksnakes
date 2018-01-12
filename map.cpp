//
// Created by alane on 04.01.2018.
//

#include <cstdlib>
#include "map.h"
#include "gameProperties.h"

int getRandomPos() {
    return rand() % BOARD_SIZE;
}

void setRandomPositionForSnake(Snake *snake, int index) {
    (*snake).currDirection = RIGHT;
    int randPos = -1;
    while (randPos == -1) {
        randPos = getRandomPos();
        if (randPos + 1 == BOARD_SIZE ||
            isCollidingPoint(randPos, randPos, index) ||
            isCollidingPoint(randPos + 1, randPos, index)) {
            randPos = -1;
        }
    }
    (*snake).positions[0][0] = randPos;
    (*snake).positions[0][1] = randPos;
    (*snake).positions[1][0] = randPos + 1;
    (*snake).positions[1][1] = randPos;
}

void setRandomPositionForSnakes(struct Snake *snakes, int count) {
    for (int a = 0; a < count; a++) {
        setRandomPositionForSnake(&snakes[a], a);
    }
}

int isCollidingPoint(int x, int y, int excludeIndex) {
    int index = 0;
    for (int a = 0; a < gPlayerCount + gEnemyCount; a++) {
        Snake *combSnake = &gSnakes[a];
        if (excludeIndex == index) {
            index++;
            continue;
        }
        for (int b = 0; b < (*combSnake).currSize; b++) {
            if (((*combSnake).positions[b][0] == x ||
                 (*combSnake).positions[b][0] == x + 1 ||
                 (*combSnake).positions[b][0] == x - 1) &&
                ((*combSnake).positions[b][1] == y ||
                 (*combSnake).positions[b][1] == y + 1 ||
                 (*combSnake).positions[b][1] == y - 1)) {
                return true;
            }
        }
        index++;
    }
    return false;
}