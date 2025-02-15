#include "SDLApp.h"


void process_input(void){
}

void update(void){
}

void render(void){
}

void free_resources(void){
}
int main(int argc, char* argv[]) {
        bool is_running = initialize_window();
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
