cmake_minimum_required(VERSION 3.31)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManagementSystem main.cpp
        Book/Book.cpp
        Book/Book.h
        Library/Library.cpp
        Library/Library.h
        User/User.cpp
        User/User.h
        Menu/menu.hpp)
