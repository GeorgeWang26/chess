#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"

class Bishop: public Piece {
    public:
        Bishop(int row, int col, std::string team, bool undercap, bool moved);
        bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
        bool getUndercheck(Board &board) override;
};

#endif