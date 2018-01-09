//
// Created by alane on 04.01.2018.
//

#include "ai.h"
#include "helpers.h"
#include "map.h"

int canGo(Snake *snake, Direction direction, int index) {
    int xPos =
            (*snake).positions[(*snake).currSize - 1][0] +
            (direction == RIGHT ? 1 : 0) +
            (direction == LEFT ? -1 : 0);
    int yPos =
            (*snake).positions[(*snake).currSize - 1][1] +
            (direction == UP ? 1 : 0) +
            (direction == DOWN ? -1 : 0);
    return !isCollidingPoint(
            xPos,
            yPos,
            false,
            index
    );
}

Direction getBestDirection(struct Snake *snake, int index) {
    int canGoUp = canGo(snake, UP, index);
    int canGoDown = canGo(snake, DOWN, index);
    int canGoRight = canGo(snake, RIGHT, index);
    int canGoLeft = canGo(snake, LEFT, index);
    int needsUp =
            (*snake).positions[(*snake).currSize - 1][1] == gCurrRewardPos[1] ?
            -1 :
            (*snake).positions[(*snake).currSize - 1][1] <= gCurrRewardPos[1];
    int needsRight =
            (*snake).positions[(*snake).currSize - 1][0] == gCurrRewardPos[0] ?
            -1 :
            (*snake).positions[(*snake).currSize - 1][0] <= gCurrRewardPos[0];
    int foundDirection = 0;
    if((*snake).currDirection == UP) canGoDown = false;
    if((*snake).currDirection == DOWN) canGoUp = false;
    if((*snake).currDirection == RIGHT) canGoLeft = false;
    if((*snake).currDirection == LEFT) canGoRight = false;
    if (needsUp != -1) {
        if (needsUp && canGoUp) {
            return UP;
        } else if (!needsUp && canGoDown) {
            return DOWN;
        }
    } else {
        if (needsRight && canGoRight) {
            return RIGHT;
        } else if (!needsRight && canGoLeft) {
            return LEFT;
        }
    }
    if (canGoUp) return UP;
    if (canGoDown) return DOWN;
    if (canGoRight) return RIGHT;
    if (canGoLeft) return LEFT;
    return UP;
}

void setEnemyDirections() {
    for (int a = 0; a < gEnemyCount; a++) {
        gEnemySnakes[a].currDirection = getBestDirection(&gEnemySnakes[a], a);
    }
}