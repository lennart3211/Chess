//
// Created by Lennart Strempfer on 02/02/2024.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, ChessPieceType type, Texture2D *texture, Vector2 position_f) : color(color), texture(texture), position_f(position_f) {
    isInGame = true;
}

void ChessPiece::draw() {
    if (texture != nullptr && isInGame) DrawTexture(*texture, position_f.x, position_f.y, WHITE);
}