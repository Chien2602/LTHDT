#include "Snake.h"
#include "GameBoard.h"
#include "Food.h"
#include "Mylib.h"
#include<iostream>

using namespace std;


int Snake::getLength() {
	return length;
}
void Snake::setLength(int _length) {
	length = _length;
}
int Snake::getDirection() {
	return direction;
}
int Snake::getScore() {
	return score;
}
void Snake::setScore(int _score) {
	score = _score;
}
void Snake::setDirection(int _direction) {
	direction = _direction;
}
Snake::Snake(const Snake& snake) {
	length = snake.length;
	direction = snake.direction;
}
Snake::Snake(int _direction, int _length, int _score) {
	length = _length;
	direction = _direction;
	score = _score;
}
void Snake::initialize() {
	int x = 50, y = 13;
	for (int i = 0; i < length; i++) {
		bodyX[i] = x;
		bodyY[i] = y;
		x--;
	}
}
void Snake::draw() {
	SetColor(3);
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < length; i++) {
		gotoXY(bodyX[i], bodyY[i]);
		if (i == 0)
			cout << u8"🜐";  
		else
			cout << "o";  
	}
}
void Snake::clearOldData() {
	for (int i = 0; i < length; i++) {
		gotoXY(bodyX[i], bodyY[i]);
		cout << " ";
	}
}
void Snake::move() {
	GameBoard gameboard;
	for (int i = length; i > 0; i--) {
		bodyX[i] = bodyX[i - 1];
		bodyY[i] = bodyY[i - 1];
	}

	switch (direction) {
	case 0: bodyY[0]++; break; // xuong
	case 1: bodyY[0]--; break; // len
	case 2: bodyX[0]++; break; // phai
	case 3: bodyX[0]--; break; // trai
	};
	draw();
	
	gameboard.displayScore(score);
	
}
void Snake::changeDirection(char key) {
	if (key == -32) {
		key = _getch();
		if (key == 72 && direction != 0) direction = 1; // Up
		else if (key == 80 && direction != 1) direction = 0; // Down
		else if (key == 77 && direction != 3) direction = 2; // Right
		else if (key == 75 && direction != 2) direction = 3; // Left
	}
}
bool Snake::hasCollided(GameBoard& board) {
	return board.isCollision(bodyX[0], bodyY[0]) || hasCollisionWithBody(bodyX[0], bodyY[0]);
}
bool Snake::ateFood(Food& food) {
	return bodyX[0] == food.getX() && bodyY[0] == food.getY();
}
bool Snake::hasCollisionWithBody(int x, int y) {
	for (int i = 1; i < length; i++) {
		if (x == bodyX[i] && y == bodyY[i]) {
			return true;
		}
	}
	return false;
}
Snake::~Snake(){}