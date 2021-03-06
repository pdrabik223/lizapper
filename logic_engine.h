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

    logic_engine(size_t x, size_t y) : x_(x), y_(y) {

        board = new cell *[x];

        for (int i = 0; i < x; i++) {
            board[i] = new cell[y];
            for (int j = 0; j < y; j++) {
                board[i][j] = cell(false);
            }
        }
    };

    logic_engine(logic_engine &other) {
        x_ = other.x_;
        y_ = other.y_;

        board = new cell *[x_];

        for (int i = 0; i < x_; i++) {
            board[i] = new cell[y_];
            for (int j = 0; j < y_; j++) {
                board[i][j] = other.board[i][j];
            }
        }

    }

    logic_engine &operator=(logic_engine &other) {
        if (this == &other) return *this;
        x_ = other.x_;
        y_ = other.y_;

        board = new cell *[x_];

        for (int i = 0; i < x_; i++) {
            board[i] = new cell[y_];
            for (int j = 0; j < y_; j++) {
                board[i][j] = other.board[i][j];
            }
        }
        return *this;
    }

    bool is_the_game_won() {
        for (int i = 0; i < x_; i++) {
            for (int j = 0; j < y_; j++)
                if (!board[i][j].is_bomb() && !board[i][j].is_known()) return false;
        }
        return true;
    }


    size_t size() const { return x_ * y_; }

    size_t get_x() const { return x_; }

    size_t get_y() const { return y_; }

    void set_x(size_t x) { x_ = x; }

    void set_y(size_t y) { y_ = y; }

    cell &get(size_t x, size_t y) { return board[x][y]; }

    cell &operator[](size_t pos) {
        return board[pos / y_][pos % y_];
    }

    void show();

    void iterate(size_t position_to_start);

    void fill_with_bombs(unsigned fill_in_percentage);

    void fill_with_numbers();

    char count_nearby(unsigned int position);

    ~logic_engine() {
        for (int i = 0; i < x_; i++) {
            delete[] board[i];

        }
        delete[] board;
    }


protected:

    // ##   <- this board is 3x2
    // ##      x_ = 3 y_ = 2
    // ##      that's my notation deal with it

    size_t x_;
    size_t y_;
    cell **board;


};


#endif //LIZAPPER_LOGIC_ENGINE_H
