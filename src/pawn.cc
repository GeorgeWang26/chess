#include "pawn.h"
#include "board.h"

using namespace std;

Pawn::Pawn(int row, int col, string team, bool undercap, bool moved, bool canEnpassant):
    Piece{row, col, team, "pawn", undercap, moved, canEnpassant}
{}


// CHECK FOR ENPASSANT
bool Pawn::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (!(0 <= dest[0] && dest[0] < 8 && 0 <= dest[1] && dest[1] < 8) || board.theBoard[dest[0]][dest[1]]->getTeam() == team) {
        // dest is: out of bounds, same team (if dest==pos, team will be same)
        return false;
    }

    bool valid = false;
    Piece *destpiece = board.theBoard[dest[0]][dest[1]];

    // regular moves
    if (team == "white") {
        // white can only go up
        if (dest[0] == pos[0]+1 && dest[1] == pos[1]-1 && destpiece != nullptr && destpiece->getTeam() != team) {
            // overtake front left
            valid = true;
        } else if (dest[0] == pos[0]+1 && dest[1] == pos[1]+1 && destpiece != nullptr && destpiece->getTeam() != team) {
            // overtake front right
            valid = true;
        } else if (dest[0] == pos[0]+1 && dest[1] == pos[1] && destpiece == nullptr) {
            // move foward by 1
            valid = true;
        } else if (!getMoved() && dest[0] == pos[0]+2 && dest[1] == pos[1] && destpiece == nullptr) {
            // first move by 2, check if Piece::canEnpassant should set to true in Pawn::moveto()
            valid = true;
        }
    } else {
        // team == "black"
        // black can only go down
        if (dest[0] == pos[0]-1 && dest[1] == pos[1]-1 && destpiece != nullptr && destpiece->getTeam() != team) {
            // overtake down left
            valid = true;
        } else if (dest[0] == pos[0]-1 && dest[1] == pos[1]+1 && destpiece != nullptr && destpiece->getTeam() != team) {
            // overtake down right
            valid = true;
        } else if (dest[0] == pos[0]-1 && dest[1] == pos[1] && destpiece == nullptr) {
            // move down by 1
            valid = true;
        } else if (!getMoved() && dest[0] == pos[0]-2 && dest[1] == pos[1] && destpiece == nullptr) {
            // first move by 2, check if Piece::canEnpassant should set to true in Pawn::moveto()
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
                // check p != nullptr
                if (p && p->getTeam() == team && p->getType() == "king") {
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
    if (dest[0] == pos[0] && abs(dest[1] - pos[1]) == 1 && destpiece != nullptr && destpiece->getTeam() != team
            && destpiece->getType() == "pawn" && destpiece->getEnpassant()) {
        return true;
    }
    return false;
}


Board* Pawn::moveto(Board &board, int *dest) {
    Board *nb = Piece::moveto(board, dest);
    if (!getMoved() && abs(dest[1] - pos[1]) == 2) {
        // first move by 2, trigger enpassant
        nb->theBoard[dest[0]][dest[1]]->setEnpassant(true);
    }
    return nb;
}
