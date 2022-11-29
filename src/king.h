#ifndef KING_H
#define KING_H

#include "piece.h"
#include <iostream>


class King: public Piece{
    bool ifMoved;
public:
    King(int row, int col, std::string team);
    bool validmove(const Board &board, const int *dest, const bool destIsKing, bool &canCheck, bool &captureEnemy, bool &escape) const override;
    bool canCastle(const Board &board, const std::string team) const override;
    bool getUndercheck(const Board &board, const std::string team) const override;
};

#endif
