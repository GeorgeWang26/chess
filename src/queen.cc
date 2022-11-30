#include "board.h"
#include "queen.h"

bool Queen::validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) {
    if ((dest[0] < 0 ) || (dest[0] > 7) || (dest[1] < 0 ) || (dest[1] > 7) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        return false;
    }
    // check diagonal
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
    // check horozontal and vertical
    if (!((dest[0] == pos[0]) || (dest[1] == pos[1]))) {
        return false;
    }
    
}
