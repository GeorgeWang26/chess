#ifndef BOARD_H_
#define BOARD_H_

// #include <vector>

class Piece;

class Board {
    // vector<vector<std::unique_ptr(Piece)>>* theBoard;
public:
    Piece* theBoard[8][8];
    
    Board();
    ~Board() {};
    bool validBoard();
    // Piece* getPiece(int *pos);
};

#endif
