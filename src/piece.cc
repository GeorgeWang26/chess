#include "piece.h"
#include "board.h"
#include <string>
#include <memory>

using namespace std;

Piece::Piece(int row, int col, string team, string type, bool undercap, bool moved):
    pos{row, col}, team{team}, type{type}, undercap{undercap}, moved{moved}
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

void Piece::setUndercap(Board &board) {
    // regular check here
    undercap = false;
    bool fake = false;
    // check all 64 pos for now, optimize latter to only check straight, diagonal, horse, pawn
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // suicide = false
            if (board.theBoard[i][j]->validmove(board, pos, false, fake, fake, fake)) {
                undercap = true;
                return;
            }
        }
    }
}

bool Piece::getMoved() {
    return moved;
}

bool Piece::getUndercheck(Board &board) {
    return false;
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
    // return new board (heap allocated)
    // USER NEEEEEEED TO DELETE
    return nb;
}

// bool Piece::enpassant(Board &board) {
//     return false;
// }
