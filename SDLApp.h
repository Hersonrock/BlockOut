#ifndef SDLinit
#define SDLinit
#include <SDL3/SDL.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

const char* title;
extern uint32_t window_width;
extern uint32_t window_height;
extern uint32_t* color_buffer;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* color_buffer_texture;

SDL_DisplayID* displays;

SDL_DisplayID* get_display_id(void);
bool get_display_dimensions(uint32_t *w, uint32_t *h);
bool initialize_window(void);
void setup(void);
void destroy_window(void);



#endif //SDLinit
