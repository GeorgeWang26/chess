#ifndef HUMAN_H_
#define HUMAN_H_

#include "player.h"
#include <string>

class Human: public Player {
public:
    Human(std::string team);
    Board* move(Board* gameBoard) override;
};

#endif
