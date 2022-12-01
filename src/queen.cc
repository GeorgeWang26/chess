#include "board.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"

using namespace std;

Queen::Queen(int row, int col, string team, bool undercap, bool moved):
    Piece{row, col, team, "queen", undercap, moved}
{}

bool Queen::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        return false;
    }

    if (abs((dest[0] - pos[0])) == abs((dest[1] - pos[1]))) { // check for diagonal moves
        int it = abs((dest[0] - pos[0])) - 1;
        int tx;
        int ty;
        if ((dest[0] >= pos[0]) && (dest[1] >= pos[1])) {
            tx = ++pos[0];
            ty = ++pos[1];
            for (int i = 0; i < it; i++) {
                if (board.theBoard[tx][ty] != nullptr) {
                    return false;
                }
                ++tx;
                ++ty;
            }
        } else if ((dest[0] < pos[0]) && (dest[1] < pos[1])) {
            tx = --pos[0];
            ty = --pos[1];
            for (int i = 0; i < it; i++) {
                if (board.theBoard[tx][ty] != nullptr) {
                    return false;
                }
                --tx;
                --ty;
            }
        } else if ((dest[0] >= pos[0]) && (dest[1] <= pos[1])) {
            tx = ++pos[0];
            ty = --pos[1];
            for (int i = 0; i < it; i++) {
                if (board.theBoard[tx][ty] != nullptr) {
                    return false;
                }
                ++tx;
                --ty;
            }
        } else {
            tx = --pos[0];
            ty = ++pos[1];
            for (int i = 0; i < it; i++) {
                if (board.theBoard[tx][ty] != nullptr) {
                    return false;
                }
                --tx;
                ++ty;
            }
        }
    } else if (dest[0] == pos[0] && dest[1] > pos[1]) { // check for horozontal/vertical moves
        int i = dest[0];
        for (int j = pos[1]; j < dest[1]; j++) {
            if (board.theBoard[i][j]) {
                return false;
            }
        }
    } else if (dest[0] == pos[0] && dest[1] < pos[1]) {
        int i = dest[0];
        for (int j = pos[1]; j > dest[1]; j--) {
            if (board.theBoard[i][j]) {
                return false;
            }
        }
    } else if (dest[0] > pos[0] && dest[1] == pos[1]) {
        int j = dest[1];
        for (int i = pos[0]; i < dest[0]; i++) {
            if (board.theBoard[i][j]) {
                return false;
            }
        }
    } else if (dest[0] < pos[0] && dest[1] == pos[1]) {
        int j = dest[1];
        for (int i = pos[0]; i > dest[0]; i--) {
            if (board.theBoard[i][j]) {
                return false;
            }
        }
    } else {
        return false;
    }

    if (suicide) {
        captureEnemy = true;
        return true;
    } else {
        Board* nb = moveto(board, dest);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece *p = nb->theBoard[i][j];
                // check p != nullptr
                if (p && p->getTeam() == team && p->getType() == "king") {
                    if(p->getUndercheck(*nb)) {
                        delete nb;
                        return false;
                    } else {
                        delete nb;
                        return true;
                    }
                }
            }
        }
    }
}
