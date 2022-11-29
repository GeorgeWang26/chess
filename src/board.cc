#include "board.h"
#include "piece.h"
#include <vector>
#include <string>

using namespace std;

Board::Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            theBoard[i][j] = nullptr;
        }
    }
    // default starting positions
    // setting white
    for (i = 0; i < 8; ++i) {
        if ((i == 0) || (i == 7)) { // rook
            theBoard[0][i] = new Rook(); // complete constructor late
        } else if ((i == 1) || (i == 6)) { // knight
            theBoard[0][i] = new Knight(); // complete constructor late
        } else if ((i == 2) || (i == 5)){
            theBoard[0][i] = new Bishop(); // complete constructor late
        } else if (i == 3) {
            theBoard[0][i] = new King(); // complete constructor late
        } else {
            theBoard[0][i] = new Queen(); // complete constructor late        
        }
        theBoard[1][i] = new Pawn();
    }
    // setting black
    for (i = 0; i < 8; ++i) {
        if ((i == 0) || (i == 7)) { // rook
            theBoard[7][i] = new Rook(); // complete constructor late
        } else if ((i == 1) || (i == 6)) { // knight
            theBoard[7][i] = new Knight(); // complete constructor late
        } else if ((i == 2) || (i == 5)){
            theBoard[7][i] = new Bishop(); // complete constructor late
        } else if (i == 3) {
            theBoard[7][i] = new King(); // complete constructor late
        } else {
            theBoard[7][i] = new Queen(); // complete constructor late        
        }
        theBoard[6][i] = new Pawn();
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

Bool Board::validBoard() {
    int wKing = 0;
    int bKing = 0;

    int wPawn = 0;
    int bPawn = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // both teams must have a kind on the board
            if (theBoard[i][j].getType() == "king") { // includ piece type parameter
                if (theBoard[i][j].getTeam() == "white") {
                    wKing++;
                } else {
                    bKing++;
                }
            }
            // pawns cannot be on the first row of their own side
            // each team cannot have more than 8 pawns
            if (theBoard[i][j].getType() == "pawn") {
                // invalid pawn position
                // pawns cannot be on the first or last row of the board
                if ((i == 0) || (i == 7)) {
                    return false;
                }
                if (theBoard[i][j].getTeam() == "white") {
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

Piece& Board::getPiece(vector<int> &pos) {
    return theBoard[pos[0]][pos[1]];
}




