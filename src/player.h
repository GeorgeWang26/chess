#ifndef PLAYER_H_
#define PLAYER_H_

#include "board.h"
#include "piece.h"

class Player {
protected:
    std::string team;
public:
    explicit Player(std::string team);
    virtual ~Player();
    // std::string playerTeam();
    virtual Board* move(Board* gameBoard) = 0;
};

#endif
