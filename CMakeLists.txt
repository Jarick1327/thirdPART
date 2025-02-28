cmake_minimum_required(VERSION 3.16)

project(week3_qt)

find_package(SDL3 CONFIG REQUIRED)

add_executable(week3_qt main.cpp)

target_link_libraries(week3_qt PRIVATE SDL3::SDL3)
