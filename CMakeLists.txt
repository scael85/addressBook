cmake_minimum_required(VERSION 3.15)
project(addressBook C)

set(CMAKE_C_STANDARD 90)

add_executable(addressBook main.c phoneBook.c phoneBook.h)