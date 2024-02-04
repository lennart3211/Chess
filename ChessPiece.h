//
// Created by Lennart Strempfer on 02/02/2024.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include <raylib.h>

enum ChessPieceType {
    PAWN = 1,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

class ChessPiece {
public:
    ChessPiece(int color, ChessPieceType type, Texture2D *texture);
    void draw(float x, float y);

    int color;
    ChessPieceType type;
    bool isSelected{};

private:
    Texture2D *texture;
};


#endif //CHESS_CHESSPIECE_H
