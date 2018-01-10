#include <cstdlib>
#include <sys/time.h>
#include "stdafx.h"
#include "helpers.h"
#include "gameStates.h"
#include "menu.h"
#include "game.h"
#include "gameOver.h"

#define SIXTY_FPS_IN_MS 16

long long lastFrameTime = 0;

int main() {
    srand(time(NULL));
    char *currInput;
    long long currTime = 0;
    while(isMenuShowing || isGameStarted || isGameOverScreenShowing) {
        currTime = timeMs();
        if (currTime - lastFrameTime >= SIXTY_FPS_IN_MS) {
            currInput = abfragen();
            if(isMenuShowing) {
                drawMenuScreen(currInput);
            }
            else if(isGameStarted) {
                drawGameScreen(currInput);
            }
            else if(isGameOverScreenShowing) {
                drawGameOverScreen(currInput);
            }
            lastFrameTime = timeMs();
        } else {
            Sleep((lastFrameTime + 16000 - currTime) / 1000);
        }
    }
    return 0;
}