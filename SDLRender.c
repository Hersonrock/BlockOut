#include "SDLRender.h"

SDL_FPoint *grid_points = NULL;

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
        
        array_push(grid_points, point);
        array_push(grid_points, point1);
        array_push(grid_points, point2);
        array_push(grid_points, point3);
}
