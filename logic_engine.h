//
// Created by studio25 on 30.03.2021.
//

#ifndef LIZAPPER_LOGIC_ENGINE_H
#define LIZAPPER_LOGIC_ENGINE_H


#include <cstdio>
#include "cell.h"

class logic_engine {

    using size_t = unsigned;

public:
    logic_engine() = delete;

    logic_engine(size_t x, size_t y) : x_(x), y_(y) { board = new cell[size()]; };

    size_t size() const { return x_ * y_; }

    size_t get_x() const { return x_; }

    size_t get_y() const { return y_; }

    void set_x(size_t x) { x_ = x; }

    void set_y(size_t y) { y_ = y; }

    cell &operator[](size_t position) { return board[position]; }

    void fill_with_bombs(unsigned fill_in_percentage);

    void show();

protected:
    // ##   <- this board is 3x2
    // ##      x_ = 3 y_ = 2
    // ##      that's my notation deal with it

    size_t x_;
    size_t y_;
    cell *board;
};


#endif //LIZAPPER_LOGIC_ENGINE_H
