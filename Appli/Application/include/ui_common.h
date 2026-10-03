#ifndef UI_COMMON_H
#define UI_COMMON_H

#include <tk/tkernel.h>

typedef enum {
    SCREEN_HOME,
    SCREEN_VISION,
    SCREEN_SIGN,
    SCREEN_TUTOR,
    SCREEN_EXPLORE,
    SCREEN_COMING_SOON
} UI_SCREEN_STATE;

extern UI_SCREEN_STATE current_screen;
void ui_set_screen(UI_SCREEN_STATE new_screen);

#endif
