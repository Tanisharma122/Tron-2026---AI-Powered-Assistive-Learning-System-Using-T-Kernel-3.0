#include "../include/ai_sign_manager.h"
#include <tm/tmonitor.h>

static int recognition_triggered = 0;

int ai_sign_manager_init(void) {
    tm_printf((UB*)"AI SIGN READY\n");
    return 0;
}

int ai_sign_manager_is_ready(void) {
    return 0;
}

const char* ai_sign_manager_get_status(void) {
    if (recognition_triggered) {
        return "PROCESSING...";
    }
    return "AI MODEL NOT LOADED";
}

void ai_sign_manager_trigger_inference(void) {
    recognition_triggered = 1;
    tm_printf((UB*)"AI Sign Inference Triggered\n");
}

const char* ai_sign_manager_get_result(void) {
    if (recognition_triggered) {
        recognition_triggered = 0;
        return "HELLO"; // Mock result
    }
    return "";
}
