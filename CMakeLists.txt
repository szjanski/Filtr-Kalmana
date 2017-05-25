cmake_minimum_required(VERSION 3.7)
project(Kalman)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp KF.cpp)
add_executable(Kalman ${SOURCE_FILES})
