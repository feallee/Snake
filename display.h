#ifndef __DISPLAY__H__
#include <stdint.h>
void Display_Clear(void);
void Display_DrawChar(uint8_t row, uint8_t column, char value);
void Display_DrawString(uint8_t row, uint8_t column, const char* value);
void Display_DrawNumber(uint8_t row, uint8_t column, int value);
void Display_DrawSpace(uint8_t row, uint8_t column, uint8_t length);
void Display_Refresh(void);
#endif // !__DISPLAY__H__

