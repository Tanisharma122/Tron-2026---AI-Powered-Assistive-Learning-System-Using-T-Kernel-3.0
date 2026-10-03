#ifndef TOUCH_MANAGER_H
#define TOUCH_MANAGER_H

#include <tk/tkernel.h>

typedef struct {
    int x;
    int y;
    int touched;
} TouchEvent;

int touch_manager_init(void);
int touch_get_event(TouchEvent *event);

#endif
