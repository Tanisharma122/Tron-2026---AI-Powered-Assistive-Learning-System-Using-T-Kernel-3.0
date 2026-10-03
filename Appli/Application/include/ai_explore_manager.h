#ifndef AI_EXPLORE_MANAGER_H
#define AI_EXPLORE_MANAGER_H

#include <tk/tkernel.h>

int ai_explore_manager_init(void);
const char* ai_explore_manager_get_status(void);
const char* ai_explore_manager_get_answer(void);
void ai_explore_manager_ask_question(const char* question);
int ai_explore_manager_is_ready(void);

#endif
