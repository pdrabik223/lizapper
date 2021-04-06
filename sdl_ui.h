//
// Created by studio25 on 06.04.2021.
//

#ifndef LIZAPPER_SDL_UI_H
#define LIZAPPER_SDL_UI_H

#include "game_engine_traits.h"
class sdl_ui: public  game_engine_traits{
public:
    sdl_ui():game_engine_traits(){};
    sdl_ui(logic_engine &game) : game_engine_traits(game) {};

    void show_frame() override;

    void show_time() override {};

    game_status gen_frame() override;

    void user_interaction() override;

    void start(unsigned &difficulty_level, size_t &x, size_t &y);

    void end(bool result);

    void set_engine(logic_engine &game) {
        delete engine_instation;
        engine_instation = &game;
    }

};


#endif //LIZAPPER_SDL_UI_H
