cmake_minimum_required(VERSION 3.27)
project(chapter2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/main.cpp)

add_executable(main ${SOURCES})