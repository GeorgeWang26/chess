#include "king.h"
#include "board.h"
#include <iostream>
#include <string>

using namespace std;

King::King(int row, int col, string team):
    Piece{row, col, team, "king"}, ifMoved{false}
{}

bool King::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        // dest is: out of bounds, same team (if dest==pos, team will be same)
        return false;
    } else if (pos[0]-1 <= dest[0] && dest[0] <= pos[0]+1 && pos[1]-1 <= dest[1] && dest[1] <= pos[1]+1) {
        // move is within valid range
        if (suicide) {
            // suicide=true only when validmove() is called from King::getUndercheck()
            //      so dest is always the enemy king, so capture enemy always = true (altho this should not be needed at all)
            // also, since we are checking if it's valid to check enemy king, it doesn't matter if
            // this will put our own king in danger, because validmove() is now called from enemy's turn
            // SOOOOO as long as move is within valid range, return true 
            captureEnemy = true;
            return true;
        } else {
            Board *nb = moveto(board, dest);
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Piece *p = nb->theBoard[i][j];
                    if (p->getTeam() == team && p->getType() == "king") {

                    }
                }
            }
        }
    }
}

bool King::canCastle(Board &board) {
    // 
}

bool King::getUndercheck(Board &board) {
    // see if king is under check from ANY enemy (go through all 64 pieces)
    // validmove(dest=pos, suicide=true)
    bool fake;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // suicide = true
            // validmove will make sure [i][j] cant be same team as dest(current king)
            if (board.theBoard[i][j]->validmove(board, pos, true, fake, fake, fake)) {
                return true;
            }
        }
    }
    return false;
}
