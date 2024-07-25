#ifndef __KEY_H__

typedef enum
{
	KEY_NONE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
}Key_Type;

Key_Type Key_GetKey(void);

#endif // !__KEY_H__

