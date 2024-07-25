#include <conio.h>
#include "key.h"

#define KEY_UP1 'w'
#define KEY_LEFT1 'a'
#define KEY_RIGHT1 'd'
#define KEY_DOWN1 's'

#define KEY_UP2 'W'
#define KEY_LEFT2 'A'
#define KEY_RIGHT2 'D'
#define KEY_DOWN2 'S'

Key_Type Key_GetKey(void)
{
	Key_Type key = KEY_NONE;
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_UP1:
		case KEY_UP2:
		{
			key = KEY_UP;
		}
		break;
		case KEY_DOWN1:
		case KEY_DOWN2:
		{
			key = KEY_DOWN;
		}
		break;
		case KEY_LEFT1:
		case KEY_LEFT2:
		{
			key = KEY_LEFT;
		}
		break;
		case KEY_RIGHT1:
		case KEY_RIGHT2:
		{
			key = KEY_RIGHT;
		}
		break;		
		default:
		{			
		}
		break;
		}
	}
	return key;
}
