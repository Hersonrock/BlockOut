#include "SDLApp.h"
#include "SDLTime.h"
#include "SDLInput.h"
#include "SDLRender.h"
#include "array.h"

void update(void){
        frame_time_control();
        create_game_grid(window_width, window_height);
}

void render(void){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderLines(renderer, grid_points, array_length(grid_points));

        SDL_RenderPresent(renderer);
}

void free_resources(void){
        array_free(grid_points);
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
