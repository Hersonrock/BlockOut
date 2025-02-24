#ifndef SDLTIME
#define SDLTIME

#include <stdint.h>
#include <stdio.h>
#define FPS 120 
#define FRAME_TIME_TARGET (1000.0 / FPS)

void frame_time_control(void);

#endif //SDLTIME
