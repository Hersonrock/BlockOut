#include "SDLInput.h"

bool is_running = false;

void process_input(void) {
	SDL_Event event;
        while(SDL_PollEvent(&event)){
                if(event.type == SDL_EVENT_QUIT){
                        is_running = false;
                        break;
                }
                
                if(event.type == SDL_EVENT_KEY_DOWN){
                        switch(event.key.key){
                                case SDLK_ESCAPE:
                                        is_running = false;
                                        break;
                                default:
                                        break;
                        }
                }

        }
        
}
