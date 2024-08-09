#ifndef SNAKE_H
#define SNAKE_H
#pragma once
#include "Food.h"
#include "GameBoard.h"

#define MAX 100

using namespace std;

class Snake
{
private:
    int direction; // 0: down, 1: up, 2: right, 3: left
    int length;
    int score;
public:
    int bodyX[MAX], bodyY[MAX];
    int getLength();
    void setLength(int _length);
    int getDirection();
    void setDirection(int _direction);
    int getScore();
    void setScore(int _score);
    Snake(const Snake& snake);
    Snake(int _direction = 2, int _length = 2, int _score = 0);
    void initialize();
    void draw();
    void clearOldData();
    void move();
    void changeDirection(char key);
    bool hasCollided(GameBoard& board);
    bool ateFood(Food& food);
    bool hasCollisionWithBody(int x, int y);
    ~Snake();
};

#endif // !SNAKE_H
