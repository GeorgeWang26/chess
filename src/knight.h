#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "piece.h"

class Knight: public Piece {
public:
    Knight(int row, int col, std::string team, bool undercap, bool moved);
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
};

#endif
