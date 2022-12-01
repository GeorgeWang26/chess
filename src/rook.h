#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
    // bool hasMoved;
public:
    Rook(int row, int col, std::string team, bool undercap, bool moved);
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
};

#endif
