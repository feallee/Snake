#ifndef __SNAKE_H__
#include <stdint.h>
#include <stdbool.h>
#define SNAKE_WIDTH 32
#define SNAKE_HEIGHT 24
#define SNAKE_BODY_COUNT 129

typedef enum
{
	SNAKE_CONTROL_UP,
	SNAKE_CONTROL_DOWN,
	SNAKE_CONTROL_LEFT,
	SNAKE_CONTROL_RIGHT,
}Snake_ControlType;

typedef struct
{
	uint8_t Row;
	uint8_t Column;
}Snake_PointType;

typedef struct
{	
	uint8_t Count;
	Snake_PointType Body[SNAKE_BODY_COUNT];  
}Snake_Type;

void Snake_Init(Snake_Type* snake);
bool Snake_Move(Snake_Type* snake, Snake_ControlType control);
#endif // !__SNAKE_H__

