cmake_minimum_required(VERSION 3.26)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp
        Chess.h
        Chess.cpp
        ChessPiece.h
        ChessPiece.cpp
        ChessSquare.h
        ChessSquare.cpp)

target_link_libraries(Chess raylib winmm)