//
// Created by studio25 on 30.03.2021.
//
//
// todo make it count time
// todo documentation
// todo some cord class
// and push it as a new repo or smth
// todo like emm  stl_shiet

#include <cstdio>
#include <iostream>
#include <ctime>
#include <thread>
#include "logic_engine.h"
#include "game_engine_traits.h"
#include "windows_console.h"


int main() {
    srand(time(NULL));
    printf("hello world\n");
    windows_console game;

    unsigned difficulty_level = 7;
    size_t x = 6;
    size_t y = 6;

    // game.start(difficulty_level,x,y);

    logic_engine brain(x, y);

    brain.fill_with_bombs(difficulty_level);

    brain.fill_with_numbers();
    auto helper(brain);
    for(int i=0;i<helper.size();i++) helper[i].set_known();

    game.set_engine(brain);

    game_status current;
    while (2 > 1) { // main loop
        system("cls");
        helper.show();
        game.show_frame();

        game.user_interaction();

        current = game.gen_frame();

        if (current != on) break;

    }
    if(current == lost) game.end(false);
    else game.end(true);
    //    system("pause");
    return 0;
}
