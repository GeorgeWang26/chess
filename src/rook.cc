#include "rook.h"
#include "board.h"
#include <iostream>
#include <string>

bool Rook::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        // dest is: out of bounds, same team (if dest==pos, team will be same)
        return false;
    } else if (dest[0] == pos[0] || dest[1] == pos[1]) {
        // move is within valid range
        // going straight up/down OR left/right
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
                        return !p->getUndercheck(*nb);
                    }
                }
            }
            delete nb;
        }
    }
    else {
        return false;
    }
}
