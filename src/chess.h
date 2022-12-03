#ifndef CHESS_H_
#define CHESS_H_

// #include "board.h"
// #include "player.h"
#include "subject.h"
#include <string>

class Player;
class Board;

class Chess: public Subject {
    std::string curPlayer;
    bool gameRunning;
    bool gameStart;
    Board* curBoard;
    Board* prevBoard;
    Player* white;
    Player* black;
    // int result; // result 0 = white win, 1 = blackwin
    void reset();
public:
    float whiteWin;
    float blackWin;
    
    // Chess(Board* curBoard, Board* prevBoard, std::string curPlayer, Player* white, Player* black, bool gameRunning, int result, int whiteWin, int blackWin);
    // Chess();
    ~Chess();
    void takeTurn();
    Board* getState() const override;
};

#endif
