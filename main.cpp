//
// Created by studio25 on 30.03.2021.
//


#include <cstdio>
#include <iostream>
#include "logic_engine.h"
#include "game_engine_traits.h"
#include "windows_console.h"

int main() {
    printf("hello world\n");
    cell pierwsza(true);
    pierwsza.set_flag(true);


    logic_engine cos (4, 4);
    cos.show();


    system("pause");
    return 0;
}
