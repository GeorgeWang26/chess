#ifndef HUMAN_H_
#define HUMAN_H_

#include "player.h"

class Human: public Player {
    void forfeit();
public:
    void move(Board* gameBoard) override;
};

#endif
