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

int playerCount = 1;
int enemyCount = 4;
int difficulty = 150;


int isStarting = true;
int currMenuItem = 0;
int hadVariableChange = true;

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
            case 3:{                         //difficulty level
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

int handleInput(char *input) {
    if (strlen(input) > 0) {
        MenuInput inputDirection = convertInputToUpAndDown(input);
        if (inputDirection == FALSE_INPUT) {

        } else if (inputDirection == ARROW_UP) {
            if (currMenuItem != 0) {
                currMenuItem--;
                highlightOption();
                hadVariableChange = true;
            }
        } else if (inputDirection == ARROW_DOWN) {
            currMenuItem++;
            if (currMenuItem >= 5) currMenuItem = 0;
            highlightOption();
            hadVariableChange = true;
        } else if (inputDirection == ENTER) {
            if (currMenuItem == 0) {
                setGameVars(playerCount, enemyCount, difficulty);
                isStarting = true;
                hadVariableChange = true;
                startGame();
                return true;
            }
            if (currMenuItem == 4) {
                stopGame();
                return true;
            }
        }
        else if (inputDirection == ARROW_LEFT) {
            if (currMenuItem == 1) {
                if (playerCount != 1) {
                    playerCount--;
                    hadVariableChange = true;
                }
            }
            if (currMenuItem == 2) {
                if (enemyCount != 0) {
                    enemyCount--;
                    hadVariableChange = true;
                }
            }
            if (currMenuItem == 3){
                if (difficulty != 150)
                {
                    difficulty+=50;
                    hadVariableChange = true;
                }
            }
        }
        else if (inputDirection == ARROW_RIGHT){
            if(currMenuItem == 1) {
                if (playerCount != 2) {
                    playerCount++;
                    hadVariableChange = true;
                }
            }
            if(currMenuItem == 2) {
                if (enemyCount != 6) {
                    enemyCount++;
                    hadVariableChange = true;
                }
            }
            if(currMenuItem == 3){
                if (difficulty != 50) {
                    difficulty-=50;
                    hadVariableChange = true;
                }
            }
        }
    }
    return false;
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

        fontSize(120);
        text2(30, 30, "Dark Snakes");
        textFarbe2(30, 30, WHITE);

        fontSize(30);
        text2(30, 19, "Start Game");

        text2(30, 3, "Quit Game");
    }

    if(hadVariableChange) {
        fontSize(30);
        int isPlayercountText = currMenuItem == 1;
        char playercountText[256];
        snprintf(playercountText, sizeof(playercountText), "%sPlayercount: %d%s",
                 isPlayercountText ? "< " : "",
                 playerCount,
                 isPlayercountText ? " >" : "");
        text2(30, 15, playercountText);

        int isEnemycountText = currMenuItem == 2;
        char enemycountText[256];
        snprintf(enemycountText, sizeof(enemycountText), "%sEnemycount: %d%s",
                 isEnemycountText ? "< " : "",
                 enemyCount,
                 isEnemycountText ? " >" : "");
        text2(30, 11, enemycountText);

        int isDifficultyText = currMenuItem == 3;
        char difficultyText[256];
        snprintf(difficultyText, sizeof(difficultyText), "%sDifficulty: %s%s",
                 isDifficultyText ? "< " : "",
                 difficulty == 150 ? "Easy" : difficulty == 100 ? "Medium" : "Hard",
                 isDifficultyText ? " >" : "");
        text2(30, 7, difficultyText);
        hadVariableChange = false;
    }

    if(isStarting) {
        highlightOption();
        isStarting = false;
    }

}

void drawMenuScreen(char *input) {
    //TODO Actually show a Menu.
    if(handleInput(input)) return;
    makeScreenColorful();
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