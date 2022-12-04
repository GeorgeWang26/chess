#include <iostream>
#include "human.h"
#include "piece.h"
#include "board.h"

using namespace std;

Human::Human(string team):
    Player{team}
{}


Board* Human::move(Board* gameBoard, bool &success) {    
    string command;
    string posS;
    string destS;
    
    // start position
    cin >> posS;
    cin >> destS;

    if ('a' <= posS[0] && posS[0] <= 'h' && '1' <= posS[1] && posS[1] <= '8') {
        if ('a' <= destS[0] && destS[0] <= 'h' && '1' <= destS[1] && destS[1] <= '8') {
            int pos[2] = {posS[1] - '1', posS[0] - 'a'};
            int dest[2] = {destS[1] - '1', destS[0] - 'a'};
            bool fake;
            if (gameBoard->validmove(team, pos, dest, fake, fake, fake)) {
                success = true;
                return gameBoard->moveto(pos, dest);
            }
        }
    }
    cout << "invalid command, move is not accepted" << endl;
    // if reach here, then we know move is not valid, the returned nullptr should not be used
    success = false;
    return nullptr;
}
