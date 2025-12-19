cmake_minimum_required(VERSION 4.0)
project(ProjektPP C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjektPP main.c
        dino.h
        file_manager.h
        utils.h
)
