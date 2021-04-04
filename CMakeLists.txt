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

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

