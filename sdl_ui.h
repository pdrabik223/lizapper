//
// Created by studio25 on 06.04.2021.
//

#ifndef LIZAPPER_SDL_UI_H
#define LIZAPPER_SDL_UI_H

#include "game_engine_traits.h"
#include <SDL2/SDL.h>
class sdl_ui: public  game_engine_traits{
public:
    sdl_ui():game_engine_traits(){
        window= nullptr;
        screen_surface = nullptr;
    };
    sdl_ui(logic_engine &game) : game_engine_traits(game) {
        window_height = engine_instation->get_x()*30;
        window_width = engine_instation->get_y()*30;

    };

    void show_frame() override;

    void show_time() override {};

    game_status gen_frame() override;

    void user_interaction() override;

    void start(unsigned &difficulty_level, size_t &x, size_t &y) override;

    void end(bool result) override;

    void set_engine(logic_engine &game) {
        delete engine_instation;
        engine_instation = &game;
    }

private:
    size_t window_height; // x
    size_t window_width;  // y
    SDL_Window* window;
    SDL_Surface* screen_surface; // this will be jpg, just for kiks

};


#endif //LIZAPPER_SDL_UI_H
