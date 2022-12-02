#include "human.h"
#include <iostream>
#include <sstream>

#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

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
            
            start[0] = moveCommand[0] - 'a';
            start[1] = moveCommand[1] - '0';
            // check if the start position is valid (piece exists and is of the same team)
            if (gameBoard->theBoard[start[0]][start[1]]->getTeam() == playerTeam()) {
                // end position
                cin >> moveCommand;
                endDest[0] = moveCommand[0] - 'a';
                endDest[1] = moveCommand[1] - '0';

                bool fake = false;
                // check for valid move
                if (gameBoard->theBoard[start[0]][start[1]]->validmove(*gameBoard, endDest, false, fake, fake, fake)) {
                    gameBoard->theBoard[start[0]][start[1]]->moveto(*gameBoard, endDest);
                }
                cout << gameBoard;
            }
        } 
    }
    delete endDest;
}


