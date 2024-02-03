//
// Created by Lennart Strempfer on 02/02/2024.
//

#include <cmath>
#include "Chess.h"

Chess::Chess() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chess");
    SetTargetFPS(60);
    initBoard();
    initPieces();
    selectedSquare = {4, 4}; // Needs to have value at all times
}

Chess::~Chess() {

    // Unload Piece Textures
    UnloadTexture(textures.w_pawn);
    UnloadTexture(textures.b_pawn);
    UnloadTexture(textures.b_rook);
    UnloadTexture(textures.w_rook);
    UnloadTexture(textures.b_knight);
    UnloadTexture(textures.w_knight);
    UnloadTexture(textures.b_bishop);
    UnloadTexture(textures.w_bishop);
    UnloadTexture(textures.b_queen);
    UnloadTexture(textures.w_queen);
    UnloadTexture(textures.b_king);
    UnloadTexture(textures.b_king);
}

void Chess::initBoard() {
    for (int i = 0; i < NUM_SQUARES; ++i) {
        for (int j = 0; j < NUM_SQUARES; ++j) {
            board[i][j] = (Rectangle){ i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE };
        }
    }
}

void Chess::initPieces() {

    // Initialize Piece Map
    pieceMap = {
            { 2,  3,  4,  5,  6,  4,  3,  2},
            { 1,  1,  1,  1,  1,  1,  1,  1},
            { 0,  0,  0,  0,  0,  0,  0,  0},
            { 0,  0,  0,  0,  0,  0,  0,  0},
            { 0,  0,  0,  0,  0,  0,  0,  0},
            { 0,  0,  0,  0,  0,  0,  0,  0},
            { 1,  1,  1,  1,  1,  1,  1,  1},
            { 2,  3,  4,  5,  6,  4,  3,  2}
    };

    // Load Textures
    textures = {
            LoadTexture("../resources/textures/b_pawn_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_pawn_png_shadow_128px.png"),
            LoadTexture("../resources/textures/b_rook_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_rook_png_shadow_128px.png"),
            LoadTexture("../resources/textures/b_knight_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_knight_png_shadow_128px.png"),
            LoadTexture("../resources/textures/b_bishop_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_bishop_png_shadow_128px.png"),
            LoadTexture("../resources/textures/b_queen_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_queen_png_shadow_128px.png"),
            LoadTexture("../resources/textures/b_king_png_shadow_128px.png"),
            LoadTexture("../resources/textures/w_king_png_shadow_128px.png")
    };

    // Pawns
    for (int i = 0; i < 8; ++i) {
        b_pieces.emplace_back(1, PAWN, &textures.b_pawn, (Vector2){i*SQUARE_SIZE, SQUARE_SIZE });
        w_pieces.emplace_back(0, PAWN, &textures.w_pawn, (Vector2){i*SQUARE_SIZE, 6*SQUARE_SIZE });
    }

    // Rooks
    b_pieces.emplace_back(1, ROOK, &textures.b_rook, (Vector2){0,             0 });
    w_pieces.emplace_back(0, ROOK, &textures.w_rook, (Vector2){0,             7*SQUARE_SIZE });
    b_pieces.emplace_back(1, ROOK, &textures.b_rook, (Vector2){7*SQUARE_SIZE, 0 });
    w_pieces.emplace_back(0, ROOK, &textures.w_rook, (Vector2){7*SQUARE_SIZE, 7*SQUARE_SIZE });

    // Knights
    b_pieces.emplace_back(1, KNIGHT, &textures.b_knight, (Vector2){1*SQUARE_SIZE, 0 });
    w_pieces.emplace_back(0, KNIGHT, &textures.w_knight, (Vector2){1*SQUARE_SIZE, 7*SQUARE_SIZE });
    b_pieces.emplace_back(1, KNIGHT, &textures.b_knight, (Vector2){6*SQUARE_SIZE, 0 });
    w_pieces.emplace_back(0, KNIGHT, &textures.w_knight, (Vector2){6*SQUARE_SIZE, 7*SQUARE_SIZE });

    // Bishops
    b_pieces.emplace_back(1, BISHOP, &textures.b_bishop, (Vector2){2*SQUARE_SIZE, 0 });
    w_pieces.emplace_back(0, BISHOP, &textures.w_bishop, (Vector2){2*SQUARE_SIZE, 7*SQUARE_SIZE });
    b_pieces.emplace_back(1, BISHOP, &textures.b_bishop, (Vector2){5*SQUARE_SIZE, 0 });
    w_pieces.emplace_back(0, BISHOP, &textures.w_bishop, (Vector2){5*SQUARE_SIZE, 7*SQUARE_SIZE });

    // Queens
    b_pieces.emplace_back(1, QUEEN, &textures.b_queen, (Vector2){4*SQUARE_SIZE, 0});
    w_pieces.emplace_back(0, QUEEN, &textures.w_queen, (Vector2){3*SQUARE_SIZE, 7*SQUARE_SIZE});

    // Kings
    b_pieces.emplace_back(1, KING, &textures.b_king, (Vector2){3*SQUARE_SIZE, 0});
    w_pieces.emplace_back(0, KING, &textures.w_king, (Vector2){4*SQUARE_SIZE, 7*SQUARE_SIZE});
}

