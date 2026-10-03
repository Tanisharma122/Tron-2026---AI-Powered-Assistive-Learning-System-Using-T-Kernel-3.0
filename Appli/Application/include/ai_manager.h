#ifndef AI_MANAGER_H
#define AI_MANAGER_H

#include <tk/tkernel.h>

int ai_manager_init(void);
int ai_manager_is_ready(void);
const char* ai_manager_get_status(void);
void ai_manager_trigger_inference(void);

#endif
