#include "robot2.h"
#include "piece.h"
#include "board.h"
#include <iostream>

using namespace std;

Robot2::Robot2(string team):
    Player{team}
{}

Board* Robot2::move(Board* gameBoard, bool &success) {
    cout << "robot2 on the move" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece *p = gameBoard->theBoard[i][j];
            if (p != nullptr && p->getTeam() == team) {
                for (int desti = 0; desti < 8; desti++) {
                    for (int destj = 0; destj < 8; destj++) {
                        bool canCheck;
                        bool canCapture;
                        bool fake;
                        int dest[2] = {desti, destj};
                        if (p->validmove(*gameBoard, dest, false, canCheck, canCapture, fake)) {
                            if (canCapture || canCheck) {
                                // add into alpha vector
                                success = true;
                                return p->moveto(*gameBoard, dest);
                            } else {
                                // add into regular vector
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    // if has alpha, return random alpha element
    // else return random regular element
    success = false;
    return nullptr;
}