#include <iostream>
#include <ctime>
#include <conio.h>
#include "GameBoard.h"
#include "Snake.h"
#include "Food.h"
#include "Mylib.h"  

#define MAX 100

using namespace std;

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main() {
    GameBoard board;
    Snake snake;
    Food food;
    hideCursor();
    board.drawWalls();
    snake.initialize();
    snake.draw();

    food.generateFood(board, snake.bodyX, snake.bodyY, snake.getLength());

    bool gameover = false;

    while (!gameover) {
        if (_kbhit()) {
            char key = _getch();
            snake.changeDirection(key);
        }

        snake.clearOldData();
        snake.move();

        if (snake.ateFood(food)) {
            
            snake.setScore(snake.getScore() + food.getFoodscore());
            snake.setLength(snake.getLength() + food.getFoodscore());
            food.generateFood(board, snake.bodyX, snake.bodyY, snake.getLength());
        }

        gameover = snake.hasCollided(board);

        Sleep(150);
    }
    _getch();
    return 0;
}
