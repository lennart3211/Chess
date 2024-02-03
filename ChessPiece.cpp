//
// Created by Lennart Strempfer on 02/02/2024.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, ChessPieceType type, Texture2D *texture) : color(color), texture(texture) {
}

void ChessPiece::draw(float x, float y) {
    if (texture != nullptr) DrawTexture(*texture, x, y, WHITE);
}