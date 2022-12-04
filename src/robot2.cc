#include "robot2.h"
#include "piece.h"
#include "board.h"
#include <iostream>
#include <vector>

using namespace std;

Robot2::Robot2(string team):
    Player{team}
{}

Board* Robot2::move(Board* gameBoard, bool &success) {
    vector<vector<int>> preferredMoves;
    vector<vector<int>> potentialMoves;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pos[] = {i, j};
            for (int desti = 0; desti < 8; desti++) {
                for (int destj = 0; destj < 8; destj++) {
                    bool canCheck;
                    bool canCapture;
                    bool fake;
                    int dest[] = {desti, destj};
                    if (gameBoard->validmove(team, dest, false, canCheck, canCapture, fake)) {
                        success = true;
                        vector<int> move {i, j, desti, destj};
                        if (canCapture || canCheck) {
                            // add into alpha vector
                            preferredMoves.emplace_back(move);  
                        } else {
                            // add into regular vector
                            potentialMoves.emplace_back(move);
                            continue;
                        }
                    }
                }
            }
        }
    }
    if (preferredMoves.size() > 0) {
        // choose random element in preferred moves
         vector<int> move = preferredMoves[rand() % (preferredMoves.size())];
        return p->moveto(*gameBoard, dest);
    } else {
        // choose random element in potential moves
        vector<int> move = potentialMoves[rand() % (potentialMoves.size())];
        return p->moveto(*gameBoard, dest);
    }
    
    // should never occur
    success = false;
    return nullptr;
}