//
// Created by studio25 on 30.03.2021.
//

#include <iostream>
#include <conio.h>
#include "windows_console.h"

void windows_console::show_frame() {
    for (int i = 0; i < engine_instation->get_x(); i++) {
        for (int j = 0; j < engine_instation->get_y(); j++)
            if (i * engine_instation->get_y() + j == cursor_position)printf("%c<", (char) engine_instation->get(i, j));
            else printf("%c ", (char) engine_instation->get(i, j));
        printf("\n");
    }

}

void windows_console::user_interaction() {
    char key;

    while (2 > 1) {
        key = getch();
        switch (key) {
            case 'a':
                if (cursor_position % engine_instation->get_y() > 0)
                    --cursor_position;
                player_action = do_nothing;
                return;
            case 'd':
                if (cursor_position % engine_instation->get_y() < engine_instation->get_y() - 1)
                    ++cursor_position;
                player_action = do_nothing;
                return;

            case 'w':
                if (cursor_position / engine_instation->get_y() >0)
                    cursor_position -= engine_instation->get_y();
                player_action = do_nothing;
                return;
            case 's':
                if (cursor_position / engine_instation->get_y() <  engine_instation->get_x()-1)
                    cursor_position += engine_instation->get_y();
                player_action = do_nothing;
                return;
            case 'e':
                player_action = pop;
                return;
            case 'q':
                player_action = quit_game;
                return;
            case 'f':
                player_action = flag;
                return;
            case 'n':
                player_action = new_game;
                return;

        }


    }


}

bool windows_console::gen_frame() {
    if (player_action == do_nothing) return false;
    if (player_action == flag) {

        engine_instation->operator[](cursor_position).switch_flag();
    } else if (engine_instation->operator[](cursor_position).is_bomb()) return true;
    engine_instation->iterate(cursor_position);

    return false;

}

void windows_console::start(unsigned &difficulty_level, size_t &x, size_t &y) {


    printf("welcome to lizzaper\n "
           "it's a sapper only made by lizzy...  kinda\n"
           "please set in difficulty level a percentage how hard should the game be\n"
           "difficulty level: \n");
    std::cin >> difficulty_level;
    printf("%\n now size of the board\nx: ");
    std::cin >> x;
    printf("\ny: ");
    std::cin >> y;


}

void windows_console::end(bool result) {
    if (result) {
        printf("job well done! now go fuck your self\n ");
        system("pause");

    } else {
        printf("ha! u suck!\n");
        system("pause");

    }

}


