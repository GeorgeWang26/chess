#ifndef ROBOT2_H_
#define ROBOT2_H_

#include "player.h"


class Robot2: public Player {
public:
    Robot2(std::string team);
    Board* move(Board* gameBoard, bool &success) override;
};


#endif
