#ifndef PIECE_H
#define PIECE_H

#include <string>

class Board;

class Piece {
protected:
    // make sure this is does NOT live on heap
    int pos[2];
    std::string team;  // black, white
    std::string type;  // king, queen, bishop, rook, knight, pawn
    bool undercap;

public:
    Piece(int row, int col, std::string team, std::string type);
    std::string getTeam() const;
    std::string getType() const;

    bool getUndercap() const;
    void setUndercap(const Board &board);

    virtual bool getUndercheck(const Board &board, const std::string team) const;

    // return true as long as it obey moving rules and doesnt put own king in check
    // how to check if own king is in check? see notes.txt
    virtual bool validmove(const Board &board, const int *dest, const bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) const = 0;
    // return a new allocated board
    Board* moveto(const Board &board, const int *dest) const;

    // only override in King and Rook
    virtual bool canCastle(const Board &board, const std::string team) const;
    // only override in Pawn
    virtual bool canExpassant(const Board &board, const std::string team) const;

};

#endif
