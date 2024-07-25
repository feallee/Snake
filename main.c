#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "snake.h"
#include "key.h"


int main(void)
{
	Snake_ControlType control = SNAKE_CONTROL_UP;
	 
	Snake_Type snake;
	Snake_Init(&snake);
	while (Snake_Move(&snake, control))
	{	
		Key_Type key = Key_GetKey();
		if (key == KEY_UP)
		{
			control = SNAKE_CONTROL_UP;
		}
		else if (key == KEY_DOWN)
		{
			control = SNAKE_CONTROL_DOWN;
		}
		else if (key == KEY_LEFT)
		{
			control = SNAKE_CONTROL_LEFT;
		}
		else if (key == KEY_RIGHT)
		{
			control = SNAKE_CONTROL_RIGHT;
		}
		Sleep(200);
	}
	printf("\n游戏结束，按任意键退出游戏。");
	return _getch();
}