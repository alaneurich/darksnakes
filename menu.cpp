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

int xVarTriLD = 38;                 // x value for triangle tld at Player count
int xVarTriRD = 22;                 // x value for triangle trd at Player count
int yVarTri;                        // y value for triangle height

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
            if(inputDirection == ENTER && currMenuItem == 0) {
                startGame();
            }
            if(inputDirection == ENTER && currMenuItem == 4){
                //End Game
            }
        }
    }
}

void makeScreenColorful () {
    if(isStarting) {
        int x;
        int yVar = 19;                          // Height of the texts on screen

        loeschen();

        groesse (60, 60);
        formen ("s");
        farben (BLACK);

        for(x=3; x<57; x++){
            farbe2(x, 25, WHITE);
            symbolGroesse2(x, 25, 0.3);
        }

        fontSize(120);
        text2(30, 30, "Dark Snakes");
        textFarbe2(30, 30, WHITE);

        fontSize(30);
        text2(30, 19, "Start Game");
        textFarbe2(30, yVar, WHITE);

        text2(30, 15, "Playercount: 1");
        textFarbe2(30, yVar-4, WHITE);

        text2(30, 11, "Enemycount : 4");
        textFarbe2(30, yVar-8, WHITE);

        text2(30, 7, "Difficulty: easy");        //easy, medium, hard
        textFarbe2(30, yVar-12, WHITE);

        text2(30, 3, "Quit Game");
        textFarbe2(30, yVar-16, WHITE);

        isStarting = false;
    }
}



void drawTriangleToNavigate(int currMenuItem){


    switch (currMenuItem) {             // defines yVarTri for every menu option that is highlighted
        case 1: {                       // and gives it to the code below the switch-statement
            yVarTri = 16;
            break;
        }
        case 2: {
            yVarTri = 12;
            xVarTriLD = 39;
            xVarTriRD = 21;
            break;
        }
        case 3: {
            yVarTri = 8;
            break;

        }

    }

    form2(xVarTriLD, yVarTri, "tld");    // triangle left down on the right side of the option
    hintergrund2(xVarTriLD, yVarTri, BLACK);
    farbe2(xVarTriLD, yVarTri, YELLOW);

    form2(xVarTriLD, yVarTri-1, "tlu");    // triangle left down on the right side of the option
    hintergrund2(xVarTriLD, yVarTri-1, BLACK);
    farbe2(xVarTriLD, yVarTri-1, YELLOW);

    form2(xVarTriRD, yVarTri, "trd");    // triangle right down on the right side of the option
    hintergrund2(xVarTriRD, yVarTri, BLACK);
    farbe2(xVarTriRD, yVarTri, YELLOW);

    form2(xVarTriRD, yVarTri-1, "tru");    // triangle right down on the right side of the option
    hintergrund2(xVarTriRD, yVarTri-1, BLACK);
    farbe2(xVarTriRD, yVarTri-1, YELLOW);

}

void deleteTriangleForNoLongerUsedOption (int currMenuItem){

    form2(xVarTriLD, yVarTri, "none");    // triangle left down on the right side of the option
    form2(xVarTriLD, yVarTri-1, "none");    // triangle left up on the right side of the option
    form2(xVarTriRD, yVarTri, "none");    // triangle right down on the right side of the option
    form2(xVarTriRD, yVarTri-1, "none");    // triangle right up on the right side of the option

}

void highlightOption (){
    int x;
    int yVar = 19;                    // the height at which the texts are put on screen


    {
        switch (currMenuItem) {
            case 0:{                         // Start Game
                textFarbe2(30, yVar, RED);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, WHITE);

                break;}
            case 1:{                         //Player count
                textFarbe2(30, yVar, WHITE);
                textFarbe2(30, yVar - 4, RED);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, WHITE);

                drawTriangleToNavigate(1);
                deleteTriangleForNoLongerUsedOption(1);

                break;}
            case 2:{                         // Enemy count
                textFarbe2(30, yVar, WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, RED);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, WHITE);

                drawTriangleToNavigate(2);

                break;}
            case 3:{                         //Difficulty level
                textFarbe2(30, yVar, WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, RED);
                textFarbe2(30, yVar - 16, WHITE);

                drawTriangleToNavigate(3);

                break;}
            case 4:{                         //Quit Game
                textFarbe2(30, yVar,WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, RED);

                break;}
            default:
                currMenuItem = 0;
        }
    }

}

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.

    makeScreenColorful();
    handleInput(input);
    highlightOption();
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