#include "../include/ai_tutor_manager.h"
#include <tm/tmonitor.h>

int ai_tutor_manager_init(void) {
    tm_printf((UB*)"AI TUTOR READY\n");
    return 0;
}

const char* ai_tutor_manager_get_explanation(int mode) {
    return "AI TUTOR NOT CONNECTED";
}

const char* ai_tutor_manager_get_quiz_question(void) {
    return "AI TUTOR NOT CONNECTED";
}

int ai_tutor_manager_check_quiz_answer(int answer_idx) {
    return 0;
}

void ai_tutor_manager_set_topic(int topic_id) {
    tm_printf((UB*)"Topic set to %d\n", topic_id);
}
