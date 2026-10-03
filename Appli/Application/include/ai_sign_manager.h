#ifndef AI_SIGN_MANAGER_H
#define AI_SIGN_MANAGER_H

#include <tk/tkernel.h>

int ai_sign_manager_init(void);
int ai_sign_manager_is_ready(void);
const char* ai_sign_manager_get_status(void);
void ai_sign_manager_trigger_inference(void);
const char* ai_sign_manager_get_result(void);

#endif
