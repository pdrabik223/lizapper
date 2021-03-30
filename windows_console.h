//
// Created by studio25 on 30.03.2021.
//

#ifndef LIZAPPER_WINDOWS_CONSOLE_H
#define LIZAPPER_WINDOWS_CONSOLE_H

#include "game_engine_traits.h"

class windows_console : protected game_engine_traits {

public:
    windows_console(logic_engine &game) : game_engine_traits(game) {};

    void show_frame();

    void show_time();

    bool gen_frame();

    char user_interaction();


};


#endif //LIZAPPER_WINDOWS_CONSOLE_H
