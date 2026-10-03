#include "../include/task_vision.h"
#include <tm/tmonitor.h>

void task_vision(INT stacd, void *exinf) {
    while(1) {
        /* Handle camera processing / AI status updates */
        tk_dly_tsk(100);
    }
}
