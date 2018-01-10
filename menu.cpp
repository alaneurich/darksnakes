//
// Created by alane on 02.01.2018.
//

#include "gameStates.h"
#include "gameProperties.h"
#include "menu.h"

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.

    setGameVars(2, 0, 100);
    startGame();
}

void startGame() {
    isMenuShowing = false;
    isGameStarted = true;
}

void setGameVars(int newPlayerCount, int newEnemyCount, int newTurnTimeMs) {
    gPlayerCount = newPlayerCount;
    gEnemyCount = newEnemyCount;
    gTurnTimeMs = newTurnTimeMs;
}