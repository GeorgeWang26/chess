#ifndef KING_H
#define KING_H

#include "piece.h"
#include <iostream>


class King: public Piece{
    bool ifMoved;
public:
    King(int row, int col, std::string team);
    bool validmove(Board &board, int *dest, bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) override;
    bool canCastle(Board &board) override;
    bool getUndercheck(Board &board) override;
};

#endif
