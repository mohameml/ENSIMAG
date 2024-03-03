cmake_minimum_required(VERSION 3.3)
project(TP3_ibakuyua_lebitb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Darray.cpp
    src/Darray.h
    src/Dvector.cpp
    src/Dvector.h
    src/test_Dmatrix_bases.cpp
    src/test_Dmatrix_operators.cpp
    src/test_Dvector_bases.cpp
    src/test_Dvector_operators.cpp src/Dmatrix.cpp src/Dmatrix.h src/test_Dmatrix_Cholesky.cpp)

add_executable(TP3_ibakuyua_lebitb ${SOURCE_FILES})