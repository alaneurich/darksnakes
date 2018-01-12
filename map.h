//
// Created by alane on 04.01.2018.
//

#ifndef DARKSNAKESTEST_MAP_H
#define DARKSNAKESTEST_MAP_H

int getRandomPos();

void setRandomPositionForSnake(struct Snake *snake, int index);

void setRandomPositionForSnakes(struct Snake *snakes, int count);

int isCollidingPoint(int x, int y, int excludeIndex);

#endif //DARKSNAKESTEST_MAP_H
