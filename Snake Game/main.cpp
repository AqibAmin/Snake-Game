#include<iostream>
#include"Screen.h"
#include<conio.h>
#include<ctime>
#include<stdio.h>
#include<windows.h>  ///for clear and Sleep   //system("Color 70");
using namespace std;
void ShowConsoleCursor(bool showFlag);
int main()
{
	char speed;
	char choice;
	srand(time(0));
	system("Color 70");
	do
	{
		ShowConsoleCursor(false);
		cout << "Select Game Mode:\n\t1. Easy\n\t2. Medium\n\t3. hard\n";
		speed = _getch();
		while (speed != '1' && speed != '2' && speed != '3')
		{
			cout << "Invalid Input.\n";
			cout << "Select Game Mode:\n\t1. Easy\n\t2. Medium\n\t3. hard\n";
			speed = _getch();
		}
		if (speed == '1')
		{
			speed = 70;
		}
		else if (speed == '2')
		{
			speed = 50;
		}
		else
		{
			speed = 30;
		}
		Screen* s1=new Screen(speed);
		int tempKey = 0;
		int keyPress = 75;
		bool  notGameOver = true;
		while (notGameOver)
		{
			cout << "Press 0 to Exit Game.\n";
			if (_kbhit())
			{
				
				tempKey = _getch();
				if (tempKey == '0')
				{
					break;
				}
				if (tempKey == 77 || tempKey == 75 || tempKey == 72 || tempKey == 80)
				{
					if (tempKey == 75 && keyPress != 77 || tempKey == 77 && keyPress != 75 || tempKey == 72 && keyPress != 80 || tempKey == 80 && keyPress != 72)
					{
						keyPress = tempKey;
					}
				}
			}
			system("CLS");
			notGameOver = s1->displayScreen(keyPress);
		}
		delete s1;
		s1 = nullptr;
		system("CLS");
		cout << "\n\t\t\t\t\t\t\tGame Over!!!!!!\n\n";
		cout << "Do you want to Continue? (Y/N): ";
		cin>>choice;
	}
	while (choice == 'Y' || choice == 'y');
	return 0;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}