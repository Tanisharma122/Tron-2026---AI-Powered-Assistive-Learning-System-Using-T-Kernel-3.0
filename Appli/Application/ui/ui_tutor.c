#include "../include/ui_tutor.h"
#include "../include/ui_common.h"
#include "../include/lcd_manager.h"
#include "../include/ai_tutor_manager.h"

typedef enum {
    STATE_SUBJECTS,
    STATE_TOPICS,
    STATE_EXPLANATION,
    STATE_QUIZ
} TUTOR_STATE;

static TUTOR_STATE t_state = STATE_SUBJECTS;
static int quiz_answered = 0;
static int quiz_correct = 0;

void ui_tutor_draw(void) {
    lcd_clear(COLOR_NAVY);
    lcd_draw_text(50, 20, "AI TUTOR", COLOR_LIGHTBLUE);

    if (t_state == STATE_SUBJECTS) {
        lcd_draw_text(50, 50, "Select Subject", COLOR_WHITE);
        lcd_draw_rect(50, 100, 150, 50, COLOR_CARD);
        lcd_draw_text(60, 115, "MATHEMATICS", COLOR_WHITE);
        
        lcd_draw_rect(50, 180, 150, 50, COLOR_CARD);
        lcd_draw_text(60, 195, "SCIENCE", COLOR_WHITE);

        lcd_draw_rect(500, 300, 150, 50, COLOR_ACCENT);
        lcd_draw_text(520, 315, "BACK", COLOR_WHITE);
    } else if (t_state == STATE_TOPICS) {
        lcd_draw_text(50, 50, "Select Topic", COLOR_WHITE);
        lcd_draw_rect(50, 100, 150, 50, COLOR_CARD);
        lcd_draw_text(60, 115, "ALGEBRA", COLOR_WHITE);

        lcd_draw_rect(500, 300, 150, 50, COLOR_ACCENT);
        lcd_draw_text(520, 315, "BACK", COLOR_WHITE);
    } else if (t_state == STATE_EXPLANATION) {
        lcd_draw_text(50, 50, "Explanation", COLOR_WHITE);
        lcd_draw_text(50, 100, ai_tutor_manager_get_explanation(0), COLOR_WHITE);

        lcd_draw_rect(50, 300, 100, 40, COLOR_CARD);
        lcd_draw_text(60, 310, "SIMPLE", COLOR_WHITE);

        lcd_draw_rect(170, 300, 100, 40, COLOR_CARD);
        lcd_draw_text(180, 310, "EXAMPLE", COLOR_WHITE);

        lcd_draw_rect(290, 300, 100, 40, COLOR_CARD);
        lcd_draw_text(300, 310, "QUIZ", COLOR_WHITE);

        lcd_draw_rect(500, 300, 150, 40, COLOR_ACCENT);
        lcd_draw_text(520, 310, "BACK", COLOR_WHITE);
    } else if (t_state == STATE_QUIZ) {
        lcd_draw_text(50, 50, "AI QUIZ", COLOR_WHITE);
        lcd_draw_text(50, 100, ai_tutor_manager_get_quiz_question(), COLOR_WHITE);

        // Options
        lcd_draw_rect(50, 180, 100, 40, COLOR_CARD);
        lcd_draw_text(60, 190, "[ 8 ]", COLOR_WHITE);
        lcd_draw_rect(170, 180, 100, 40, COLOR_CARD);
        lcd_draw_text(180, 190, "[ 10 ]", COLOR_WHITE);

        if (quiz_answered) {
            lcd_draw_text(50, 250, quiz_correct ? "CORRECT!" : "TRY AGAIN", COLOR_ACCENT);
        }

        lcd_draw_rect(500, 300, 150, 40, COLOR_ACCENT);
        lcd_draw_text(520, 310, "BACK", COLOR_WHITE);
    }
}

void ui_tutor_handle_touch(int x, int y) {
    if (t_state == STATE_SUBJECTS) {
        if (x >= 50 && x <= 200 && y >= 100 && y <= 150) {
            t_state = STATE_TOPICS;
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 350) {
            ui_set_screen(SCREEN_HOME);
        }
    } else if (t_state == STATE_TOPICS) {
        if (x >= 50 && x <= 200 && y >= 100 && y <= 150) {
            t_state = STATE_EXPLANATION;
            ai_tutor_manager_set_topic(1);
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 350) {
            t_state = STATE_SUBJECTS;
            ui_set_screen(SCREEN_TUTOR);
        }
    } else if (t_state == STATE_EXPLANATION) {
        if (x >= 290 && x <= 390 && y >= 300 && y <= 340) {
            t_state = STATE_QUIZ;
            quiz_answered = 0;
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 340) {
            t_state = STATE_TOPICS;
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 50 && x <= 150 && y >= 300 && y <= 340) {
            // SIMPLE
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 170 && x <= 270 && y >= 300 && y <= 340) {
            // EXAMPLE
            ui_set_screen(SCREEN_TUTOR);
        }
    } else if (t_state == STATE_QUIZ) {
        if (x >= 50 && x <= 150 && y >= 180 && y <= 220) {
            quiz_answered = 1;
            quiz_correct = 1;
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 170 && x <= 270 && y >= 180 && y <= 220) {
            quiz_answered = 1;
            quiz_correct = 0;
            ui_set_screen(SCREEN_TUTOR);
        } else if (x >= 500 && x <= 650 && y >= 300 && y <= 340) {
            t_state = STATE_EXPLANATION;
            ui_set_screen(SCREEN_TUTOR);
        }
    }
}
