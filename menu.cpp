//
// Created by alane on 02.01.2018.
//

#include <cstring>
#include "gameStates.h"
#include "gameProperties.h"
#include "menu.h"
#include "input.h"
#include "stdafx.h"

int isStarting = true;
char *menuItems[] = {"Spiel starten", "Blaa", "Bliii", "Blubb"};
int currMenuItem = 0;
int menuSize = 4;

void handleInput(char *input) {
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

void makeScreenColorful () {
    if(isStarting) {
        int x,y;

        loeschen();

        groesse (60, 60);
        formen ("s");
        farben (BLACK);

        fontSize(120);
        text2(30, 30, "Dark Snakes");
        textFarbe2(30, 30, WHITE);

        fontSize(30);
        text2(30, 22, "Start Game");
        textFarbe2(30, 22, WHITE);

        fontSize(30);
        text2(30, 15, "Playercount: 1");
        textFarbe2(30, 15, WHITE);


        text2(30, 12, "Enemycount : 4");
        textFarbe2(30, 12, WHITE);

        text2(30, 9, "Difficulty: 100");        //easy, medium, hard
        textFarbe2(30, 9, WHITE);

        text2(30, 4, "Quit Game");
        textFarbe2(30, 4, WHITE);

        isStarting = false;
    }
}

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.

    makeScreenColorful();
    handleInput(input);
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