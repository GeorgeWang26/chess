#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook: public Piece {
    bool hasMoved;
public:
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
    bool canCastle(Board &board) override;
};

#endif
