#include "knight.h"
#include "board.h"

bool Knight::validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) {
    // check for invalid squares
    if ((dest[0] < 0 ) || (dest[0] > 7) || (dest[1] < 0 ) || (dest[1] > 7)) {
        return false;
    }

    // check for valid knight squares
    if (( (dest[0] == pos[0] + 2) && ((dest[1] == pos[1] + 1) || (dest[1] == pos[1] - 1)) ) || 
        ( (dest[0] == pos[0] + 1) && ((dest[1] == pos[1] + 2) || (dest[1] == pos[1] - 2)) ) ||
        ( (dest[0] == pos[0] - 1) && ((dest[1] == pos[1] + 2) || (dest[1] == pos[1] - 2)) ) ||
        ( (dest[0] == pos[0] - 2) && ((dest[1] == pos[1] + 1) || (dest[1] == pos[1] - 1)) )) {
        // check for same team piece in test square
        if (board.theBoard[dest[0]][dest[1]]->getTeam() != getTeam()) {
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
        } else {
            return false;
        }
    } else {
        return false;
    }
}
