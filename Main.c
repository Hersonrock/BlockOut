#include "SDLApp.h"
#include "SDLTime.h"
#include "SDLInput.h"
#include "array.h"

SDL_FPoint *points = NULL;

void create_game_grid(uint32_t window_width, uint32_t window_height){

        //0.066f and 0.81 are the percentage of the screen where
        //the play screen is fixed on. I did this so it could be dynamic
        SDL_FPoint point = {
                .x = window_width * 0.066f,
                .y = 1
        };
        SDL_FPoint point1 = {
                .x = window_width * 0.066f,
                .y = window_height - 1 
        };
        SDL_FPoint point2 = {
                .x = window_width * 0.81f,
                .y =  window_height - 1
        };
        SDL_FPoint point3 = {
                .x = window_width * 0.81f,
                .y = 1 
        };
        
        array_push(points, point);
        array_push(points, point1);
        array_push(points, point2);
        array_push(points, point3);
}



void update(void){
        frame_time_control();
        create_game_grid(window_width, window_height);
}

void render(void){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderLines(renderer, points, array_length(points));

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
