#include "../include/task_ui.h"
#include "../include/ui_common.h"
#include "../include/ui_home.h"
#include "../include/ui_vision.h"
#include "../include/ui_sign.h"
#include "../include/ui_tutor.h"
#include "../include/ui_explore.h"
#include "../include/touch_manager.h"

void task_ui(INT stacd, void *exinf) {
    TouchEvent event;
    ui_set_screen(SCREEN_HOME);
    
    while(1) {
        if (touch_get_event(&event) == 0 && event.touched) {
            switch (current_screen) {
                case SCREEN_HOME:
                    ui_home_handle_touch(event.x, event.y);
                    break;
                case SCREEN_VISION:
                    ui_vision_handle_touch(event.x, event.y);
                    break;
                case SCREEN_SIGN:
                    ui_sign_handle_touch(event.x, event.y);
                    break;
                case SCREEN_TUTOR:
                    ui_tutor_handle_touch(event.x, event.y);
                    break;
                case SCREEN_EXPLORE:
                    ui_explore_handle_touch(event.x, event.y);
                    break;
                case SCREEN_COMING_SOON:
                    if (event.x >= 300 && event.x <= 500 && event.y >= 300 && event.y <= 350) {
                        ui_set_screen(SCREEN_HOME);
                    }
                    break;
            }
        }
        tk_dly_tsk(50);
    }
}
