#ifndef PIECE_H
#define PIECE_H

#include <string>

class Board;

class Piece {
protected:
    // make sure this is does NOT live on heap
    int pos[2];
    std::string team;
    bool undercap;

public:
    Piece(int row, int col, std::string team);
    std::string getTeam() const;
    bool getUndercap() const;
    void setUndercap(const Board &board);

    // return true as long as it obey moving rules and doesnt put own king in check
    // how to check if own king is in check? see notes.txt
    virtual bool validmove(const Board &board, const int *dest, bool &canCheck, bool &captureEnemy, bool &escape) const = 0;
    // return a new allocated board
    Board* moveto(const Board &board, const int *dest) const;

    // only override in King and Rook
    virtual bool canCastle(const Board &board, const std::string team) const;
    // only override in Pawn
    virtual bool canExpassant(const Board &board, const std::string team) const;

    // only override in King
    // return true as long as enemy piece can capture king, regardless if this capture move will put enemy king in check
    virtual bool getUndercheck(const Board &board, const std::string team) const;
};

#endif
