#include<iostream>
#include"Screen.h"
#include<windows.h>
using namespace std;

Screen::Screen(int speed)
{
	score = 0;
	snakeLength = 3;
	snakeSpeed = speed;
	for (int i = 0; i < snakeLength; i++)
	{
		snake[i].setRowPosition(7);
		snake[i].setColPosition(i+3);
	}
	food.setRowPosition(3);
	food.setColPosition(5);
}
bool Screen::displayScreen(char key)
{
	board[food.getRowPosition()][food.getColPosition()].setPx('*');
	this->moveSnake(key);
	if (food.getRowPosition() == snake[0].getRowPosition() && food.getColPosition() == snake[0].getColPosition())
	{
		score++;
		this->resetFoodPosition();
		this->extendSnakeLength();
	}
	cout << "\n\n\n\n\t\t\t\t\t\t ------------------------------";
	for (int i = 0; i < boardRows; i++)
	{
		cout << "\n\t\t\t\t\t\t|";
		for (int j = 0; j < boardCols; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << board[i][j].getPx();
			}
			else
			{
				cout << board[i][j].getPx();
			}
		}
		cout << "|";
	}
	cout << "\n\t\t\t\t\t\t ------------------------------";
	cout << "\n\n\t\t\t\t\t\t\t   Score: " << score << endl;
	Sleep(snakeSpeed);
	return this->checkForGameOver();
}

void Screen::moveSnake(int key)
{
	int tempR1, tempR2, tempC1, tempC2;
	tempR1 = snake[0].getRowPosition();
	tempC1 = snake[0].getColPosition();
	board[snake[0].getRowPosition()][snake[0].getColPosition()].setPx(' ');
	for (int i = 1; i < snakeLength; i++)
	{
		tempR2 = snake[i].getRowPosition();
		tempC2 = snake[i].getColPosition();
		board[snake[i].getRowPosition()][snake[i].getColPosition()].setPx(' ');
		snake[i].setRowPosition(tempR1);
		snake[i].setColPosition(tempC1);
		tempR1 = tempR2;
		tempC1 = tempC2;
	}
	if (key == 75)
	{
		if (snake[0].getColPosition() == 0)
		{
			snake[0].setColPosition(boardCols-1);
		}
		else
		{
			snake[0].setColPosition((snake[0].getColPosition() - 1) % boardCols);
		}
	}
	else if (key == 72)
	{
		
		if (snake[0].getRowPosition() == 0)
		{
			snake[0].setRowPosition(boardRows-1);
		}
		else
		{
			snake[0].setRowPosition((snake[0].getRowPosition() - 1) % boardRows);
		}
	}
	else if (key == 77)
	{
		if (snake[0].getColPosition() == boardCols-1)
		{
			snake[0].setColPosition(0);
		}
		else
		{
			snake[0].setColPosition((snake[0].getColPosition() + 1) % boardCols);
		}
		
	}
	else if (key == 80)
	{
		if (snake[0].getRowPosition() == boardRows-1)
		{
			snake[0].setRowPosition(0);
		}
		else
		{
			snake[0].setRowPosition((snake[0].getRowPosition() + 1) % boardRows);
		}
	}
	for (int i = 0; i < snakeLength; i++)
	{
		board[snake[i].getRowPosition()][snake[i].getColPosition()].setPx('o');
	}
}

void Screen::resetFoodPosition()
{
	bool flag = true;
	int count = 0;
	while (flag)
	{
		food.setRowPosition(rand() % (boardRows));
		food.setColPosition(rand() % (boardCols));
		for (int i = 0; i < snakeLength; i++)
		{
			if (snake[i].getRowPosition() == food.getRowPosition() && snake[i].getColPosition() == food.getColPosition())
			{
				count++;
			}
		}
		if (count == 0)
		{
			flag = false;
		}
	}
}

void Screen::extendSnakeLength()
{
	if (snake[snakeLength-1].getRowPosition()== snake[snakeLength - 2].getRowPosition())
	{
		snake[snakeLength].setRowPosition(snake[snakeLength-1].getRowPosition());
		if (snake[snakeLength-2].getColPosition() < snake[snakeLength-1].getColPosition())
		{
			snake[snakeLength].setColPosition((snake[snakeLength - 1].getColPosition() + 1) % boardCols);
		}
		else if(snake[snakeLength - 2].getColPosition() > snake[snakeLength - 1].getColPosition())
		{
			snake[snakeLength].setColPosition((snake[snakeLength - 1].getColPosition() - 1) % boardCols);
		}
	}
	else if(snake[snakeLength - 1].getColPosition() == snake[snakeLength - 2].getColPosition())
	{
		if (snake[snakeLength - 2].getRowPosition()<snake[snakeLength - 1].getRowPosition())
		{
			snake[snakeLength].setRowPosition((snake[snakeLength - 1].getRowPosition() + 1) % boardRows);
		}
		else if (snake[snakeLength - 2].getRowPosition() > snake[snakeLength - 1].getRowPosition())
		{
			snake[snakeLength].setRowPosition((snake[snakeLength - 1].getRowPosition() - 1) % boardRows);
		}
		snake[snakeLength].setColPosition(snake[snakeLength - 1].getColPosition());
	}
	snakeLength++;
}

bool Screen::checkForGameOver()
{
	cout << endl;
	for (int i = 0; i < snakeLength; i++)
	{
		for (int j = 0; j < snakeLength; j++)
		{
			if (snake[i].getRowPosition() == snake[j].getRowPosition() && snake[i].getColPosition() == snake[j].getColPosition()&&i!=j)
			{
				return false;
			}

		}
	}
	return true;
}