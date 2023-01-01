#ifndef SCREEN_H
#define SCREEN_H

#include"Pixel.h"
#include"Position.h"
using namespace std;

const int boardRows = 15;
const int boardCols = 30;
const int snakeMaxLength = 50;

class Screen
{
private:
	int snakeLength;
	int score;
	int snakeSpeed;
	Pixel board[boardRows][boardCols];
	Position snake[snakeMaxLength];
	Position food;
public:
	Screen(int );
	bool displayScreen(char);
	void moveSnake(int);
	void resetFoodPosition();
	void extendSnakeLength();
	bool checkForGameOver();
};

#endif
