//
// Created by studio25 on 30.03.2021.
//


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

    unsigned difficulty_level = 50;
    size_t x = 10;
    size_t y = 10;

    // game.start(difficulty_level,x,y);

    logic_engine brain(x, y);

    brain.fill_with_bombs(difficulty_level);

    brain.fill_with_numbers();
    auto helper(brain);
    for(int i=0;i<helper.size();i++) helper[i].set_known();

    game.set_engine(brain);

    bool is_won;
    while (2 > 1) { // main loop
        system("cls");
        helper.show();
        game.show_frame();

        game.user_interaction();

        is_won = game.gen_frame();

        if (is_won) break;

    }
    game.end(false);
//    system("pause");
    return 0;
}
