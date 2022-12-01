#include "human.h"
#include <iostream>
#include <sstream>

using namespace std;

void Human::move(Board* gameBoard) {
    string command;
    string moveCommand;
    int start[2];
    int* endDest = new int[2];
    while (cin >> command) {
        if (command == "move") {
            // start position
            cin >> moveCommand;
            char c1;
            char c2;
            c1 = moveCommand[0];
            c2 = moveCommand[1];
            start[0] = c1 - 'a';
            start[1] = c2 - '0';
            // check if the start position is valid (piece exists and is of the same team)
            if (gameBoard->theBoard[c1][c2]->getTeam() == playerTeam()) {
                // end position
                cin >> moveCommand;
                c1 = moveCommand[0];
                c2 = moveCommand[1];
                endDest[0] = c1 - 'a';
                endDest[1] = c2 - '0';

                gameBoard->theBoard[c1][c2]->moveto(*gameBoard, endDest);
            }
        }
    }
    delete endDest;
}

