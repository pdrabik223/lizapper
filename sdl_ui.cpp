//
// Created by studio25 on 06.04.2021.
//

#include "sdl_ui.h"

void sdl_ui::show_frame() {
// if screen exists update
// if not create one and update

    if (window == nullptr) { // create one

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        } else {
            // set windows sizes
            window_height = engine_instation->get_x() * 30;
            window_width = engine_instation->get_y() * 30;
            //Create window

            window = SDL_CreateWindow("Lizzaper~_~", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width,
                                      window_height, SDL_WINDOW_SHOWN);
            if (window == NULL) {
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            } else {
                //Get window surface
                screen_surface = SDL_GetWindowSurface(window);

                //Fill the surface white
                SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0x00, 0xFF, 0xFF));


            }
        }

    }
    SDL_UpdateWindowSurface(window);
//Wait two seconds
   // SDL_Delay(5000);
}

void sdl_ui::end(bool result) {


// todo image of sorts like nice!
// but what with mayby background image will change
// now that will be cool


    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}

void sdl_ui::start(unsigned int &difficulty_level, size_t &x, size_t &y) {
// for now it's stolen from window console


}

void sdl_ui::user_interaction() {
//in future mayby mouse
// i'm very open to the idea
// but my idea lies upon get_mouse_position function from sdl
// the problem is that i dit know if such a function even ezyst's
//


}

game_status sdl_ui::gen_frame() {

    //so this will be hard, like hell
    return on;
}
