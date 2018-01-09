//
// Created by alane on 02.01.2018.
//

#ifndef DARKSNAKESTEST_DRAW_H
#define DARKSNAKESTEST_DRAW_H

enum SnakeMoveResult{
    HIT_WALL,
    GOT_REWARD,
    NOTHING
};
void setupDraw();
void initialDraw(struct Snake *playerSnakes, Snake *enemySnakes);
void drawSnakePart(int x, int y, int color);
void drawReward(int x, int y);
void resetField(int x, int y);
SnakeMoveResult moveSnake(struct Snake *tmpSnake, int color, const int currRewardPos[]);

#endif //DARKSNAKESTEST_DRAW_H
