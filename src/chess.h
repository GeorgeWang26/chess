#ifndef CHESS_H_
#define CHESS_H_

#include "board.h"
#include "player.h"
#include <string>

class Chess {
    std::string curPlayer;
    bool gameRunning;
    Board* curBoard;
    Board* prevBoard;
    Player* white;
    Player* black;
    // int result; // result 0 = white win, 1 = blackwin
    float whiteWin;
    float blackWin;
public:
    // Chess(Board* curBoard, Board* prevBoard, std::string curPlayer, Player* white, Player* black, bool gameRunning, int result, int whiteWin, int blackWin);
    // Chess();
    ~Chess();
    void takeTurn(Board* gameBoard);
    void undo();
    Board & getState();
};

#endif