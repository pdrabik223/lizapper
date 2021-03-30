//
// Created by studio25 on 30.03.2021.
//

#include <cstdlib>
#include "logic_engine.h"


void logic_engine::fill_with_bombs(unsigned int fill_in_percentage) {

    for (int i = 0; i < size(); i++)
        if (rand() % 100 > fill_in_percentage)
            board[i].set_bomb(true);

}

void logic_engine::show() {
    for (int i=0;i<get_x();i++) {
        for (int j = 0; j < get_y(); j++)
            printf("%c ", (char) board[i * get_y() + j]);
        printf("\n");
    }
}
