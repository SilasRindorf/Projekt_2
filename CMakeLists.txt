cmake_minimum_required(VERSION 3.16)
project(Projekt_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Projekt_2 main/main.c main/steps/Step_1.c "main/assist_functions/bitFunctions.c" main/steps/Step_2.c)