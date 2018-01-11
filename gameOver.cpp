//
// Created by alane on 03.01.2018.
//

#include "gameOver.h"
#include "gameStates.h"
#include "stdafx.h"

void gameOver (){
    int x,y;

    groesse(60,60);
    farben (BLACK);

    text2(30, 30, "YOU DIED");
}

void drawGameOverScreen(char *input) {
    //TODO Actually show Game Over Screen.

    startNextGameWithNewOptions();
}

void stopGame() {
    isMenuShowing = false;
    isGameStarted = false;
    isGameOverScreenShowing = false;
}

void startNextGame() {
    stopGame();
    isGameStarted = true;
}

void startNextGameWithNewOptions() {
    stopGame();
    isMenuShowing = true;
}
