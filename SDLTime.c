#include "SDLTime.h"


uint64_t elapsed_time = 0;

void frame_time_control(void){

        int64_t time_to_wait = FRAME_TIME_TARGET -
                                (SDL_GetTicks() - elapsed_time);

        if(time_to_wait > 0){
                SDL_Delay(time_to_wait);
        }

        elapsed_time = SDL_GetTicks();
}
