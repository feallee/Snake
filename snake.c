#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "display.h"
#include "snake.h"


static bool ExistsPoint(Snake_Type* snake, Snake_PointType point)
{
	bool r = false;
	for (uint8_t i = 0; i < snake->Count; i++)
	{
		if (snake->Body[i].Row == point.Row && snake->Body[i].Column == point.Column)
		{
			r = true;
			break;
		}
	}
	return r;
}

static void CreateFood(Snake_Type* snake)
{
	Snake_PointType p = { 0,0 };
	do
	{
		int rnd = rand() % (SNAKE_WIDTH * SNAKE_HEIGHT);
		p.Row = rnd / SNAKE_WIDTH + 3;
		p.Column = rnd % SNAKE_WIDTH + 2;
	} while (ExistsPoint(snake, p));
	snake->Food.Row = p.Row;
	snake->Food.Column = p.Column;
	Display_DrawChar(p.Row, p.Column, '*');
}

void Snake_Init(Snake_Type* snake)
{
	srand((unsigned int)time((time_t*)NULL));
	snake->Count = 1;
	snake->Body[0].Row = SNAKE_HEIGHT + 2;
	snake->Body[0].Column = SNAKE_WIDTH / 2 + 1;
	CreateFood(snake);

	Display_DrawString(1, SNAKE_WIDTH / 2, "SNAKE");

	for (uint8_t i = 0; i < SNAKE_WIDTH; i++)
	{
		Display_DrawChar(2, i + 2, '-');
	}
	for (uint8_t i = 0; i < SNAKE_HEIGHT; i++)
	{
		Display_DrawChar(i + 3, 1, '|');
		Display_DrawChar(i + 3, SNAKE_WIDTH + 2, '|');
	}
	for (uint8_t i = 0; i < SNAKE_WIDTH; i++)
	{
		Display_DrawChar(SNAKE_HEIGHT + 3, i + 2, '-');
	}
	Display_DrawString(SNAKE_HEIGHT + 4, 1, "按键：w=上,s=下,a=左,d=右，分数：");
}

static Snake_PointType CalcPoint(Snake_Type* snake, Snake_ControlType control)
{
	Snake_PointType p = { 0 };
	if (control == SNAKE_CONTROL_UP)
	{
		p.Row = snake->Body[0].Row - 1;
		p.Column = snake->Body[0].Column;
	}
	else if (control == SNAKE_CONTROL_DOWN)
	{
		p.Row = snake->Body[0].Row + 1;
		p.Column = snake->Body[0].Column;

	}
	else if (control == SNAKE_CONTROL_LEFT)
	{
		p.Row = snake->Body[0].Row;
		p.Column = snake->Body[0].Column - 1;
	}
	else
	{
		p.Row = snake->Body[0].Row;
		p.Column = snake->Body[0].Column + 1;
	}
	return p;
}

bool Snake_Move(Snake_Type* snake, Snake_ControlType control)
{
	Snake_PointType head = CalcPoint(snake, control), tail = { 0 };
	tail.Row = snake->Body[snake->Count - 1].Row;
	tail.Column = snake->Body[snake->Count - 1].Column;

	if (head.Row == snake->Food.Row && head.Column == snake->Food.Column)//食物处理
	{
		snake->Body[snake->Count].Row = snake->Food.Row;
		snake->Body[snake->Count].Column = snake->Food.Column;
		snake->Count++;
		CreateFood(snake);
	}
	else
	{
		Display_DrawChar(tail.Row, tail.Column, ' ');
	}
	
	//处理身体+尾
	for (uint8_t i = snake->Count - 1; i > 0; i--)
	{
		snake->Body[i].Row = snake->Body[i - 1].Row;
		snake->Body[i].Column = snake->Body[i - 1].Column;
		Display_DrawChar(snake->Body[i].Row, snake->Body[i].Column, i < snake->Count - 1 ? 'o' : '.');
	}

	//处理头
	snake->Body[0].Row = head.Row;
	snake->Body[0].Column = head.Column;

	//处理越界和身体
	bool r;
	if (head.Row > 2 && head.Row < SNAKE_HEIGHT + 3 && head.Column>1 && head.Column < SNAKE_WIDTH + 2 && snake->Count < SNAKE_BODY_COUNT)
	{
		r = true;
		Display_DrawChar(head.Row, head.Column, 'O');
	}
	else
	{
		r = false;
		Display_DrawChar(head.Row, head.Column, 'X');
	}

	

	//处理分数
	Display_DrawNumber(SNAKE_HEIGHT + 4, 34, snake->Count);
	return r;
}
