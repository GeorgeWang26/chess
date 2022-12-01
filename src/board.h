#ifndef BOARD_H_
#define BOARD_H_

class Piece;

class Board {
public:
    Piece* theBoard[8][8];
    
    Board(bool blankBoard = false);
    ~Board() {};
    Board(const Board &other);
    bool validBoard();
};

#endif
