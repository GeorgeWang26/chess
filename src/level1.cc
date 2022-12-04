#include "level1.h"
#include <iostream>
#include <sstream>

#include "piece.h"
// #include "rook.h"
// #include "bishop.h"
// #include "knight.h"
// #include "queen.h"
// #include "king.h"
// #include "pawn.h"

Level1::Level1(string team): Player{team} {}

// king pawn check 9 possible move
int* checkKP(Board* gameBoard, int i, int j){
    // i - 1 <= x <= i + 1
    // j - 1 <= y <= j + 1
    bool fake = false;
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            int dest[2] = {x,y};
            if (gameBoard->theBoard[i][j]->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                return dest;
            }
        }
    }
    // if no valid move 
    return nullptr;
}

// knight check 8 possible move
int* checkN(Board* gameBoard, int i, int j) {
    int x, y;
    int dest[2] = {x, y};
    bool fake = false;
    dest[0] = i - 1;
    dest[1] = j - 2;
    Piece* p = gameBoard->theBoard[i][j];
    if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
        return dest;
    }
    else {
        dest[1] = j + 2;
        if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
            return dest;
        }
        else {
            dest[0] = i + 1;
            dest[1] = j - 2;
            if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                return dest;
            }
            else {
                dest[1] = j + 2;
                if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                    return dest;
                }
                else {
                    dest[0] = i + 2;
                    dest[1] = j - 1;
                    if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                        return dest;
                    }
                    else {
                        dest[1] = j + 1;
                        if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                            return dest;
                        }
                        else {
                            dest[0] = i - 2;
                            dest[1] = j - 1;
                            if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                                return dest;
                            }
                            else {
                                dest[1] = j + 1;
                                if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                                return dest;
                            }
                                else {
                                    return nullptr;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int* checkBRQ(Board* gameBoard, int i, int j) {
    Piece* p = gameBoard->theBoard[i][j];
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            int dest[2] = {x,y};
            bool fake = false;
            if (i == x || abs(i - x) == abs(j - y) || j == y) {
                if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                    return dest;
                }
            }
        }
    }
    return nullptr;
}




// bishop/rook/queen check digonal/horizental/vertial
Board* Level1::move(Board* gameBoard, bool &success) {
    success = false;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece *p = gameBoard->theBoard[i][j];
            if(p!= nullptr && p->getTeam() == team) {
                string PieceType = p->getType();
                
                if(PieceType == "pawn" || PieceType == "king") {
                    // checkKP
                    int* dest = checkKP(gameBoard, i, j);
                    if (dest != nullptr) { return p->moveto(*gameBoard, dest); }
                }
                else if (PieceType == "knight") {
                    /*checkN*/
                    int* dest = checkN(gameBoard, i, j);
                    if (dest != nullptr) { return p->moveto(*gameBoard, dest);}
                }
                else {
                    /*checkBRQ*/
                    int* dest = checkBRQ(gameBoard, i, j);
                    if (dest != nullptr) { return p->moveto(*gameBoard, dest);}
                }
            }
        }
    }
}

