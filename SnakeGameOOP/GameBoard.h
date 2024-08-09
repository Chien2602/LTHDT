#ifndef GAMEBOARD_H
#pragma once

using namespace std;

class GameBoard
{
private:
    int width;
    int height;
public:
    int getWidth();
    int getHeight();
    void setWidth(int _width);
    void setHeight(int _height);
    GameBoard(int w = 100, int h = 26);
    GameBoard(const GameBoard& gameboard);
    ~GameBoard();
    void drawWalls();
    bool isCollision(int x, int y);
    void displayScore(int score);
};
#endif // !GAMEBOARD_H
