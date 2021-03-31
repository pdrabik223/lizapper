//
// Created by studio25 on 30.03.2021.
//


#include <cstdio>
#include <iostream>
#include <ctime>
#include "logic_engine.h"
#include "game_engine_traits.h"
#include "windows_console.h"

int main() {
    srand(time(NULL));
    printf("hello world\n");
    cell pierwsza(true);
    pierwsza.set_known(true);
    pierwsza.set_nearby(4);
    printf("%c \n\n\n", pierwsza.bombs_nearby());

    logic_engine cos(4, 4);
    cos.show();

    cos.fill_with_bombs(25);
    cos.fill_with_numbers();
    for(int i=0;i<cos.size();i++)
        cos[i].set_known(true);

    cos.show();

    system("pause");
    return 0;
}
