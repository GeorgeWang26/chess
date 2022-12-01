#ifndef QUEEN_H_
#define QUEEN_H_

#include "piece.h"

class Queen: public Piece {
    public:
        bool validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) override;
        bool getUndercheck(Board &board);
};

#endif