#include<iostream>
#include"Pixel.h"

using namespace std;

Pixel::Pixel()
{
	px = ' ';
}
char Pixel::getPx()const
{
	return px;
}
void Pixel::setPx(char p)
{
	px = p;
}