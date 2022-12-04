#include "robot3.h"
#include "piece.h"
#include "board.h"
#include <iostream>
#include <vector>

using namespace std;

Robot3::Robot3(string team):
    Player{team}
{}

Board* Robot3::move(Board* gameBoard, bool &success) {
    success = true;
    vector<vector<int>> alphamove;
    vector<vector<int>> regmove;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pos[] = {i, j};
            for (int desti = 0; desti < 8; desti++) {
                for (int destj = 0; destj < 8; destj++) {
                    bool canCheck;
                    bool canCapture;
                    bool canEscape;
                    int dest[] = {desti, destj};
                    if (gameBoard->validmove(team, pos, dest, canCheck, canCapture, canEscape)) {
                        success = true;
                        vector<int> move {i, j, desti, destj};
                        if (canCapture || canCheck || canEscape) {
                            // add into alpha vector
                            alphamove.emplace_back(move);  
                        } else {
                            // add into regular vector
                            regmove.emplace_back(move);
                        }
                    }
                }
            }
        }
    }
    if (alphamove.size() > 0) {
        // choose random element in preferred moves
        vector<int> move = alphamove[rand() % (alphamove.size())];
        int pos[] = {move[0], move[1]};
        int dest[] = {move[2], move[3]};
        return gameBoard->moveto(pos, dest);
    } else {
        // choose random element in potential moves
        vector<int> move = regmove[rand() % (regmove.size())];
        int pos[] = {move[0], move[1]};
        int dest[] = {move[2], move[3]};
        return gameBoard->moveto(pos, dest);
    }
}