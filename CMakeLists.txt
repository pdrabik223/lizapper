cmake_minimum_required(VERSION 3.17)
project(lizapper)

set(CMAKE_CXX_STANDARD 14)

add_executable(lizapper
        main.cpp
        cell.h
        cell.cpp
        game_engine_traits.h
        game_engine_traits.cpp
        windows_console.h
        windows_console.cpp
        logic_engine.h
        logic_engine.cpp)
