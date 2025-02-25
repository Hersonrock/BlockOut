#ifndef SDLRENDER
#define SDLRENDER

#include <SDL3/SDL.h>
#include "array.h"

extern SDL_FPoint *grid_points;
void create_game_grid(uint32_t window_width, uint32_t window_height);

#endif SDLRENDER
