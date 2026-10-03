#include "../include/ui_explore.h"
#include "../include/ui_common.h"
#include "../include/lcd_manager.h"
#include "../include/ai_explore_manager.h"

typedef enum {
    EXP_STATE_INPUT,
    EXP_STATE_PROCESSING,
    EXP_STATE_ANSWER
} EXPLORE_STATE;

static EXPLORE_STATE e_state = EXP_STATE_INPUT;
static const char* current_question = "";

void ui_explore_draw(void) {
    lcd_clear(COLOR_NAVY);
    lcd_draw_text(50, 20, "AI EXPLORE", COLOR_LIGHTBLUE);
    lcd_draw_text(50, 50, "Discover knowledge with AI", COLOR_WHITE);

    if (e_state == EXP_STATE_INPUT) {
        lcd_draw_text(50, 100, "Enter Question:", COLOR_WHITE);
        lcd_draw_rect(50, 130, 400, 40, COLOR_CARD);
        lcd_draw_text(60, 140, "Ask something...", COLOR_WHITE);

        // Suggested
        lcd_draw_rect(50, 200, 200, 40, COLOR_CARD);
        lcd_draw_text(60, 210, "What is AI?", COLOR_WHITE);
        
        lcd_draw_rect(280, 200, 200, 40, COLOR_CARD);
        lcd_draw_text(290, 210, "How does a CPU work?", COLOR_WHITE);

        lcd_draw_rect(500, 130, 100, 40, COLOR_ACCENT);
        lcd_draw_text(510, 140, "ASK AI", COLOR_WHITE);

        lcd_draw_rect(500, 300, 150, 40, COLOR_ACCENT);
        lcd_draw_text(520, 310, "HOME", COLOR_WHITE);
    } else if (e_state == EXP_STATE_PROCESSING) {
        lcd_draw_text(50, 100, "QUESTION:", COLOR_LIGHTBLUE);
        lcd_draw_text(50, 130, current_question, COLOR_WHITE);
        
        lcd_draw_text(50, 200, ai_explore_manager_get_status(), COLOR_ACCENT);

        lcd_draw_rect(500, 300, 150, 40, COLOR_ACCENT);
        lcd_draw_text(520, 310, "BACK", COLOR_WHITE);
    } else if (e_state == EXP_STATE_ANSWER) {
        lcd_draw_text(50, 100, "QUESTION:", COLOR_LIGHTBLUE);
        lcd_draw_text(50, 130, current_question, COLOR_WHITE);

        lcd_draw_text(50, 170, "AI ANSWER:", COLOR_LIGHTBLUE);
        lcd_draw_text(50, 200, ai_explore_manager_get_answer(), COLOR_WHITE);

        lcd_draw_rect(50, 300, 150, 40, COLOR_CARD);
        lcd_draw_text(60, 310, "NEW QUESTION", COLOR_WHITE);

        lcd_draw_rect(500, 300, 150, 40, COLOR_ACCENT);
        lcd_draw_text(520, 310, "HOME", COLOR_WHITE);
    }
}

void ui_explore_handle_touch(int x, int y) {
    if (e_state == EXP_STATE_INPUT) {
        if (x >= 50 && x <= 250 && y >= 200 && y <= 240) {
            current_question = "What is AI?";
            e_state = EXP_STATE_PROCESSING;
            ai_explore_manager_ask_question(current_question);
            // Simulate processing finishing
            e_state = EXP_STATE_ANSWER;
            ui_set_screen(SCREEN_EXPLORE);
        } else if (x >= 280 && x <= 480 && y >= 200 && y <= 240) {
            current_question = "How does a CPU work?";
            e_state = EXP_STATE_PROCESSING;
            ai_explore_manager_ask_question(current_question);
            // Simulate processing finishing
            e_state = EXP_STATE_ANSWER;
            ui_set_screen(SCREEN_EXPLORE);
        } else if (x >= 500 && x <= 600 && y >= 130 && y <= 170) {
            current_question = "Ask something...";
            e_state = EXP_STATE_PROCESSING;
            ai_explore_manager_ask_question(current_question);
            e_state = EXP_STATE_ANSWER;
            ui_set_screen(SCREEN_EXPLORE);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 340) {
            ui_set_screen(SCREEN_HOME);
        }
    } else if (e_state == EXP_STATE_PROCESSING) {
        if (x >= 500 && x <= 650 && y >= 300 && y <= 340) {
            e_state = EXP_STATE_INPUT;
            ui_set_screen(SCREEN_EXPLORE);
        }
    } else if (e_state == EXP_STATE_ANSWER) {
        if (x >= 50 && x <= 200 && y >= 300 && y <= 340) {
            e_state = EXP_STATE_INPUT;
            ui_set_screen(SCREEN_EXPLORE);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 340) {
            ui_set_screen(SCREEN_HOME);
        }
    }
}
