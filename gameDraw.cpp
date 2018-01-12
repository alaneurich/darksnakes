//
// Created by alane on 02.01.2018.
//


#include "gameDraw.h"
#include "stdafx.h"
#include "snakeTypes.h"
#include "helpers.h"

void setupDraw() {
    loeschen();
    groesse(BOARD_SIZE, BOARD_SIZE);
    formen(const_cast<char *>("s"));
    farben(BLACK);
}

void initialSnakeDraw(struct Snake *snakes, int count) {
    for (int a = 0; a < count; a++) {
        Snake *snake = &snakes[a];
        for (int b = 0; b < (*snake).currSize; b++) {
            if((*snake).isPlayer) {
                int color = a == 0 ? RED : GREEN;
                drawSnakePart((*snake).positions[b][0], (*snake).positions[b][1], color);
            } else {
                drawSnakePart((*snake).positions[b][0], (*snake).positions[b][1], WHITE);
            }
        }
    }
}

void initialDraw(struct Snake *playerSnakes) {
    initialSnakeDraw(playerSnakes, gPlayerCount + gEnemyCount);
}

void drawSnakePart(int x, int y, int color) {
    farbe2(x, y, color);
}

void drawReward(int x, int y) {
    farbe2(x, y, GREEN);
}

void resetField(int x, int y) {
    farbe2(x, y, BLACK);
}

int isCollidingWithOtherSnake(struct Snake *tmpSnake, int isPlayer, int snakeIndex) {
    int xPos = (*tmpSnake).positions[(*tmpSnake).currSize - 1][0];
    int yPos = (*tmpSnake).positions[(*tmpSnake).currSize - 1][1];
    for(int a = 0; a < gPlayerCount; a++) {

    }
}

SnakeMoveResult moveSnake(struct Snake *tmpSnake, int color, const int currRewardPos[]) {
    resetField((*tmpSnake).positions[0][0], (*tmpSnake).positions[0][1]);
    int x = (*tmpSnake).positions[(*tmpSnake).currSize - 1][0];
    int y = (*tmpSnake).positions[(*tmpSnake).currSize - 1][1];
    if ((*tmpSnake).currDirection == RIGHT) x++;
    if ((*tmpSnake).currDirection == LEFT) x--;
    if ((*tmpSnake).currDirection == UP) y++;
    if ((*tmpSnake).currDirection == DOWN) y--;

    int gotReward = false;
    if (x == currRewardPos[0] && y == currRewardPos[1]) {
        gotReward = true;
        (*tmpSnake).currSize++;
        resetField(currRewardPos[0], currRewardPos[1]);
    }
    if (!gotReward) deleteFirstObject(tmpSnake);
    (*tmpSnake).positions[(*tmpSnake).currSize - 1][0] = x;
    (*tmpSnake).positions[(*tmpSnake).currSize - 1][1] = y;
    drawSnakePart(x, y, color);
    if (x == -1 || x == BOARD_SIZE || y == -1 || y == BOARD_SIZE) return HIT_WALL;
    if(gotReward) return GOT_REWARD;
    return NOTHING;
}