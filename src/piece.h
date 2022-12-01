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
    bool moved;

public:
    Piece(int row, int col, std::string team, std::string type, bool undercap, bool moved);
    std::string getTeam();
    std::string getType();

    bool getUndercap();
    void setUndercap(Board &board);

    bool getMoved();

    // only override in King
    virtual bool getUndercheck(Board &board);

    // return true as long as it obey moving rules and doesnt put own king in check
    // how to check if own king is in check? see notes.txt
    virtual bool validmove(Board &board, int *dest, bool suicide, bool &canCheck, bool &captureEnemy, bool &escape) = 0;
    
    // return a new allocated board
    // ONLY OVERRIDE IN KING TO MOVE BOTH KING AND ROOK IF IS CASTLE
    virtual Board* moveto(Board &board, int *dest);

    // only override in Pawn
    // virtual bool canEnpassant(Board &board);

};

#endif
