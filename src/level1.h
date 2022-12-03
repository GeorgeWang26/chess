#ifndef LEVEL1_H
#define LEVEL1_H

#include "player.h"
using namespace std;

class Level1 : public Player{
public:
    Level1(string team);
    Board* move(Board* gameBoard, bool &success) override;
};

#endif
