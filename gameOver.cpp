//
// Created by alane on 03.01.2018.
//

#include "gameOver.h"
#include "gameStates.h"
#include "stdafx.h"

int isStarting = true;
int animCount = 0;

void timeUntilNew(){
    //Wait for 5 seconds then return to title screen
}

void animateYouDead (){
    if(animCount == 100) return;
    fontSize(animCount/3 + 100);
    text2(30, 30, "YOU DIED");
    animCount++;
}

void drawGameOverScreen(char *input) {
    //TODO Actually show Game Over Screen.
    int x;
    int y;

    if(isStarting) {

        loeschen();
        groesse (60, 60);

        formen ("s");
        farben (0x606060);

        for(x=0; x<60; x++){
            for(y=25; y<36; y++) {
                farbe2(x, y, BLACK);
            }
        }

        textFarbe2(30, 30, RED);

        isStarting = false;
    }

    animateYouDead();
    timeUntilNew();
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
