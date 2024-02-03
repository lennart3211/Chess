//
// Created by Lennart Strempfer on 03/02/2024.
//

#ifndef CHESS_CHESSSQUARE_H
#define CHESS_CHESSSQUARE_H


#include <optional>
#include <memory>
#include "ChessPiece.h"

class ChessSquare {
public:

    ChessPiece *piece;
    Rectangle rectangle;
};


#endif //CHESS_CHESSSQUARE_H
