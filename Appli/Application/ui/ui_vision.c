#include "../include/ui_vision.h"
#include "../include/ui_common.h"
#include "../include/lcd_manager.h"
#include "../include/ai_manager.h"

void ui_vision_draw(void) {
    lcd_clear(COLOR_NAVY);
    lcd_draw_text(50, 20, "AI VISION", COLOR_LIGHTBLUE);
    lcd_draw_text(50, 50, "See and understand the world", COLOR_WHITE);
    
    // Camera Area
    lcd_draw_rect(50, 100, 400, 250, COLOR_CARD);
    lcd_draw_text(150, 200, ai_manager_get_status(), COLOR_WHITE);
    
    // Buttons
    lcd_draw_rect(500, 100, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 115, "CAPTURE", COLOR_WHITE);
    
    lcd_draw_rect(500, 200, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 215, "ANALYZE", COLOR_WHITE);
    
    lcd_draw_rect(500, 300, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 315, "BACK", COLOR_WHITE);
}

void ui_vision_handle_touch(int x, int y) {
    if (x >= 500 && x <= 650 && y >= 300 && y <= 350) {
        ui_set_screen(SCREEN_HOME);
    } else if (x >= 500 && x <= 650 && y >= 200 && y <= 250) {
        ai_manager_trigger_inference();
    }
}
