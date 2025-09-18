# Library Management System

A simple C++ library management system. You can manage books and users, borrow & return books, etc.

---

## Table of Contents

* [Overview](#overview)
* [Features](#features)
* [Structure](#structure)
* [Requirements](#requirements)
* [Building](#building)
* [Usage](#usage)
* [Future Improvements](#future-improvements)
* [License](#license)

---

## Overview

This project implements a basic Library Management System in **C++** using object-oriented design. It defines classes for `Book`, `User`, and `Library`, and includes a `main.cpp` for interaction. The build is managed via **CMake**.

It’s good for learning how to structure such systems, manage relationships between classes, and basic operations like add/remove/search of books/users, borrowing, returning etc.

---

## Features

* Add, remove, and search books
* Register users
* Borrow books
* Return books
* Basic console interface

---

## Structure

Here’s what the main files do:

| File                        | Purpose                                                                                               |
| --------------------------- | ----------------------------------------------------------------------------------------------------- |
| `Book.h` / `Book.cpp`       | Definition of the `Book` class: book metadata, status (available or borrowed), etc.                   |
| `User.h` / `User.cpp`       | Definition of `User` class: user details, maybe list of borrowed books etc.                           |
| `Library.h` / `Library.cpp` | Central class managing the collections of `Book` and `User`, handling borrow/return and interactions. |
| `main.cpp`                  | Entry point / user interface (console) to drive the system.                                           |
| `CMakeLists.txt`            | Build script for compiling & linking the source files.                                                |

---

## Requirements

* A C++ compiler supporting at least C++11 (or newer)
* CMake (version 3.10 or higher recommended)
* Build tools (e.g. Make, Ninja, MSVC, etc.)

---

## Building

### Linux

```bash
git clone https://github.com/diego-kopaladze/Library-Management-System.git
cd Library-Management-System
mkdir build
cd build
cmake ..
make
```

### macOS

Make sure you have **Xcode Command Line Tools** or **Homebrew GCC** installed.

```bash
git clone https://github.com/diego-kopaladze/Library-Management-System.git
cd Library-Management-System
mkdir build
cd build
cmake .. -G "Unix Makefiles"
make
```

### Windows

On Windows, you can build with **Visual Studio** or **MinGW**:

Using Visual Studio (CMake GUI or command line):

```powershell
git clone https://github.com/diego-kopaladze/Library-Management-System.git
cd Library-Management-System
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
```

Using MinGW:

```bash
git clone https://github.com/diego-kopaladze/Library-Management-System.git
cd Library-Management-System
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
```

After building, you’ll get an executable (e.g. `LibraryManagementSystem`).

---

## Usage

Run the executable (from `build` or wherever it is). The console prompts will allow you to:

* Perform book operations (add, remove, search)
* Manage user operations (register, view)
* Borrow a book for a user
* Return a book
* Exit the program

---

## Future Improvements

Here are some ideas if you want to expand:

* Persistent storage (save books/users between runs), e.g. file or database
* More detailed user permissions (admin vs normal user)
* GUI or web frontend
* More search/filter options (by author, genre, etc.)
* Improved error handling, input validation
* Unit tests / automated tests
* Multi-threading for simultaneous users

---

## License

You can add a license here (MIT, Apache, GPL, etc.).
