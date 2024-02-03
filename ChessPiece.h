//
// Created by Lennart Strempfer on 02/02/2024.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include <raylib.h>
#include <memory>

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
    ChessPiece(int color, ChessPieceType type, std::shared_ptr<Texture2D> texture);
    void draw(float x, float y);

    int color;
    ChessPieceType type;
    bool isSelected{};

private:
    std::shared_ptr<Texture2D> texture;
};


#endif //CHESS_CHESSPIECE_H
