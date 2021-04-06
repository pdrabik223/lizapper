//
// Created by studio25 on 30.03.2021.
//

#ifndef LIZAPPER_WINDOWS_CONSOLE_H
#define LIZAPPER_WINDOWS_CONSOLE_H

#include "game_engine_traits.h"

class windows_console : protected game_engine_traits {

public:
    windows_console() : game_engine_traits() {};

    windows_console(logic_engine &game) : game_engine_traits(game) {};

    void show_frame() override;

    void show_time() {};

    game_status gen_frame() override;

    void user_interaction() override;

    void start(unsigned &difficulty_level, size_t &x, size_t &y);

    void end(bool result);

    void set_engine(logic_engine &game) {
        delete engine_instation;
        engine_instation = &game;
    }

};


#endif //LIZAPPER_WINDOWS_CONSOLE_H
