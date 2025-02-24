#include "SDLInput.h"

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
