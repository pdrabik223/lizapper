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


    logic_engine cos(6, 6);

    cos.fill_with_bombs(5);
    cos.fill_with_numbers();

    for (int i = 0; i < cos.size(); i++)
        cos[i].set_known(true);


    cos.show();
    std::cout<<std::endl;

    for (int i = 0; i < cos.size(); i++)
        cos[i].set_known(false);

    cos.iterate(6*6/2+1);
    cos.show();

    system("pause");
    return 0;
}
