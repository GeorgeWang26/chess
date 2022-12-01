#ifndef KING_H
#define KING_H

#include "piece.h"
#include <iostream>


class King: public Piece{
    // bool hasMoved;
    bool castle(Board &board, int *dest);
public:
    King(int row, int col, std::string team, bool undercap, bool moved);
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
    // bool canCastle(Board &board, int *dest) override;
    bool getUndercheck(Board &board) override;
};

#endif
