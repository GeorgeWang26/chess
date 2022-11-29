#include "piece.h"
#include "board.h"
#include <string>
#include <memory>

using namespace std;

Piece::Piece(int row, int col, string team, string type): 
    pos{row, col}, team{team}, undercap{false}, type{type} 
{}

string Piece::getTeam() {
    return team;
}

string Piece::getType() {
    return type;
}

bool Piece::getUndercap() {
    return undercap;
}

bool Piece::getUndercheck(Board &board) {
    return false;
}

void Piece::setUndercap(Board &board) {
    // regular check here
    undercap = false;
    bool fake = false;
    // check all 64 pos for now, optimize latter to only check straight, diagonal, horse, pawn
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.theBoard[i][j]->validmove(board, pos, type=="king", fake, fake, fake)) {
                undercap = true;
                return;
            }
        }
    }
}

Board* Piece::moveto(Board &board, int *dest) {
    Board *nb = new Board {board};
    nb->theBoard[dest[0]][dest[1]] = nb->theBoard[pos[0]][pos[1]];
    delete(nb->theBoard[pos[0]][pos[1]]);
    nb->theBoard[pos[0]][pos[1]] = nullptr;
    return nb;
}

bool Piece::canCastle(Board &board) {
    return false;
}

bool Piece::canExpassant(Board &board) {
    return false;
}
