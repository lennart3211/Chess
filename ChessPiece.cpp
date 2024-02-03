//
// Created by Lennart Strempfer on 02/02/2024.
//

#include <memory>
#include <utility>
#include "ChessPiece.h"

ChessPiece::ChessPiece(int color, ChessPieceType type, std::shared_ptr<Texture2D> texture) : color(color), texture(std::move(texture)) {
    isSelected = false;
}

void ChessPiece::draw(float x, float y) {
    if (texture != nullptr) DrawTexture(*texture, x, y, WHITE);
}