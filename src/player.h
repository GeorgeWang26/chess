#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player {
    std::string team;
    public:
        std::string getTeam();
        bool checkmate();
        bool stalemate();
        void forfeit();
        void move(Board *gameBoard);
};

#endif