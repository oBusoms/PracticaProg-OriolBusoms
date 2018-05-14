cmake_minimum_required(VERSION 3.8)
project(PracticaProg)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c baralla.c Bot.c Crupier.c Misc.c Partida.c pila.c Player.c Ronda.c)
set(HEADER_FILES baralla.h Bot.h Crupier.h Misc.h Partida.h pila.h Player.h Ronda.h)
add_executable(PracticaProg ${SOURCE_FILES})