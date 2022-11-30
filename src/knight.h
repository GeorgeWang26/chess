#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "piece.h"

class Knight: public Piece {
    public:
        bool validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) override;
};

#endif