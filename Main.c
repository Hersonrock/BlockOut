#include "SDLApp.h"
#include "SDLTime.h"
#include "SDLInput.h"

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
