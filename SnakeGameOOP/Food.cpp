#include "Food.h"
#include "Mylib.h"
#include "GameBoard.h"
#include "Snake.h"
#include<iostream>

using namespace std;


int Food::getFoodscore() {
	return foodscore;
}
int Food::getX() {
	return x;
}
int Food::getY() {
	return y;
}
void Food::setFoodscore(int _foodscore) {
	foodscore = _foodscore;
}
void Food::setX(int _x) {
	x = _x;
}
void Food::setY(int _y) {
	y = _y;
}
Food::Food(int _x, int _y, int _foodscore) {
	x = _x;
	y = _y;
	foodscore = _foodscore;
}
Food::Food(const Food& food) {
	x = food.x;
	y = food.y;
	foodscore = food.foodscore;
}
void Food::generateFood(GameBoard& board, int snakeX[], int snakeY[], int length) {
	srand(time(NULL));
	SetConsoleOutputCP(CP_UTF8);
	//char food[3] = { '$', 'O', '*'};
	int foodScore[3] = { 1, 2, 3 };
	do {
		x = rand() % (99 - 11 + 1) + 11;
		y = rand() % (25 - 2 + 1) + 2;
	} while (Snake().hasCollisionWithBody(x, y));
	//int color = rand() % 15 + 1;
	SetColor(6);
	gotoXY(x, y);
	string foodIndex;
	int randomValue = rand() % 100; 
	int index;
	if (randomValue < 75) {
		foodIndex = u8"$";
		index = 0;
	}
	else if (randomValue < 90 and randomValue >= 75) {
		foodIndex = u8"€";
		index = 1;
	}
	else {
		foodIndex = u8"£";
		index = 2;
	}

	int scoreIndex = foodScore[index];
	foodscore = scoreIndex;
	cout << foodIndex;
	SetColor(7);
}
Food::~Food(){}