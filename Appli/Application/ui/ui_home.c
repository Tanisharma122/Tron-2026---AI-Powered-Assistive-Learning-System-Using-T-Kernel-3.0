#include "../include/ui_home.h"
#include "../include/ui_common.h"
#include "../include/lcd_manager.h"

void ui_home_draw(void) {
    lcd_clear(COLOR_NAVY);
    lcd_draw_text(50, 20, "AI ASSISTIVE LEARNING", COLOR_LIGHTBLUE);
    lcd_draw_text(50, 50, "Real-Time Intelligence * uT-Kernel 3.0", COLOR_WHITE);
    
    // SEE Card
    lcd_draw_rect(50, 100, 150, 100, COLOR_CARD);
    lcd_draw_text(70, 140, "SEE\nAI Vision", COLOR_WHITE);
    
    // SIGN Card
    lcd_draw_rect(250, 100, 150, 100, COLOR_CARD);
    lcd_draw_text(270, 140, "SIGN\nAI Comm", COLOR_WHITE);
    
    // LEARN Card
    lcd_draw_rect(50, 250, 150, 100, COLOR_CARD);
    lcd_draw_text(70, 290, "LEARN\nAI Tutor", COLOR_WHITE);
    
    // EXPLORE Card
    lcd_draw_rect(250, 250, 150, 100, COLOR_CARD);
    lcd_draw_text(270, 290, "EXPLORE\nAI Know", COLOR_WHITE);
    
    // Status Bar
    lcd_draw_text(50, 400, "o uT-Kernel Running   o AI Ready   o System OK", COLOR_WHITE);
}

void ui_home_handle_touch(int x, int y) {
    if (x >= 50 && x <= 200 && y >= 100 && y <= 200) {
        ui_set_screen(SCREEN_VISION);
    } else if (x >= 250 && x <= 400 && y >= 100 && y <= 200) {
        ui_set_screen(SCREEN_SIGN);
    } else if (x >= 50 && x <= 200 && y >= 250 && y <= 350) {
        ui_set_screen(SCREEN_TUTOR);
    } else if (x >= 250 && x <= 400 && y >= 250 && y <= 350) {
        ui_set_screen(SCREEN_EXPLORE);
    }
}
