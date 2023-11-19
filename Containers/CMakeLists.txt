cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(serial serial.cpp)
set_target_properties(serial PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(list list.cpp)
set_target_properties(list PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
