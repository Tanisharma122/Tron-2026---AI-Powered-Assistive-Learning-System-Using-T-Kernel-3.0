#include "../include/touch_manager.h"
#include <tm/tmonitor.h>

int touch_manager_init(void) {
    tm_printf((UB*)"TOUCH READY\n");
    return 0;
}

int touch_get_event(TouchEvent *event) {
    /* Mock touch event polling */
    event->touched = 0;
    return 0;
}
