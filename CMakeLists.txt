cmake_minimum_required(VERSION 3.23)
project(Movie)

set(CMAKE_CXX_STANDARD 14)

add_executable(Movie main.cpp Movie.cpp Movie.h Movies.cpp Movies.h)
