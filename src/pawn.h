#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
    bool enpassant(Board &board, int *dest);
public:
    Pawn(int row, int col, std::string team, bool undercap, bool moved, bool canEnpassant);
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
    Board* moveto(Board &board, int *dest) override;
};

#endif
