#include "board.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

using namespace std;

Board::Board(bool blankBoard = false) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            theBoard[i][j] = nullptr;
        }
    }

    // custom board start as empty
    if (blankBoard) {
        return;
    }

    // default starting positions
    for (int j = 0; j < 8; j++) {
        if ((j == 0) || (j == 7)) {
            theBoard[0][j] = new Rook(0, j, "white", false, false);
            theBoard[7][j] = new Rook(7, j, "black", false, false);
        } else if ((j == 1) || (j == 6)) {
            theBoard[0][j] = new Knight(0, j, "white", false, false);
            theBoard[7][j] = new Knight(7, j, "black", false, false);
        } else if ((j == 2) || (j == 5)){
            theBoard[0][j] = new Bishop(0, j, "white", false, false);
            theBoard[7][j] = new Bishop(7, j, "black", false, false);
        } else if (j == 3) {
            theBoard[0][j] = new Queen(0, j, "white", false, false);
            theBoard[7][j] = new Queen(7, j, "black", false, false);
        } else {
            // j == 4
            theBoard[0][j] = new King(0, j, "white", false, false);
            theBoard[7][j] = new King(7, j, "black", false, false);
        }
        theBoard[1][j] = new Pawn(0, j, "white", false, false, false);
        theBoard[6][j] = new Pawn(6, j, "black", false, false, false);
    }
}


Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // its fine to delete nullptr
            delete theBoard[i][j];
        }
    }
}


Board::Board(const Board &other) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = other.theBoard[i][j];
            if (p != nullptr) {
                if (p->getType() == "rook") {
                    theBoard[i][j] = new Rook(i, j, p->getTeam(), p->getUndercap(), p->getMoved());
                } else if (p->getType() == "knight") {
                    theBoard[i][j] = new Knight(i, j, p->getTeam(), p->getUndercap(), p->getMoved());
                } else if (p->getType() == "bishop") {
                    theBoard[i][j] = new Bishop(i, j, p->getTeam(), p->getUndercap(), p->getMoved());
                } else if (p->getType() == "king") {
                    theBoard[i][j] = new King(i, j, p->getTeam(), p->getUndercap(), p->getMoved());
                } else if (p->getType() == "queen") {
                    theBoard[i][j] = new Queen(i, j, p->getTeam(), p->getUndercap(), p->getMoved());
                } else if (p->getType() == "pawn") {
                    theBoard[i][j] = new Pawn(i, j, p->getTeam(), p->getUndercap(), p->getMoved(), p->getEnpassant());
                }
            } else {
                theBoard[i][j] = nullptr;
            }
        }
    }
}


bool Board::validBoard() {
    // dont care number of pieces on board except for king
    int wKing = 0;
    int bKing = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece *p = theBoard[i][j];
            if (p == nullptr) {
                continue;
            }
            // both teams must have one and only one kind on the board
            if (p->getType() == "king") {
                if (p->getTeam() == "white") {
                    wKing++;
                } else {
                    bKing++;
                }
            }
            // no pawn on first or last row
            if (p->getType() == "pawn" && (i == 0 || i == 7)) {
                return false;
            }
        }
    }

    if (wKing != 1 || bKing != 1 || check("white") || check("black")) {
        return false;
    }
    
    return true;
}


bool Board::check(string team) {
    // find king, see if king is undercheck
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = theBoard[i][j];
            if (p != nullptr && p->getType() == "king" && p->getTeam() == team) {
                return p->getUndercheck(*this);
            }
        }
    }
}


bool Board::checkmate(string team) {
    // currently under check, and has no valid moves (all moves will result in check)
    if (check(team)) {
        // see if there are any valid moves
        return stalemate(team);
    }
    return false;
}


bool Board::stalemate(string team) {
    // if team has no valid moves (all moves will result in check)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *cur = theBoard[i][j];
            // only care about if own team has any valid moves
            if (cur != nullptr && cur->getTeam() == team) {
                for (int desti = 0; desti < 8; desti++) {
                    for (int destj = 0; destj < 8; destj++) {
                        int dest[] = {desti, destj};
                        bool fake = false;
                        if (cur->validmove(*this, dest, false, fake, fake, fake)) {
                            // if a valid move exist, then is not in stalemate
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
