#include "bishop.h"
#include "board.h"

bool Bishop::validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) {
    // check for invalid squares
    if ((dest[0] < 0 ) || (dest[0] > 7) || (dest[1] < 0 ) || (dest[1] > 7)) {
        return false;
    }

    // check for valid bishop squares
    if (abs((dest[0] - pos[0])) == abs((dest[1] - pos[1]))) {
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
    } else {
        return false;
    }

    Board* newBoard = moveto(board, dest);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = newBoard->theBoard[i][j];
            if (p->getTeam() == team && p->getType() == "king") {
                
                return !p->getUndercheck(*newBoard);

            }
        }
    }

}
