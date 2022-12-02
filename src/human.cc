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
    char c1;
    char c2;
    int start[2];
    int* endDest = new int[2];
    while (cin >> command) {
        if (command == "move") {
            // start position
            cin >> moveCommand;
            
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

                bool fake = false;
                if (gameBoard->theBoard[c1][c2]->validmove(*gameBoard, endDest, false, fake, fake, fake)) {
                    gameBoard->theBoard[c1][c2]->moveto(*gameBoard, endDest);
                }
                cout << gameBoard;
            }

        } else if (command == "resign") {
            forfeit();
        } else if (command == "setup") {
            // need to check if the current game is running
            string type;
            int xCor;
            int yCor;
            while (cin >> command) {
                cin >> type;
                cin >> moveCommand;
                xCor = moveCommand[0] - 'a';
                yCor = moveCommand[1] - '0';
                // checkif the current square is occupied
                if (command == "+") {
                    if (gameBoard->theBoard[xCor][yCor] != nullptr) {
                        delete gameBoard->theBoard[xCor][yCor];
                        gameBoard->theBoard[xCor][yCor] = nullptr;
                    }
                    if (type == "K") {
                        gameBoard->theBoard[xCor][yCor] = new King(xCor, yCor, playerTeam(), false, false);
                    } else if (type == "Q") {
                        gameBoard->theBoard[xCor][yCor] = new Queen(xCor, yCor, playerTeam(), false, false);
                    } else if (type == "R") {
                        gameBoard->theBoard[xCor][yCor] = new Rook(xCor, yCor, playerTeam(), false, false);
                    } else if (type == "B") {
                        gameBoard->theBoard[xCor][yCor] = new Bishop(xCor, yCor, playerTeam(), false, false);
                    } else if (type == "N") {
                        gameBoard->theBoard[xCor][yCor] = new Knight(xCor, yCor, playerTeam(), false, false);
                    } else if (type == "P") {
                        gameBoard->theBoard[xCor][yCor] = new Pawn(xCor, yCor, playerTeam(), false, false, false);
                    }
                } else if (command == "-") {
                    delete gameBoard->theBoard[xCor][yCor];
                    gameBoard->theBoard[xCor][yCor] = nullptr;

                } else if (command == "=") {
                    // set next turn
                } else if (command == "done") {
                    break;
                }
            }
            cout << gameBoard;
        }


    }
    delete endDest;
}
void Human::forfeit() {

}

