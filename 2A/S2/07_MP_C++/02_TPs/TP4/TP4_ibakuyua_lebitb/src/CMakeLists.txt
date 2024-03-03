cmake_minimum_required(VERSION 3.3)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Makefile Point.tpp Point.h test_Point.cpp Triangle.tpp Triangle.h test_Triangle.cpp Maillage.tpp Maillage.h test_Maillage.cpp test_Analyse.cpp)

add_executable(src ${SOURCE_FILES})