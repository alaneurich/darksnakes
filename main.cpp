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

void crossPlatformSleep(int sleepTime) {
#ifdef _WIN32
    Sleep(static_cast<DWORD>(sleepTime / 1000));
#else
    usleep(pollingDelay);  /* sleep for 100 milliSeconds */
#endif
}

int main() {
    srand(time(NULL));
    char *currInput;
    long long currTime;
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
            lastFrameTime = currTime;
        } else {
            crossPlatformSleep(lastFrameTime + 16000 - currTime);
        }
    }
    return 0;
}