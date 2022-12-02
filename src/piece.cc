#include "piece.h"
#include "board.h"

using namespace std;

Piece::Piece(int row, int col, string team, string type, bool undercap, bool moved, bool canEnpassant):
    pos{row, col}, team{team}, type{type}, undercap{undercap}, moved{moved}, canEnpassant{canEnpassant}
{}


Piece::~Piece() {
    // nothing need to be freed
}


string Piece::getTeam() {
    return team;
}


string Piece::getType() {
    return type;
}


bool Piece::getUndercap() {
    return undercap;
}


void Piece::setUndercap(Board &board) {
    if (getType() == "king") {
        undercap = getUndercheck(board);
        return;
    }
    // regular check here
    undercap = false;
    bool fake = false;
    // check all 64 pos for now, optimize latter to only check straight, diagonal, horse, pawn
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = board.theBoard[i][j];
            // suicide = false
            if (p != nullptr && p->validmove(board, pos, false, fake, fake, fake)) {
                undercap = true;
                return;
            }
        }
    }
}


bool Piece::getMoved() {
    return moved;
}


bool Piece::getEnpassant() {
    return canEnpassant;
}


void Piece::setEnpassant(bool status) {
    canEnpassant = status;
}


Board* Piece::moveto(Board &board, int *dest) {
    // deepcopy old board
    Board *nb = new Board {board};
    // delete old piece at dest, could be nullptr or actual piece (heap allocated)
    delete(nb->theBoard[dest[0]][dest[1]]);
    // set dest to be the current piece (which is at pos)
    nb->theBoard[dest[0]][dest[1]] = nb->theBoard[pos[0]][pos[1]];
    // set pos to be nullptr
    nb->theBoard[pos[0]][pos[1]] = nullptr;
    // now piece has moved
    nb->theBoard[dest[0]][dest[1]]->moved = true;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = nb->theBoard[i][j];
            if (p != nullptr) {
                p->setEnpassant(false);
            }
        }
    }
    
    // return new board (heap allocated)
    // USER NEEEEEEED TO DELETE
    return nb;
}


bool Piece::getUndercheck(Board &board) {
    return false;
}
