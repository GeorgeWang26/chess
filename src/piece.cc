#include "piece.h"
// #include "board.h"
#include <string>
#include <memory>

using namespace std;

Piece::Piece(int row, int col, string team): pos{row, col}, team{team}, undercap{false} {}

string Piece::getTeam() const {
    return team;
}

bool Piece::getUndercap() const {
    return undercap;
}

void Piece::setUndercap(const Board &board) {
    // regular check here
    undercap = false;
    bool fake = false;
    // check all 64 pos for now, optimize latter to only check straight, diagonal, horse, pawn
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.theBoard[i][j]->validmove(board, pos, fake, fake, fake)) {
                undercap = true;
                return;
            }
        }
    }
}

Board* Piece::moveto(const Board &board, const int *dest) const {
    Board *nb = new Board {board};
    nb->theBoard[dest[0]][dest[1]] = nb->theBoard[pos[0]][pos[1]];
    delete(nb->theBoard[pos[0]][pos[1]]);
    nb->theBoard[pos[0]][pos[1]] = nullptr;
    return nb;
}

bool Piece::canCastle(const Board &board, const string team) const {
    return false;
}

bool Piece::canExpassant(const Board &board, const string team) const {
    return false;
}

bool Piece::getUndercheck(const Board &board, const string team) const {
    return false;
}
