#include "../include/ui_common.h"
#include "../include/ui_home.h"
#include "../include/ui_vision.h"
#include "../include/ui_sign.h"
#include "../include/ui_tutor.h"
#include "../include/ui_explore.h"
#include "../include/lcd_manager.h"

UI_SCREEN_STATE current_screen = SCREEN_HOME;

void ui_set_screen(UI_SCREEN_STATE new_screen) {
    current_screen = new_screen;
    switch (current_screen) {
        case SCREEN_HOME:
            ui_home_draw();
            break;
        case SCREEN_VISION:
            ui_vision_draw();
            break;
        case SCREEN_SIGN:
            ui_sign_draw();
            break;
        case SCREEN_TUTOR:
            ui_tutor_draw();
            break;
        case SCREEN_EXPLORE:
            ui_explore_draw();
            break;
        case SCREEN_COMING_SOON:
            lcd_clear(COLOR_NAVY);
            lcd_draw_text(300, 200, "Coming Soon", COLOR_WHITE);
            lcd_draw_rect(300, 300, 200, 50, COLOR_CARD);
            lcd_draw_text(350, 315, "BACK", COLOR_WHITE);
            break;
    }
}
