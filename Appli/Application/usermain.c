#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include "include/lcd_manager.h"
#include "include/touch_manager.h"
#include "include/ai_manager.h"
#include "include/task_ui.h"
#include "include/task_vision.h"
#include "include/task_system.h"
#include "include/task_sign.h"
#include "include/camera_manager.h"
#include "include/ai_sign_manager.h"
#include "include/task_tutor.h"
#include "include/ai_tutor_manager.h"
#include "include/task_explore.h"
#include "include/ai_explore_manager.h"

LOCAL ID tskid_ui, tskid_vision, tskid_system, tskid_sign, tskid_tutor, tskid_explore;

LOCAL T_CTSK ctsk_ui = {
    .itskpri = 10,
    .stksz = 2048,
    .task = task_ui,
    .tskatr = TA_HLNG | TA_RNG3,
};

LOCAL T_CTSK ctsk_vision = {
    .itskpri = 11,
    .stksz = 2048,
    .task = task_vision,
    .tskatr = TA_HLNG | TA_RNG3,
};

LOCAL T_CTSK ctsk_system = {
    .itskpri = 12,
    .stksz = 1024,
    .task = task_system,
    .tskatr = TA_HLNG | TA_RNG3,
};

LOCAL T_CTSK ctsk_sign = {
    .itskpri = 13,
    .stksz = 2048,
    .task = task_sign,
    .tskatr = TA_HLNG | TA_RNG3,
};

LOCAL T_CTSK ctsk_tutor = {
    .itskpri = 14,
    .stksz = 2048,
    .task = task_tutor,
    .tskatr = TA_HLNG | TA_RNG3,
};

LOCAL T_CTSK ctsk_explore = {
    .itskpri = 15,
    .stksz = 2048,
    .task = task_explore,
    .tskatr = TA_HLNG | TA_RNG3,
};

EXPORT INT usermain(void) {
    tm_putstring((UB*)"Start User-main program.\n");

    if (lcd_manager_init() != 0) {
        tm_putstring((UB*)"LCD Init Failed\n");
    }
    if (touch_manager_init() != 0) {
        tm_putstring((UB*)"TOUCH Init Failed\n");
    }
    if (ai_manager_init() != 0) {
        tm_putstring((UB*)"AI Init Failed\n");
    }
    if (camera_manager_init() != 0) {
        tm_putstring((UB*)"CAMERA Init Failed\n");
    }
    if (ai_sign_manager_init() != 0) {
        tm_putstring((UB*)"AI SIGN Init Failed\n");
    }
    if (ai_tutor_manager_init() != 0) {
        tm_putstring((UB*)"AI TUTOR Init Failed\n");
    }
    if (ai_explore_manager_init() != 0) {
        tm_putstring((UB*)"AI EXPLORE Init Failed\n");
    }

    tm_putstring((UB*)"UI TASK STARTED\n");
    tskid_ui = tk_cre_tsk(&ctsk_ui);
    tk_sta_tsk(tskid_ui, 0);

    tm_putstring((UB*)"VISION TASK READY\n");
    tskid_vision = tk_cre_tsk(&ctsk_vision);
    tk_sta_tsk(tskid_vision, 0);

    tm_putstring((UB*)"SYSTEM TASK READY\n");
    tskid_system = tk_cre_tsk(&ctsk_system);
    tk_sta_tsk(tskid_system, 0);

    tm_putstring((UB*)"SIGN TASK READY\n");
    tskid_sign = tk_cre_tsk(&ctsk_sign);
    tk_sta_tsk(tskid_sign, 0);

    tm_putstring((UB*)"TUTOR TASK READY\n");
    tskid_tutor = tk_cre_tsk(&ctsk_tutor);
    tk_sta_tsk(tskid_tutor, 0);

    tm_putstring((UB*)"EXPLORE TASK READY\n");
    tskid_explore = tk_cre_tsk(&ctsk_explore);
    tk_sta_tsk(tskid_explore, 0);
    
    tk_slp_tsk(TMO_FEVR);
    return 0;
}
