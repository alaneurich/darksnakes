//
// Created by alane on 03.01.2018.
//

#include "gameOver.h"
#include "gameStates.h"
#include "stdafx.h"

int isGameOverStarting = true;
int animCount = 0;
int showingTimer = 0;

int timeUntilNew(){
    //Wait for 5 seconds then return to title screen
    showingTimer++;
    return showingTimer * 16 >= 5000;
}

void animateYouDead (){
    if(animCount == 100) return;
    fontSize(animCount/3 + 100);
    text2(30, 30, "YOU DIED");
    animCount++;
}

void drawGameOverScreen(char *input) {
    int x;
    int y;

    if(isGameOverStarting) {

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

        isGameOverStarting = false;
    }

    animateYouDead();
    if(timeUntilNew()) {
        startNextGameWithNewOptions();
    };
}

void stopGame() {
    isMenuShowing = false;
    isGameStarted = false;
    isGameOverScreenShowing = false;
}

void startNextGameWithNewOptions() {
    stopGame();
    isMenuShowing = true;
}
