#include "pawn.h"
#include "board.h"

bool Pawn::validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) {
    if (team == "white") {
        if (dest[0] > 7 || dest[0] < 0 || dest[1] > 7 || dest[1] < 0 || board.theBoard[dest[0]][dest[1]]->getTeam() == team || (pos[0] == dest[0] && pos[1] == dest[1])) {
            return false;
        }
        else if (hasMoved) {
            if (board.theBoard[pos[0] + 1][pos[1]] == nullptr) {
                if (dest[0] == pos[0] + 1 && dest[1] == pos[1]) {
                    // if no 送将 => return true; 
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }                              
                }
            }
            else if (board.theBoard[pos[0] + 1][pos[1] - 1] != nullptr) {
                if (dest[0] == pos[0] + 1 && dest[1] == pos[1] - 1) {
                    // if no 送将 => return true;  
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }                      
                }
            }
            else if (board.theBoard[pos[0] + 1][pos[1] + 1] != nullptr) {
                if (dest[0] == pos[0] + 1 && dest[1] == pos[1] + 1) {
                    // if no 送将 => return true;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }                
                }
            }
        }
        else if (!hasMoved) {
            if (dest[0] == pos[0] + 1 || dest[0] == pos[0] + 2) {
                // if no 送将 => return true;
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                }
            }
        }
        else {
            return false;
        }
    }
    else if (team == "black") {
        if (dest[0] > 7 || dest[0] < 0 || dest[1] > 7 || dest[1] < 0 || board.theBoard[dest[0]][dest[1]]->getTeam() == team || (pos[0] == dest[0] && pos[1] == dest[1])) {
            return false;
        }
        else if (hasMoved) {
            if (board.theBoard[pos[0] - 1][pos[1]] == nullptr) {
                if (dest[0] == pos[0] - 1 && dest[1] == pos[1]) {
                    // if no 送将 => return true;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }           
                }
            }
            else if (board.theBoard[pos[0] - 1][pos[1] - 1] != nullptr) {
                if (dest[0] == pos[0] - 1 && dest[1] == pos[1] - 1) {
                    // if no 送将 => return true;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }                   
                }
            }
            else if (board.theBoard[pos[0] + 1][pos[1] + 1] != nullptr) {
                if (dest[0] == pos[0] - 1 && dest[1] == pos[1] + 1) {
                    // if no 送将 => return true;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                    }                   
                }
            }
        }
        else if (!hasMoved) {
            if (dest[0] == pos[0] - 1 || dest[0] == pos[0] - 2) {
                // if no 送将 => return true;
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Board* nb = moveto(board, dest);
                            Piece *p = nb->theBoard[i][j];
                            // check p != nullptr
                            if (p && p->getTeam() == team && p->getType() == "king") {
                                return !p->getUndercheck(*nb);
                            }
                        }
                }
            }
        }               
        else {
            return false;
        }
    }
}