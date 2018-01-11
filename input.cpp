//
// Created by alane on 02.01.2018.
//

#include <cstring>
#include <cstdio>

#include "input.h"

MenuInput convertInputToUpAndDown(const char *input) {
    if (strcmp(input, "$ 38 Oben") == 0 || strcmp(input, "$ 87 W") == 0) return ARROW_UP;
    if (strcmp(input, "$ 40 Unten") == 0 || strcmp(input, "$ 83 S") == 0) return ARROW_DOWN;
    if (strcmp(input, "$ 39 Rechts") == 0 || strcmp(input, "$ 68 D") == 0) return ARROW_RIGHT;
    if (strcmp(input, "$ 37 Links") == 0 || strcmp(input, "$ 65 A") == 0) return ARROW_LEFT;
    if (strcmp(input, "$ 10 Eingabe") == 0) return ENTER;
    return FALSE_INPUT;
}

Direction convertInputToNewDirection(const char *input) {
    printf("%s\n", input);
    if (strcmp(input, "$ 38 Oben") == 0 || strcmp(input, "$ 87 W") == 0) return UP;
    if (strcmp(input, "$ 40 Unten") == 0 || strcmp(input, "$ 83 S") == 0) return DOWN;
    if (strcmp(input, "$ 39 Rechts") == 0 || strcmp(input, "$ 68 D") == 0) return RIGHT;
    if (strcmp(input, "$ 37 Links") == 0 || strcmp(input, "$ 65 A") == 0) return LEFT;
    return NONE;
}

int getPlayerIndexByInput(const char *input) {
    if(strcmp(input, "$ 38 Oben") == 0 ||
            strcmp(input, "$ 40 Unten") == 0 ||
            strcmp(input, "$ 39 Rechts") == 0 ||
            strcmp(input, "$ 37 Links") == 0) {
        return 0;
    } else {
        return 1;
    }
}

int isCollidingDirections(Direction oldDirection, Direction newDirection) {
    if (newDirection == UP && oldDirection != DOWN) return false;
    if (newDirection == DOWN && oldDirection != UP) return false;
    if (newDirection == RIGHT && oldDirection != LEFT) return false;
    if (newDirection == LEFT && oldDirection != RIGHT) return false;
    return true;
}