//
// Created by Lennart Strempfer on 02/02/2024.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include <raylib.h>
#include <vector>
#include "ChessPiece.h"

typedef struct {
    Texture2D b_pawn;
    Texture2D w_pawn;
    Texture2D b_rook;
    Texture2D w_rook;
    Texture2D b_knight;
    Texture2D w_knight;
    Texture2D b_bishop;
    Texture2D w_bishop;
    Texture2D b_queen;
    Texture2D w_queen;
    Texture2D b_king;
    Texture2D w_king;
} Textures;

class Chess {
public:
    Chess();
    ~Chess();
    void play();

private:
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;
    const int NUM_SQUARES = 8;
    const float SQUARE_SIZE = (float)SCREEN_HEIGHT / (float) NUM_SQUARES;

    bool running;

    Rectangle board[8][8];
    std::vector<std::vector<int>> pieceMap;
    Textures textures;
    Vector2 mousePosition;
    std::vector<int> selectedSquare;

    std::vector<ChessPiece> b_pieces;
    std::vector<ChessPiece> w_pieces;

    void initBoard();
    void initPieces();
    void update();
    void draw();
    bool isValidMove(std::vector<int> pos, ChessPieceType type);
    bool checkPath(std::vector<int> pos);
};


#endif //CHESS_CHESS_H
