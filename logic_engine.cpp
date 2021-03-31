//
// Created by studio25 on 30.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "logic_engine.h"


void logic_engine::fill_with_bombs(unsigned int fill_in_percentage) {

    for (int i = 0; i < size(); i++)
        if (rand() % 100 < fill_in_percentage)
            board[i].set_bomb(true);

}

void logic_engine::show() {
    for (int i = 0; i < get_x(); i++) {
        for (int j = 0; j < get_y(); j++)
            printf("%c ", (char) board[i * get_y() + j]);
        printf("\n");
    }
}

void logic_engine::iterate(size_t position_to_start) {


}

void logic_engine::fill_with_numbers() {
    for (unsigned i = 0; i < size(); i++) board[i].set_nearby(count_nearby(i));


}

char logic_engine::count_nearby(unsigned int position) {

    char counter = 0;
    unsigned px = position / y_;
    unsigned py = position % y_;

    // to prevent addressing wrong
    if (px > 0 && py > 0) if (board[position - 1 - y_].is_bomb()) ++counter;
    if (px > 0) if (board[position - y_].is_bomb()) ++counter;
    if (px > 0 && py < y_ - 1) if (board[position + 1 - y_].is_bomb()) ++counter;

    if (py > 0) if (board[position - 1].is_bomb()) ++counter;
    if (py < y_ - 1) if (board[position + 1].is_bomb()) ++counter;

    if (px < x_ - 1 && py > 0) if (board[position - 1 + y_].is_bomb()) ++counter;
    if (px < x_ - 1) if (board[position + y_].is_bomb()) ++counter;
    if (px < x_ - 1 && py < y_ - 1) if (board[position + 1 + y_].is_bomb()) ++counter;


    return counter;
}
