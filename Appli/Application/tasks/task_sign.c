#include "../include/task_sign.h"
#include "../include/camera_manager.h"
#include "../include/ai_sign_manager.h"
#include <tm/tmonitor.h>

void task_sign(INT stacd, void *exinf) {
    while(1) {
        /* Process frames from camera and feed to AI if triggered */
        tk_dly_tsk(100);
    }
}
