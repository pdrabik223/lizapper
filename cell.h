//
// Created by studio25 on 30.03.2021.
//

// cell holds value of a square,
//

#ifndef LIZAPPER_CELL_H
#define LIZAPPER_CELL_H


class cell {
public:
    cell();

    explicit cell(bool bomb);

    bool is_flag_on() const { return value & 64; }

    void switch_flag();

    void set_flag(bool flag);

    bool is_bomb() const { return value & 1; }

    void set_bomb(bool bomb);

    bool is_known() const { return value & 32; }

    void set_known(bool discover);

    char bombs_nearby() const { return (char)(((value & 30)>>1)+48); }

    void set_nearby(char how_many);

    explicit operator char();

protected:
    char value;


    // it's an idea, I thing it's cool, but it's early
/*
one cell can be in few stages
 1.  -safe / bomb

 2.  -known / unknown

 3.  -how many bombs are nearby - can have value from 1 - 8
        therefore it needs 4 bytes of space

 4.  -flagged / un_flagged


 lets say
 ________ <- 8 bits of space
  4233331


 for example:

 00010000
 it means it's safe, and around are 8 bombs
          it's also unknown

*/

};


#endif //LIZAPPER_CELL_H