void Chess::play() {
    while (!WindowShouldClose()) {
        update();
        draw();
    }
}

void Chess::update() {
    mousePosition = GetMousePosition();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (CheckCollisionPointRec(mousePosition, board[i][j]) && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && pieceMap[j][i] != 0) {
                selectedSquare[0] = i;
                selectedSquare[1] = j;
            }
        }
    }
}

void Chess::draw() {
    BeginDrawing(); {
        ClearBackground(RAYWHITE);

        // Draw board
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                DrawRectangleRec(board[i][j], (i + j) % 2 == 0 ? WHITE : BLACK);
                if (i == selectedSquare[0] && j == selectedSquare[1]) {
                    DrawRectangleLinesEx(board[i][j], 10.0f, BLUE);
                }
            }
        }

        // Draw pieces
        for (int i = 0; i < 16; ++i) {
            if (b_pieces[i].isInGame) b_pieces[i].draw();
            if (w_pieces[i].isInGame) w_pieces[i].draw();
        }
    } EndDrawing();
}

bool Chess::isValidMove(std::vector<int> pos, ChessPieceType type) {
    switch (type) {
        case PAWN:
            return pos[0] == selectedSquare[0] && pieceMap[selectedSquare[0]][selectedSquare[1]] > 0 ? selectedSquare[0] == 2 ? selectedSquare[1] - pos[1] == -2 || selectedSquare[1] - pos[1] == -1 : selectedSquare[1] - pos[1] == -1 : selectedSquare[0] == 6 ? selectedSquare[1] - pos[1] == 2 || selectedSquare[1] - pos[1] == 1 : selectedSquare[1] - pos[1] == 1;
        case ROOK:
            return checkPath(pos) && pos[0] == selectedSquare[0] ? pos[1] != selectedSquare[1] : pos[1] == selectedSquare[1];
        case KNIGHT:
            return std::abs(pos[0] - selectedSquare[0]) == 1 ? std::abs(pos[1] - selectedSquare[1]) == 3 : std::abs(pos[0] - selectedSquare[0]) == 3 && std::abs(pos[1] - selectedSquare[1]) == 1;
        case BISHOP:
            return std::abs(pos[0] - selectedSquare[0]) == std::abs(pos[1] - selectedSquare[1]) && checkPath(pos);
        case QUEEN:
            return checkPath(pos) && pos[0] == selectedSquare[0] ? pos[1] != selectedSquare[1] : pos[1] == selectedSquare[1] || std::abs(pos[0] - selectedSquare[0]) == std::abs(pos[1] - selectedSquare[1]);
        case KING:
            return pos[0] == selectedSquare[0] ? std::abs(pos[1] - selectedSquare[1]) == 1 : std::abs(pos[0] - selectedSquare[0]) == 1 && std::abs(pos[1] - selectedSquare[1]) == 1;
        default:
            return true;
    }
}

bool Chess::checkPath(std::vector<int> pos) {
    if (pos[0] == selectedSquare[0]) {
        if (pos[1] < selectedSquare[1]) {
            for (int i = pos[1]; i < selectedSquare[1]; i++) {
                if (pieceMap[pos[0]][i] != 0) return false;
            }
        } else {
            for (int i = selectedSquare[1]; i < pos[1]; i++) {
                if (pieceMap[pos[0]][i] != 0) return false;
            }
        }
    } else if (pos[1] == selectedSquare[1]) {
        if (pos[0] < selectedSquare[0]) {
            for (int i = pos[0]; i < selectedSquare[0]; i++) {
                if (pieceMap[i][pos[1]] != 0) return false;
            }
        } else {
            for (int i = selectedSquare[0]; i < pos[0]; i++) {
                if (pieceMap[i][pos[1]] != 0) return false;
            }
        }
    } else {
        // diagonal
    }
    return true;
}