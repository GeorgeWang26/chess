#include "pawn.h"
#include "board.h"

using namespace std;

Pawn::Pawn(int row, int col, string team, bool undercap, bool moved, bool canEnpassant):
    Piece{row, col, team, "pawn", undercap, moved, canEnpassant}
{}


// CHECK FOR ENPASSANT
bool Pawn::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    Piece *destpiece = board.theBoard[dest[0]][dest[1]];
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || (destpiece != nullptr && destpiece->getTeam() == team)) {
        // dest is: out of bounds, same team (if dest==pos, team will be same)
        return false;
    }
    // if dest has a piece, then it's guranteed to be different team!!!!!!!!!!
    
    bool valid = false;

    // regular moves
    if (team == "white") {
        // white can only go up
        if (dest[0] == pos[0] + 1 && abs(dest[1] - pos[1]) == 1 && destpiece != nullptr) {
            // overtake up diagonal by 1
            valid = true;
        } else if (dest[0] == pos[0] + 1 && dest[1] == pos[1] && destpiece == nullptr) {
            // move up by 1
            valid = true;
        } else if (!getMoved() && dest[0] == 3 && dest[1] == pos[1] && destpiece == nullptr && board.theBoard[2][pos[1]] == nullptr) {
            // white pawn is making first move, attempt to go up by 2 to row 3
            // check that up_by_1 (row 2) AND up_by_2 (row 3, dest) are both empty
            valid = true;
        }
    } else {
        // team == "black"
        // black can only go down
        if (dest[0] == pos[0] - 1 && abs(dest[1] - pos[1]) == 1 && destpiece != nullptr) {
            // overtake down diagonal by 1
            valid = true;
        } else if (dest[0] == pos[0] - 1 && dest[1] == pos[1] && destpiece == nullptr) {
            // move down by 1
            valid = true;
        } else if (!getMoved() && dest[0] == 4 && dest[1] == pos[1] && destpiece == nullptr && board.theBoard[5][pos[1]] == nullptr) {
            // black pawn is making first move, attempt to go down by 2 to row 4
            // check that down_by_1 (row 5) AND down_by_2 (row 4, dest) are both empty
            valid = true;
        }
    }

    if (enpassant(board, dest)) {
        valid = true;
    }

    if (!valid) {
        return false;
    }

    if (suicide) {
        captureEnemy = true;
        return true;
    } else {
        Board *nb = moveto(board, dest);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece *p = nb->theBoard[i][j];
                if (p != nullptr && p->getTeam() == team && p->getType() == "king") {
                    if (p->getUndercheck(*nb)) {
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


bool Pawn::enpassant(Board &board, int *dest) {
    Piece *destpiece = board.theBoard[dest[0]][dest[1]];
    // for enpassant, dest has to be empty and cur_piece is moving forward diagonal by 1
    if (destpiece == nullptr && abs(dest[1] - pos[1]) == 1 && ((team == "white" && dest[0] == pos[0] + 1) || (team == "black" && dest[0] == pos[0] - 1))) {   
        // now check enemy pawn with enpassant activated is on the same row as pos, and same col as dest
        Piece *p = board.theBoard[pos[0]][dest[1]];
        if (p != nullptr && p->getTeam() != team && p->getType() == "pawn" && p->getEnpassant()) {
            return true;
        }
    }
    return false;
}


Board* Pawn::moveto(Board &board, int *dest) {
    Board *nb = Piece::moveto(board, dest);
    if (!getMoved() && abs(dest[1] - pos[1]) == 2) {
        // first move by 2, trigger enpassant
        nb->theBoard[dest[0]][dest[1]]->setEnpassant(true);
    } else if (enpassant(board, dest)) {
        // free piece at same row as pos, and same col as dest
        free(nb->theBoard[pos[0]][dest[1]]);
        nb->theBoard[pos[0]][dest[1]] = nullptr;
    }
    return nb;
}
