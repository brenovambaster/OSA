cmake_minimum_required(VERSION 3.23)
project(projeto2)

set(CMAKE_CXX_STANDARD 14)

add_executable(projeto2 main.cpp Movie.cpp Movie.h Buffer.cpp Buffer.h File.cpp File.h)
