#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece{
    bool castle(Board &board, int *dest);
public:
    King(int row, int col, std::string team, bool undercap, bool moved);
    bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) override;
    bool getUndercheck(Board &board) override;
    Board* moveto(Board &board, int *dest) override;
};

#endif
