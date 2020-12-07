cmake_minimum_required(VERSION 3.5)

project(AVL_T LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AVL_T main.cpp _AvlTree_H.h _AvlTree_H.cpp)
