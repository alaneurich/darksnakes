//
// Created by alane on 02.01.2018.
//

#include <cstring>
#include "gameStates.h"
#include "gameProperties.h"
#include "menu.h"
#include "input.h"
#include "stdafx.h"

char *menuItems[] = {"Spiel starten", "Blaa", "Bliii", "Blubb"};
int currMenuItem = 0;
int menuSize = 4;

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.
    if(strlen(input) > 0) {
        MenuInput inputDirection = convertInputToUpAndDown(input);
        if(inputDirection == FALSE_INPUT) {

        }
        else if(inputDirection == ARROW_UP) {

            if(currMenuItem != 0)  currMenuItem--;
        }
        else if(inputDirection == ARROW_DOWN) {

            currMenuItem++;
        }
        else if(inputDirection == ENTER) {

        }
    }
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