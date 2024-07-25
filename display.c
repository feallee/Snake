#include <stdio.h>
#include "display.h"
void Display_Clear(void)
{
	printf("\033[2J");
}

void Display_DrawChar(uint8_t row, uint8_t column, char value)
{
	printf("\033[%d;%dH%c", row, column, value);
}

void Display_DrawString(uint8_t row, uint8_t column, const char* value)
{
	printf("\033[%d;%dH%s", row, column, value);
}

void Display_DrawNumber(uint8_t row, uint8_t column, int value)
{
	printf("\033[%d;%dH%d", row, column, value);
}

void Display_DrawSpace(uint8_t row, uint8_t column, uint8_t length)
{
	printf("\033[%d;%dH%*s", row, column, length, " ");
}

void Display_Refresh(void)
{
	fflush(stdout);
}