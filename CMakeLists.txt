cmake_minimum_required(VERSION 3.20)
project(stage1)

set(CMAKE_CXX_STANDARD 14)

add_executable(stage1 server.cpp)
add_executable(client client.cpp strtonum.cpp commands.h)
