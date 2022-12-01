#include "king.h"
#include "board.h"
#include <iostream>
#include <string>

using namespace std;

King::King(int row, int col, string team, bool undercap, bool moved):
    Piece{row, col, team, "king", undercap, moved}
{}

// NEED TO CHECK FOR CASTLE
bool King::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        // dest is: out of bounds, same team (if dest==pos, team will be same)
        return false;
    } else if (castle(board, dest) || (pos[0]-1 <= dest[0] && dest[0] <= pos[0]+1 && pos[1]-1 <= dest[1] && dest[1] <= pos[1]+1)) {
        // move is within valid range
        if (suicide) {
            // suicide=true only when validmove() is called from King::getUndercheck()
            //      so dest is always the enemy king, so capture enemy always = true (altho this should not be needed at all)
            // also, since we are checking if it's valid to check enemy king, it doesn't matter if
            // this will put our own king in danger, because validmove() is now called from enemy's king
            // SOOOOO as long as move is within valid range, return true 
            captureEnemy = true;
            return true;
        } else {
            Board *nb = moveto(board, dest);
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Piece *p = nb->theBoard[i][j];
                    // check p != nullptr
                    if (p && p->getTeam() == team && p->getType() == "king") {
                        if (p->getUndercheck(*nb)) {
                            delete nb;
                            return false;
                        } else {
                            delete nb;

                            /*
                            
                            
                            
                            
                            SOMEHOW PASS THE INFO THAT WE ARE TRYING TO CASTLE
                            SO MOVETO CAN MOVE ROOK AS WELL
                            
                            
                            
                            
                            */



                            return true;
                        }
                    }
                }
            }
        }
    }
}

bool King::castle(Board &board, int *dest) {
    int row = pos[0];

    if (getMoved() || dest[0] != row || abs(dest[1] - pos[1]) == 2 || getUndercheck(board)) {
        return false;
    }
    // king never moved before, dest on same row, col diff by 2, and king not in check at start pos
    if (dest[1] == 2) {
        // left castle
        // [row][0] is allie rook that never moved before
        Piece *rook = board.theBoard[row][0];
        if (rook && rook->getTeam() == team && rook->getType() == "rook" && !rook->getMoved()) {
            // no piece between king and rook
            for (int i = 1; i <= 3; i++) {
                if (board.theBoard[row][i]) {
                    return false;
                }
            }
            // make sure king is not in check on middle and end pos
            for (int i = 2; i <= 3; i++) {
                int arr[] = {row, i};
                Board *nb = moveto(board, arr);
                Piece *king = nb->theBoard[row][i];
                if (king->getUndercheck(*nb)) {
                    return false;
                }
                delete nb;
            }
            return true;
        }
    } else {
        // right castle, dest[1] == 6
        // [row][7] is allie rook that never moved before
        Piece *rook = board.theBoard[row][7];
        if (rook && rook->getTeam() == team && rook->getType() == "rook" && !rook->getMoved()) {
            // no piece between king and rook
            // make sure king is not in check on middle and end pos
            for (int i = 5; i <= 6; i++) {
                // no piece in between
                if (board.theBoard[row][i]) {
                    return false;;
                }
                // not in check
                int arr[] = {row, i};
                Board *nb = moveto(board, arr);
                Piece *king = nb->theBoard[row][i];
                if (king->getUndercheck(*nb)) {
                    return false;
                }
                delete nb;
            }
            return true;
        }
    }
    return false;
}

bool King::getUndercheck(Board &board) {
    // see if king is under check from ANY enemy (go through all 64 pieces)
    // validmove(dest=pos, suicide=true)
    bool fake;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // suicide = true
            // validmove will make sure [i][j] cant be same team as dest(current king)
            Piece *p = board.theBoard[i][j];
            // check p != nullptr

            /*
            if king is now black
            then every p enter the condition will be white
            so black king is undercheck as long as white p can move to my pos
            regardless if the move will put white king under check
            AKA suicide
            */


            if (p && p->getTeam() != team && p->validmove(board, pos, true, fake, fake, fake)) {
                return true;
            }
        }
    }
    return false;
}
