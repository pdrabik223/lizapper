//
// Created by studio25 on 30.03.2021.
//

#ifndef LIZAPPER_GAME_ENGINE_TRAITS_H
#define LIZAPPER_GAME_ENGINE_TRAITS_H

#include "logic_engine.h"
class game_engine_traits {

public:
    game_engine_traits() = delete;
    game_engine_traits(logic_engine& game) {engine_instation = &game;}
    ~game_engine_traits(){delete engine_instation;}
protected:
    virtual void show_frame() = 0;
    virtual void show_time() = 0;
    virtual bool gen_frame() = 0;
    virtual char user_interaction() = 0;

 logic_engine * engine_instation;


};


#endif //LIZAPPER_GAME_ENGINE_TRAITS_H
