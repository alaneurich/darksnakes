//
// Created by alane on 04.01.2018.
//

#include <cstdlib>
#include <cstdio>
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
            isCollidingPoint(randPos, randPos, index, false) ||
            isCollidingPoint(randPos + 1, randPos, index, false)) {
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

int isCollidingPoint(int x, int y, int excludeIndex, int isPrecise) {
    for (int a = 0; a < gPlayerCount + gEnemyCount; a++) {
        if (excludeIndex == a) continue;
        Snake *snake = &gSnakes[a];
        for (int b = 0; b < (*snake).currSize; b++) {
            if(isPrecise &&
                    (*snake).positions[b][0] == x &&
                    (*snake).positions[b][1] == y) {
                return true;
            }
            if (((*snake).positions[b][0] == x ||
                 (*snake).positions[b][0] == x + 1 ||
                 (*snake).positions[b][0] == x - 1)
                &&
                ((*snake).positions[b][1] == y ||
                 (*snake).positions[b][1] == y + 1 ||
                 (*snake).positions[b][1] == y - 1)) {
                return true;
            }
        }
    }
    return false;
}

void checkSnakeCollisions() {
    for(int a = 0; a < gPlayerCount + gEnemyCount; a++) {
        for(int b = 0; b < gSnakes[a].currSize; b++) {
            if(isCollidingPoint(
                    gSnakes[a].positions[b][0],
                    gSnakes[a].positions[b][1],
                    a,
                    true
            )) {
                gSnakes[a].active = false;
            } else {

            }
        }
    }
}