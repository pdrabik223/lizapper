//
// Created by studio25 on 30.03.2021.
//

#ifndef LIZAPPER_GAME_ENGINE_TRAITS_H
#define LIZAPPER_GAME_ENGINE_TRAITS_H

#include "logic_engine.h"

enum game_status{
    won,
    lost,
    on
};

class game_engine_traits {

public:
    game_engine_traits() {
        cursor_position =0;
    engine_instation = nullptr;
    }
    game_engine_traits(logic_engine& game) {engine_instation = &game;}
    ~game_engine_traits(){delete engine_instation;}
protected:
    virtual void show_frame() = 0;
    virtual void show_time() = 0;
    virtual game_status gen_frame() = 0;
    virtual void user_interaction() = 0;
    virtual void start(unsigned &difficulty_level, size_t &x, size_t &y) = 0;
    virtual void end(bool) = 0;


    enum action{
        quit_game,
        new_game,
        flag,
        pop,
        do_nothing
    };

 logic_engine * engine_instation;
 size_t cursor_position;
 action player_action;
};


#endif //LIZAPPER_GAME_ENGINE_TRAITS_H
