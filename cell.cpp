//
// Created by studio25 on 30.03.2021.
//

#include "cell.h"

cell::cell() { value = 0; }

cell::cell(bool bomb) {
    if (bomb) value = 1;
    else value = 0;
}

void cell::switch_flag() {
        if (is_flag_on()) value -= 64;
        else value += 64;
}

cell::operator char() {
    if (!is_known()) {
        if (is_flag_on()) return '^';
        return '#';
    } else {
        if (is_bomb()) return '*';
        if (bombs_nearby() == '0') return '.';
        return bombs_nearby() ;
    }
}

void cell::set_flag(bool flag) {
    if (flag) {
        if (is_flag_on()) return;
        else value += 64;
    } else {
        if (!is_flag_on()) return;
        else value -= 64;
    }
}

void cell::set_bomb(bool bomb) {
    if (bomb) {
        if (is_bomb()) return;
        else value += 1;
    } else {
        if (!is_bomb()) return;
        else value -= 1;
    }
}

void cell::set_known(bool discover) {
    if (discover) {
        if (is_known()) return;
        else value += 32;
    } else {
        if (!is_known()) return;
        else value -= 32;
    }
}

void cell::set_nearby(char how_many) {
    if(how_many>8) throw "to many bombs";
    value+=how_many<<1;

}
