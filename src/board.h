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
};

#endif
