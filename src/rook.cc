#include "rook.h"
#include "board.h"
#include <iostream>
#include <string>

bool Rook::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (dest[0] > 7 || dest[0] < 0 || dest[1] > 7 || dest[1] < 0 || board.theBoard[dest[0]][dest[1]]->getTeam() == team || (pos[0] == dest[0] && pos[1] == dest[1])) {
        return false;
    }
    else if (dest[0] == pos[0] || dest[1] == pos[1]) {
        Board* newBoard = moveto(board, dest);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece *p = newBoard->theBoard[i][j];
                if (p->getTeam() == team && p->getType() == "king") {
                    if (p->getUndercheck(*newBoard)) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    }
    else {
        return false;
    }
}
