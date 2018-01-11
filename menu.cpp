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

int PlayerCount = 1;
int EnemyCount = 4;
int Difficulty = 150;


int isStarting = true;
char *menuItems[] = {"Spiel starten", "Blaa", "Bliii", "Blubb"};
int currMenuItem = 0;               // Current menu item (to navigate through the menu
int lastMenuItem = 0;               // Last menu item (for deleting no longer used triangles)
int menuSize = 4;
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

int handleInput(char *input) {
    if (strlen(input) > 0) {
        MenuInput inputDirection = convertInputToUpAndDown(input);
        if (inputDirection == FALSE_INPUT) {

        } else if (inputDirection == ARROW_UP) {
            if (currMenuItem != 0) {
                currMenuItem--;
                highlightOption();
            }
        } else if (inputDirection == ARROW_DOWN) {
            currMenuItem++;
            if (currMenuItem >= 5) currMenuItem = 0;
            highlightOption();
        } else if (inputDirection == ENTER) {
            if (currMenuItem == 0) {
                setGameVars(PlayerCount, EnemyCount, Difficulty);
                startGame();
                isStarting = true;
                return true;
            }
            if (currMenuItem == 4) {
                stopGame();
                return true;
            }
        }
        else if (inputDirection == ARROW_LEFT) {
            if (currMenuItem == 1) {
                if (PlayerCount != 1) {
                    PlayerCount--;
                    hadVariableChange = true;
                }
            }
            if (currMenuItem == 2) {
                if (EnemyCount != 0) {
                    EnemyCount--;
                    hadVariableChange = true;
                }
            }
            if (currMenuItem == 3){
                if (Difficulty != 150)
                {
                    Difficulty+=50;
                    hadVariableChange = true;
                }
            }
        }
        else if (inputDirection == ARROW_RIGHT){
            if(currMenuItem == 1) {
                if (PlayerCount != 2) {
                    PlayerCount++;
                    hadVariableChange = true;
                }
            }
            if(currMenuItem == 2) {
                if (EnemyCount != 6) {
                    EnemyCount++;
                    hadVariableChange = true;
                }
            }
            if(currMenuItem == 3){
                if (Difficulty != 50) {
                    Difficulty-=50;
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

        isStarting = false;
    }

    if(hadVariableChange) {
        fontSize(30);
        int isPlayercountText = currMenuItem == 1;
        char playercountText[256];
        snprintf(playercountText, sizeof(playercountText), "%sPlayercount: %d%s",
                 isPlayercountText ? "< " : "",
                 PlayerCount,
                 isPlayercountText ? " >" : "");
        text2(30, 15, playercountText);

        char enemycountText[256];
        snprintf(enemycountText, sizeof(enemycountText), "Enemycount: %d", EnemyCount);
        text2(30, 11, enemycountText);

        char difficultyText[256];
        snprintf(difficultyText, sizeof(difficultyText), "Difficulty: %s",
                 Difficulty == 150 ? "Easy" : Difficulty == 100 ? "Medium" : "Hard");
        text2(30, 7, difficultyText);
        hadVariableChange = false;
    }

    if(isStarting) highlightOption();

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