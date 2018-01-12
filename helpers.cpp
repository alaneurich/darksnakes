//
// Created by alane on 02.01.2018.
//

#include <afxres.h>
#include <sys/time.h>
#include "helpers.h"

Snake* getDynamicSizedSnakeArray(int size) {
    auto *snakes = new Snake[size];
    int playerCount = gPlayerCount;
    for(int a = 0; a < size; a++) {
        snakes[a].positions[0][0] = 0;
        snakes[a].positions[0][1] = 0;
        snakes[a].positions[1][0] = 0;
        snakes[a].positions[1][1] = 0;
        if(playerCount != 0) {
            snakes[a].isPlayer = true;
            playerCount--;
        }
    }
    return snakes;
}

void deleteFirstObject(struct Snake *tmpSnake) {
    for (int a = 0; a < (*tmpSnake).currSize; a++) {
        if (a + 1 != (*tmpSnake).currSize) {
            (*tmpSnake).positions[a][0] = (*tmpSnake).positions[a + 1][0];
            (*tmpSnake).positions[a][1] = (*tmpSnake).positions[a + 1][1];
        }
    }
}

long long timeMs() {
    struct timeval tv{};
    gettimeofday(&tv, nullptr);
    return (((long long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}