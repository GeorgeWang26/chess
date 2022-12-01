#include "board.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
// #include <vector>

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            theBoard[i][j] = nullptr;
        }
    }
    // default starting positions
    // setting white
    for (int i = 0; i < 8; ++i) {
        if ((i == 0) || (i == 7)) { // rook
            theBoard[0][i] = new Rook(0, i, "white", false, false); 
        } else if ((i == 1) || (i == 6)) { // knight
            theBoard[0][i] = new Knight(0, i, "white", false, false); 
        } else if ((i == 2) || (i == 5)){
            theBoard[0][i] = new Bishop(0, i, "white", false, false); 
        } else if (i == 3) {
            theBoard[0][i] = new King(0, i, "white", false, false);
        } else {
            theBoard[0][i] = new Queen(0, i, "white", false, false);       
        }
        theBoard[1][i] = new Pawn(0, i, "white", false, false, false);
    }
    // setting black
    for (int i = 0; i < 8; ++i) {
        if ((i == 0) || (i == 7)) {
            theBoard[7][i] = new Rook(0, i, "black", false, false); 
        } else if ((i == 1) || (i == 6)) {
            theBoard[7][i] = new Knight(0, i, "black", false, false);
        } else if ((i == 2) || (i == 5)){
            theBoard[7][i] = new Bishop(0, i, "black", false, false);
        } else if (i == 3) {
            theBoard[7][i] = new King(0, i, "black", false, false); 
        } else {
            theBoard[7][i] = new Queen(0, i, "black", false, false);        
        }
        theBoard[6][i] = new Pawn(0, i, "black", false, false, false);
    }
}

Board::~Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (theBoard[i][j] != nullptr) {
                delete theBoard[i][j];
            }
        }
    }
}

Board::Board(const Board &other) {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
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
    int wKing = 0;
    int bKing = 0;

    int wPawn = 0;
    int bPawn = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Piece *p = theBoard[i][j];
            // both teams must have a kind on the board
            if (p->getType() == "king") { // includ piece type parameter
                if (p->getTeam() == "white") {
                    wKing++;
                } else {
                    bKing++;
                }
            }
            // pawns cannot be on the first row of their own side
            // each team cannot have more than 8 pawns
            if (p->getType() == "pawn") {
                // invalid pawn position
                // pawns cannot be on the first or last row of the board
                if ((i == 0) || (i == 7)) {
                    return false;
                }
                if (p->getTeam() == "white") {
                    wPawn++;
                } else {
                    bPawn++;
                }
            }
        }
    }
    if ((wKing != 1) || (bKing != 1) || (wPawn > 8) || (bPawn > 8)) {
        return false;
    }
    return true;
}


// Piece* Board::getPiece(int *pos) {
//     return theBoard[pos[0]][pos[1]];
// }
