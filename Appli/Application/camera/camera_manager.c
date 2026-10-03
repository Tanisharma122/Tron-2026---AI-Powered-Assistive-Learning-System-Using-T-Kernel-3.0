#include "../include/camera_manager.h"
#include <tm/tmonitor.h>

int camera_manager_init(void) {
    tm_printf((UB*)"CAMERA READY\n");
    return 0;
}

int camera_manager_start(void) {
    tm_printf((UB*)"CAMERA STARTED\n");
    return 0;
}

int camera_manager_stop(void) {
    tm_printf((UB*)"CAMERA STOPPED\n");
    return 0;
}

void* camera_manager_get_frame(void) {
    return NULL;
}
