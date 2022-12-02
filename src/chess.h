#ifndef CHESS_H_
#define CHESS_H_

#include "board.h"
#include "player.h"
#include <string>

class Chess {
    Board* curBoard;
    Board* prevBoard;
    std::string curPlayer;
    Player* white;
    Player* black;
    bool gameRunning;
    int result; // result 0 = white win, 1 = blackwin
    int whiteWin;
    int blackWin;
public:
    Chess(Board* curBoard, Board* prevBoard, std::string curPlayer, Player* white, Player* black, bool gameRunning, int result, int whiteWin, int blackWin);
    void takeTurn(Board* gameBoard);
    void forfeit();
    void undo();
    Board & getState();
};

#endif