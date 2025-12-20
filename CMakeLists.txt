cmake_minimum_required(VERSION 4.0)
project(ProjektPP C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjektPP main.c
        file_manager.h
        utils.h
        dino.c
        dino.h
        file_manager.c
        utils.c
)
