#include "../include/ui_sign.h"
#include "../include/ui_common.h"
#include "../include/lcd_manager.h"
#include "../include/ai_sign_manager.h"
#include "../include/camera_manager.h"
#include <string.h>

static char sentence_buffer[128] = "";

void ui_sign_draw(void) {
    lcd_clear(COLOR_NAVY);
    lcd_draw_text(50, 20, "AI COMMUNICATION", COLOR_LIGHTBLUE);
    lcd_draw_text(50, 50, "Sign language to text", COLOR_WHITE);
    
    // Camera View Area
    lcd_draw_rect(50, 80, 400, 200, COLOR_CARD);
    lcd_draw_text(150, 160, ai_sign_manager_get_status(), COLOR_WHITE);
    
    // Detected Sign Area
    lcd_draw_text(50, 290, "Detected Sign:", COLOR_LIGHTBLUE);
    lcd_draw_text(50, 320, sentence_buffer, COLOR_WHITE);
    
    // Buttons
    lcd_draw_rect(500, 100, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 115, "START", COLOR_WHITE);
    
    lcd_draw_rect(500, 200, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 215, "CLEAR", COLOR_WHITE);
    
    lcd_draw_rect(500, 300, 150, 50, COLOR_ACCENT);
    lcd_draw_text(520, 315, "BACK", COLOR_WHITE);
}

void ui_sign_handle_touch(int x, int y) {
    if (x >= 500 && x <= 650 && y >= 300 && y <= 350) {
        // BACK
        ui_set_screen(SCREEN_HOME);
    } else if (x >= 500 && x <= 650 && y >= 200 && y <= 250) {
        // CLEAR
        sentence_buffer[0] = '\0';
        ui_set_screen(SCREEN_SIGN); // Redraw
    } else if (x >= 500 && x <= 650 && y >= 100 && y <= 150) {
        // START
        ai_sign_manager_trigger_inference();
        const char* res = ai_sign_manager_get_result();
        if (res && res[0] != '\0') {
            if (strlen(sentence_buffer) > 0) {
                strcat(sentence_buffer, " ");
            }
            strcat(sentence_buffer, res);
        }
        ui_set_screen(SCREEN_SIGN); // Redraw
    }
}
