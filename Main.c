#include "stdio.h"
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)) {
		fprintf(stderr, "Failed to Initialize SDL\n");
		return false;
	}
	printf("Hello, World\n");
	return true;
}