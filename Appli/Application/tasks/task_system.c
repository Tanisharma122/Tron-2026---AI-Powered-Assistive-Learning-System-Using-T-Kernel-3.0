#include "../include/task_system.h"
#include <tm/tmonitor.h>

void task_system(INT stacd, void *exinf) {
    while(1) {
        /* Monitor system status, heartbeat, etc. */
        tk_dly_tsk(1000);
    }
}
