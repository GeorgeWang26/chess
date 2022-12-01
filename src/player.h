#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "board.h"
#include "piece.h"

class Player {
    std::string team;
    public:
        Player(std::string team);
        ~Player() {};
        std::string playerTeam();
        bool checkmate();
        bool stalemate();
        void forfeit();
        virtual void move(Board* gameBoard) = 0;
};

#endif