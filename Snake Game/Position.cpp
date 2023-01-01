#include<iostream>
#include"Position.h"

using namespace std;

Position::Position()
{
	rowPosition = 0;
	colPosition = 0;
}

int Position::getRowPosition()const
{
	return rowPosition;
}
int Position::getColPosition()const
{
	return colPosition;
}
void Position::setRowPosition(int row)
{
	rowPosition = row;
}
void Position::setColPosition(int col)
{
	colPosition = col;
}
