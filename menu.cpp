//
// Created by alane on 02.01.2018.
//

#include <cstring>
#include "gameStates.h"
#include "gameProperties.h"
#include "menu.h"
#include "input.h"
#include "stdafx.h"
#include "gameOver.h"

int isStarting = true;
char *menuItems[] = {"Spiel starten", "Blaa", "Bliii", "Blubb"};
int currMenuItem = 0;               // Current menu item (to navigate through the menu
int lastMenuItem = 0;               // Last menu item (for deleting no longer used triangles)
int menuSize = 4;

void handleInput(char *input) {

    if (strlen(input) > 0) {
        MenuInput inputDirection = convertInputToUpAndDown(input);
        if (inputDirection == FALSE_INPUT) {

        } else if (inputDirection == ARROW_UP) {
            if (currMenuItem != 0) currMenuItem--;
        } else if (inputDirection == ARROW_DOWN) {
            currMenuItem++;
            if (currMenuItem >= 4) currMenuItem = 0;
        } else if (inputDirection == ENTER) {
            if (currMenuItem == 0) {
                isStarting = true;
                startGame();
            }
            if (currMenuItem == 4) {
                // End Game
                stopGame();
            }
        }
    }
}

void makeScreenColorful () {
    int x;
    int yVar = 19;                          // Height of the texts on screen

    if(isStarting) {


        loeschen();

        groesse (60, 60);
        formen ("s");
        farben (BLACK);

        for(x=3; x<57; x++){
            farbe2(x, 25, WHITE);
            symbolGroesse2(x, 25, 0.3);
        }

        isStarting = false;
    }

    fontSize(120);
    text2(30, 30, "Dark Snakes");

    fontSize(30);
    text2(30, 19, "Start Game");

    text2(30, 15, "Playercount: 1");

    text2(30, 11, "Enemycount : 4");

    text2(30, 7, "Difficulty: easy");        //easy, medium, hard

    text2(30, 3, "Quit Game");

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

                break;}
            case 2:{                         // Enemy count
                textFarbe2(30, yVar, WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, RED);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, WHITE);

                break;}
            case 3:{                         //Difficulty level
                textFarbe2(30, yVar, WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, RED);
                textFarbe2(30, yVar - 16, WHITE);

                break;}
            case 4:{                         //Quit Game
                textFarbe2(30, yVar,WHITE);
                textFarbe2(30, yVar - 4, WHITE);
                textFarbe2(30, yVar - 8, WHITE);
                textFarbe2(30, yVar - 12, WHITE);
                textFarbe2(30, yVar - 16, RED);

                break;}
        }
    }

}

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.
    handleInput(input);
    makeScreenColorful();
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