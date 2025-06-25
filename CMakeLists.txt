cmake_minimum_required(VERSION 3.31)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagementSystem main.cpp
        Book.cpp
        Book.h
        Library.cpp
        Library.h
        User.cpp
        User.h)
