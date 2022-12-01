#ifndef QUEEN_H_
#define QUEEN_H_

#include "piece.h"

class Queen: public Piece {
    public:
        Queen(int row, int col, std::string team, bool undercap, bool moved);
        bool validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) override;
};

#endif
