#ifndef AI_TUTOR_MANAGER_H
#define AI_TUTOR_MANAGER_H

#include <tk/tkernel.h>

int ai_tutor_manager_init(void);
const char* ai_tutor_manager_get_explanation(int mode);
const char* ai_tutor_manager_get_quiz_question(void);
int ai_tutor_manager_check_quiz_answer(int answer_idx);
void ai_tutor_manager_set_topic(int topic_id);

#endif
