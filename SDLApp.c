#include "SDLApp.h"

const char *title = "BlockOut";
uint32_t window_width = 0;
uint32_t window_height = 0;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_DisplayID* get_display_id(void){
        int num_displays = 0;
        SDL_DisplayID *displays = SDL_GetDisplays(&num_displays);
        if(num_displays < 1){
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "No Displays Found: %s\n",
                             SDL_GetError());
                return NULL;
        }
#ifdef DEBUG
        SDL_Log("Found %d display(s)\n", num_displays);
        for(int i = 0; i < num_displays; i++){
                SDL_Log("Display[%d] = %d\n", i, displays[i]);
        }
#endif //DEBUG
        
        return displays;
}


bool get_display_dimensions(uint32_t *w, uint32_t *h){
        
        SDL_DisplayID *displays = get_display_id();
        if(!displays) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Failed to get DisplayID: %s\n",
                             SDL_GetError());
                return false;
        }

        //Gets the first display listed
        SDL_DisplayMode *display_mode = SDL_GetCurrentDisplayMode(displays[0]);

        if(!display_mode){
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Failed to get current display mode: %s\n",
                             SDL_GetError());

                SDL_free(displays);
                return false;
        }

        *w = display_mode->w;
        *h = display_mode->h;

        SDL_free(displays);
        return true;
}

bool initialize_window(void){
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Failed to initialize SDL: %s\n",
                             SDL_GetError());
		return false;
	}

        if(!get_display_dimensions(&window_width, &window_height)){

                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Couldn't get windows dimensions: %s\n",
                             SDL_GetError());
                return false;
        }

        if(!SDL_CreateWindowAndRenderer(title,
                                        window_width,
                                        window_height,
                                        SDL_WINDOW_RESIZABLE,
                                        &window,
                                        &renderer)){
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Couldn't create window or renderer: %s\n",
                             SDL_GetError());
                return false;
        }

        return true;

}

void destroy_window(void){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}

void setup(){
}
