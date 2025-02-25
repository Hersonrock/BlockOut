#include "SDLApp.h"
#include "SDLTime.h"
#include "SDLInput.h"
#include "array.h"

SDL_FPoint *points = NULL;

SDL_FPoint point = {
        .x = 200,
        .y = 200
};

SDL_FPoint point1 = {
        .x = 400,
        .y = 400
};
SDL_FPoint point2 = {
        .x = 200,
        .y = 400
};
SDL_FPoint point3 = {
        .x = 400,
        .y = 200
};

void update(void){
        frame_time_control();
        array_push(points, point);
        array_push(points, point2);
        array_push(points, point1);
        array_push(points, point3);
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
