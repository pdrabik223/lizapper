//
// Created by studio25 on 30.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "logic_engine.h"


void logic_engine::fill_with_bombs(unsigned int fill_in_percentage) {

    for (int i = 0; i < size(); i++)
        if (rand() % 100 < fill_in_percentage)
            operator[](i).set_bomb(true);

}

void logic_engine::show() {
    for (int i = 0; i < get_x(); i++) {
        for (int j = 0; j < get_y(); j++)
            printf("%c ", (char) board[i][j]);
        printf("\n");
    }
}

void logic_engine::iterate(size_t position_to_start) {
    unsigned px = position_to_start / y_;
    unsigned py = position_to_start % y_;

    if (board[px][py].is_bomb()) return; // requ ends here
    board[px][py].set_known(true);

    if (board[px][py].bombs_nearby() != 0) return;

    // to prevent SIEGSEGV
    // but it doesn't work

    if (px > 0 && py > 0) iterate(position_to_start - 1 - y_);

    if (px > 0) iterate(position_to_start - y_);

    if (px > 0 && py < y_ - 1) iterate(position_to_start + 1 - y_);

    if (py > 0) iterate(position_to_start - 1);

    if (py < y_ - 1) iterate(position_to_start + 1);

    if (px < x_ - 1 && py > 0) iterate(position_to_start - 1 + y_);

    if (px < x_ - 1) iterate(position_to_start + y_);

    if (px < x_ - 1 && py < y_ - 1) iterate(position_to_start + 1 + y_);


}

void logic_engine::fill_with_numbers() {
    for (unsigned i = 0; i < size(); i++) operator[](i).set_nearby(count_nearby(i));


}

char logic_engine::count_nearby(unsigned int position) {

    char counter = 0;
    unsigned px = position / y_;
    unsigned py = position % y_;
    if (board[px][py].is_bomb()) return 0;

    // to prevent addressing wrong
    if (px > 0 && py > 0) if (board[px - 1][py - 1].is_bomb()) ++counter;
    if (px > 0) if (board[px - 1][py].is_bomb()) ++counter;
    if (px > 0 && py < y_ - 1) if (board[px - 1][py + 1].is_bomb()) ++counter;

    if (py > 0) if (board[px][py - 1].is_bomb()) ++counter;
    if (py < y_ - 1) if (board[px][py + 1].is_bomb()) ++counter;

    if (px < x_ - 1 && py > 0) if (board[px + 1][py - 1].is_bomb()) ++counter;
    if (px < x_ - 1) if (board[px + 1][py].is_bomb()) ++counter;
    if (px < x_ - 1 && py < y_ - 1) if (board[px + 1][py + 1].is_bomb()) ++counter;


    return counter;
}
