#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <tk/tkernel.h>

int camera_manager_init(void);
int camera_manager_start(void);
int camera_manager_stop(void);
void* camera_manager_get_frame(void);

#endif
