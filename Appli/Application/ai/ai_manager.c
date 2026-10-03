#include "../include/ai_manager.h"
#include <tm/tmonitor.h>

int ai_manager_init(void) {
    tm_printf((UB*)"AI READY\n");
    return 0;
}

int ai_manager_is_ready(void) {
    return 0; /* 0 means not yet connected/ready */
}

const char* ai_manager_get_status(void) {
    return "AI MODEL NOT LOADED";
}

void ai_manager_trigger_inference(void) {
    tm_printf((UB*)"AI Inference Triggered\n");
}
