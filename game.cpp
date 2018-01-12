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
    gSnakes = getDynamicSizedSnakeArray(gPlayerCount + gEnemyCount);

    setupDraw();

    setRandomPositionForSnakes(gSnakes, gPlayerCount + gEnemyCount);
}

void putReward() {
    do {
        gCurrRewardPos[0] = getRandomPos();
        gCurrRewardPos[1] = getRandomPos();
    } while(isCollidingPoint(
            gCurrRewardPos[0],
            gCurrRewardPos[1],
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
            Snake *playerSnake = &gSnakes[getPlayerIndexByInput(input)];
            int isColliding = isCollidingDirections((*playerSnake).currDirection, newDirection);
            if(!isColliding) (*playerSnake).currDirection = newDirection;
        }
    }
    if(timeMs() - lastTurnTime >= gTurnTimeMs) {
        if (startingUp) {
            initialSetup();
            putReward();
            initialDraw(gSnakes);
            startingUp = false;
        } else {
            int onlyHadInactivePlayers = true;
            int hadPlayer = false;
            setEnemyDirections();
            for(int a = 0; a < gPlayerCount + gEnemyCount; a++) {
                int snakeColor = 0;
                if(gSnakes[a].isPlayer && !hadPlayer) {
                    snakeColor = RED;
                    hadPlayer = true;
                }
                else if(gSnakes[a].isPlayer && hadPlayer) snakeColor = GREEN;
                else snakeColor = WHITE;
                if(gSnakes[a].active) {
                    SnakeMoveResult moveResult = moveSnake(&gSnakes[a], snakeColor, gCurrRewardPos);
                    if(moveResult == GOT_REWARD) putReward();
                    if(moveResult == HIT_WALL) gSnakes[a].active = false;
                    if(gSnakes[a].isPlayer) onlyHadInactivePlayers = false;
                }
            }
            if(onlyHadInactivePlayers && gPlayerCount > 0) {
                startingUp = true;
                finishGame();
            }
        }
        lastTurnTime = timeMs();
    }
}