#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

#include <tk/tkernel.h>

int lcd_manager_init(void);
void lcd_clear(unsigned int color);
void lcd_draw_rect(int x, int y, int w, int h, unsigned int color);
void lcd_draw_text(int x, int y, const char *text, unsigned int color);

#define COLOR_NAVY 0x000080
#define COLOR_LIGHTBLUE 0xADD8E6
#define COLOR_WHITE 0xFFFFFF
#define COLOR_CARD 0x1E1E1E
#define COLOR_ACCENT 0x00FF00

#endif
