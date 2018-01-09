//
// Created by alane on 02.01.2018.
//

#ifndef DARKSNAKESTEST_HELPERS_H
#define DARKSNAKESTEST_HELPERS_H

#include "snakeTypes.h"

Snake* getDynamicSizedSnakeArray(int size);
void deleteFirstObject(struct Snake *tmpSnake);
long long timeMs();

#endif //DARKSNAKESTEST_HELPERS_H
