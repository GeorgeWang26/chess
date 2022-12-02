#ifndef PLAYER_H_
#define PLAYER_H_

#include "board.h"
#include "piece.h"

class Player {
    std::string team;
public:
    explicit Player(std::string team);
    virtual ~Player();
    std::string playerTeam();
    virtual void move(Board* gameBoard) = 0;
};

#endif
