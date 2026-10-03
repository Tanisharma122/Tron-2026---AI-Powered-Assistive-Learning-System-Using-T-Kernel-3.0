#include "../include/lcd_manager.h"
#include <tm/tmonitor.h>
#include "../tglib.h"

int lcd_manager_init(void) {
    tm_printf((UB*)"LCD READY\n");
    tglib_init();
    return 0;
}

void lcd_clear(unsigned int color) {
    /* Implementation using tglib or direct BSP */
}

void lcd_draw_rect(int x, int y, int w, int h, unsigned int color) {
    /* Implementation */
}

void lcd_draw_text(int x, int y, const char *text, unsigned int color) {
    /* Implementation */
}
