#include "SDLApp.h"
#include "SDLTime.h"

bool is_running = false;

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
