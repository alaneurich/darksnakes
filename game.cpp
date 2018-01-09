//
// Created by alane on 04.01.2018.
//

#include <cstdio>
#include <cstring>
#include "game.h"
#include "gameProperties.h"
#include "gameDraw.h"
#include "stdafx.h"
#include "map.h"
#include "helpers.h"
#include "ai.h"
#include "gameStates.h"
#include "input.h"

long long lastTurnTime = 0;
int startingUp = true;

void initialSetup() {
    gPlayerSnakes = getDynamicSizedSnakeArray(gPlayerCount);
    gEnemySnakes = getDynamicSizedSnakeArray(gEnemyCount);

    setupDraw();

    setRandomPositionForSnakes(gPlayerSnakes, gPlayerCount, true);
    setRandomPositionForSnakes(gEnemySnakes, gEnemyCount, false);
}

void putReward() {
    do {
        gCurrRewardPos[0] = getRandomPos();
        gCurrRewardPos[1] = getRandomPos();
    } while(isCollidingPoint(
            gCurrRewardPos[0],
            gCurrRewardPos[1],
            true,
            -1
    ));

    drawReward(gCurrRewardPos[0], gCurrRewardPos[1]);
}

void finishGame() {
    isGameStarted = false;
    isGameOverScreenShowing = true;
}

void drawGameScreen(char *input) {
    if (strlen(input) > 0) {
        Direction newDirection = convertInputToNewDirection(input);
        if(newDirection != NONE) {
            Snake *playerSnake = &gPlayerSnakes[getPlayerIndexByInput(input)];
            int isColliding = isCollidingDirections((*playerSnake).currDirection, newDirection);
            if(!isColliding) (*playerSnake).currDirection = newDirection;
        }
    }
    if(timeMs() - lastTurnTime >= gTurnTimeMs) {
        if (startingUp) {
            initialSetup();
            putReward();
            initialDraw(gPlayerSnakes, gEnemySnakes);
            startingUp = false;
        } else {
            int onlyHadInactivePlayers = true;
            for(int a = 0; a < gPlayerCount; a++) {
                if(gPlayerSnakes[a].active) {
                    SnakeMoveResult moveResult = moveSnake(&gPlayerSnakes[a], a == 0 ? RED : YELLOW, gCurrRewardPos);
                    if(moveResult == GOT_REWARD) putReward();
                    if(moveResult == HIT_WALL) gPlayerSnakes[a].active = false;
                    onlyHadInactivePlayers = false;
                }
            }
            if(onlyHadInactivePlayers && gPlayerCount > 0) {
                startingUp = true;
                finishGame();
            }
            setEnemyDirections();
            for (int b = 0; b < gEnemyCount; b++) {
                SnakeMoveResult enemyMoveResult = moveSnake(&gEnemySnakes[b], BEIGE, gCurrRewardPos);
                if(enemyMoveResult == GOT_REWARD) putReward();
                if(enemyMoveResult == HIT_WALL) gEnemySnakes[b].active = false;
            }
        }
        lastTurnTime = timeMs();
    }
}