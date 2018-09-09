cmake_minimum_required(VERSION 3.12)
project(tree C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_INSTALL_PREFIX /usr/local/bin)

add_executable(tree src/tree.c src/formatter.c src/formatter.h src/boolean.h)

install(TARGETS tree DESTINATION ${CMAKE_INSTALL_PREFIX})
