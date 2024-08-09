#include "GameBoard.h"
#include "Mylib.h"
#include<iostream>

using namespace std;

int GameBoard::getWidth() {
	return width;
}
int GameBoard::getHeight() {
	return height;
}
void GameBoard::setWidth(int _width) {
	width = _width;
}
void GameBoard::setHeight(int _height) {
	height = _height;
}
GameBoard::GameBoard(int w, int h) {
	width = w;
	height = h;
}
GameBoard::GameBoard(const GameBoard& gameboard) {
	width = gameboard.width;
	height = gameboard.height;
}
GameBoard::~GameBoard(){}
void GameBoard::drawWalls() {
	SetColor(12);
	SetConsoleOutputCP(CP_UTF8);
	for (int x = 10; x <= width; x++) {
		gotoXY(x, 1); cout << u8"✠";
		gotoXY(x, height); cout << u8"✠";
	}
	for (int y = 1; y <= height; y++) {
		gotoXY(10, y); cout << u8"✠";
		gotoXY(width, y); cout << u8"✠";
	}
	SetColor(7);
}
bool GameBoard::isCollision(int x, int y) {
	return x == 10 || x == width || y == 1 || y == height;
}

void GameBoard::displayScore(int score) {
	gotoXY(0, 0);
	SetColor(14);  // Yellow color for the score display
	cout << "Score: " << score;
	SetColor(7);   // Reset to default color
}