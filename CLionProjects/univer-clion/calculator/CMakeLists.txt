cmake_minimum_required(VERSION 3.29)
project(calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator src/main.cpp
        src/Stack.h
        src/Command.h
        src/Calculator.cpp)
