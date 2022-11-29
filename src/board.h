#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

class Piece;

class Board {
    // vector<vector<std::unique_ptr(Piece)>>* theBoard;
    Piece* theBoard[8][8];

    public:
        Bool validBoard();
        Piece& getPiece(vector<int> &pos);
        Board();
        ~Board() {};
}

#endif



