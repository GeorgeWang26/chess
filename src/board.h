#ifndef BOARD_H_
#define BOARD_H_

#include <string>

class Piece;

class Board {
public:
    Piece* theBoard[8][8];
    
    Board(bool blankBoard = false);
    ~Board() {};
    Board(const Board &other);

    bool validBoard();

    bool check(std::string team);
    bool checkmate(std::string team);
    bool stalemate(std::string team);

    bool validmove(int *cur, int *dest, bool &canCheck, bool &captureEnemy, bool &escape);
    // user will need to free (delete) the returned Board*
    Board* moveto(int *cur, int *dest, std::string newType = "queen");
    
    void setUndercap();
};

#endif
