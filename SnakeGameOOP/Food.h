#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "GameBoard.h"
class Food
{
private:
    int x, y;
    int foodscore;
public:
    int getFoodscore();
    void setFoodscore(int _foodscore);
    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);
    Food(int _x = 0, int _y = 1, int _foodscore = 0);
    Food(const Food& food);
    void generateFood(GameBoard& board, int snakeX[], int snakeY[], int length);
    ~Food();
};
#endif // !FOOD_H
