#include "../include/ai_explore_manager.h"
#include <tm/tmonitor.h>

static int explore_processing = 0;

int ai_explore_manager_init(void) {
    tm_printf((UB*)"AI EXPLORE READY\n");
    return 0;
}

const char* ai_explore_manager_get_status(void) {
    if (explore_processing) {
        return "PROCESSING...";
    }
    return "AI SERVICE NOT CONNECTED";
}

const char* ai_explore_manager_get_answer(void) {
    return "AI SERVICE NOT CONNECTED";
}

void ai_explore_manager_ask_question(const char* question) {
    explore_processing = 1;
    tm_printf((UB*)"Asking AI: %s\n", question);
}

int ai_explore_manager_is_ready(void) {
    return 0; // Not ready/connected
}
