#include "king.h"
#include "board.h"
#include <iostream>

King::King(int row, int col, std::string team):
    Piece{row, col, team, "king"}, ifMoved{false}
{}

bool King::validmove(const Board &board, const int *dest, const bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) const {
    if (dest[0] > 7 || dest[0] < 0 || dest[1] > 7 || dest[1] < 0 || board.theBoard[dest[0]][dest[1]]->team == team || (pos[0] == dest[0] && pos[1] == dest[1])) {
        return false;
    }
    else if ((dest[0] <= pos[0] + 1 && dest[0] >= pos[0] - 1) && (dest[1] >= pos[1] - 1 && dest[1] >= pos[1] + 1)) {
        // step1-3 finished

        /*
        smartptr
        unique_ptr<Board> new_board {new Board{board}};
        new_board[dest[0]][dest[1]] = new_board[pos[0]][pos[1]];
        */

        // Board* new_board = new Board{board};
        // new_board[dest[0]][dest[1]] = new_board[pos[0]][pos[1]];
        // delete new_board[pos[0]][pos[1]];
        
       // check if opponent is already under check, if so, no check for illegal move.
       

////////
    if (suicide) {
        // suicide=true only when validmove() is called from King::getUndercheck()
        // so dest is always the enemy king, so capture enemy always = true
        captureEnemy = true;
        return true;
    } else {
        Board *nb = moveto(board, dest);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece *p = nb->theBoard[i][j];
                if (p->getTeam() == team && p->getType() == "king" && )
            }
        }
    }
////////
       
       if (gettype(board[dest[0]][dest[1]]) != "king") {
        Board* new_board = MoveTo(dest, board);
        string opponent_team = team == "white" ? "black" : "white";
        if (getUndercheck(new_board, team)) {
            return false;
        }
       }


        
        /* check if my king will be checked. */
        if (UnderCheck(new_board, team)) {
            // if so => return false;
            // is not => check next;
        }

        //check if the move will check enemy's king
        if (UnderCheck(new_board, opponent_team)) {
            //if so => mutate canCheck to be true
            //if not => no change (assume the parameter is default by false)
        }

        //check if the move will captureEnemy
        if (board[dest[0]][dest[1]]->team == opponent_team) {
            //if so => muatate to be true
            //if not => no change (assume the parameter is default by false)
        }
            
        
        
            
        //check if the move will escape the capture
            //if so => mutate escape status to be true and under_capture to be fasle(optional);
            //if not => not change (assume the parameter is default by false)

        
    }
    else {
        return false;
    }
}

bool King::canCastle(const Board &board, const std::string team) const {
    // if (if_moved) {
    //     return false;
    // }
    // else {
    //     return true;
    // }
}

bool King::getUndercheck(const Board &board, const std::string team) const {
    bool fake;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // suicide = true
            if (board.theBoard[i][j]->validmove(board, pos, true, fake, fake, fake)) {
                return true;
            }
        }
    }
    return false;
}
