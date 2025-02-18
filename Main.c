#include "SDLApp.h"

#define FPS 120 
#define FRAME_TARGET_TIME 1000/FPS
uint32_t previous_frame_time = 0;
bool is_running = false;

void frame_time_control(void){

        uint32_t time_to_wait = FRAME_TARGET_TIME -
                                (SDL_GetTicks() -
                                previous_frame_time);
        if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME){
                SDL_Delay(time_to_wait);
        }

        previous_frame_time = SDL_GetTicks();
}

void process_input(void) {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_EVENT_QUIT:
		is_running = false;
		break;
        case SDL_EVENT_KEY_DOWN:

                if (event.key.key == SDLK_ESCAPE) {
                        is_running = false;
                }
                break;

	default:
		break;
	}
}

void update(void){
        frame_time_control();
}

void render(void){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderPoint(renderer, 200, 200);

        SDL_RenderPresent(renderer);
}

void free_resources(void){
}
int main(int argc, char* argv[]) {
        is_running = initialize_window();
        setup();
        while(is_running){
                process_input();
                update();
                render();
        }
        destroy_window();
        free_resources();

	return true;
}
