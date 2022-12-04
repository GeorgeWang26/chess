#include "robot2.h"
#include "piece.h"
#include "board.h"
#include <iostream>

using namespace std;

Robot2::Robot2(string team):
    Player{team}
{}

Board* Robot2::move(Board* gameBoard, bool &success) {
    vector<vector<int>> preferredMoves;
    vector<vector<int>> potentialMoves;

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
                        vector<int> dest = {desti, destj};
                        if (p->validmove(*gameBoard, dest, false, canCheck, canCapture, fake)) {
                            success = true;
                            if (canCapture || canCheck) {
                                // add into alpha vector
                                preferredMoves.emplace_back(dest);  
                            } else {
                                // add into regular vector
                                potentialMoves.emplace_back(dest);
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    if (preferredMoves.size() > 0) {
        // choose random element in preferred moves
        return p->moveto(*gameBoard, dest);
    } else {
        // choose random element in potential moves
        return p->moveto(*gameBoard, dest);
    }
    
    // should never occur
    success = false;
    return nullptr;
}