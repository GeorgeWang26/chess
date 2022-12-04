#include "robot3.h"
#include "board.h"
#include <vector>

using namespace std;

Robot3::Robot3(string team):
    Player{team}
{}


Board* Robot3::move(Board* gameBoard, bool &success) {
    // robot will always have a valid move
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
                            alphamove.push_back(move);  
                        } else {
                            regmove.push_back(move);
                        }
                    }
                }
            }
        }
    }

    if (alphamove.size() > 0) {
        // choose random alphamove
        vector<int> move = alphamove[rand() % (alphamove.size())];
        int pos[] = {move[0], move[1]};
        int dest[] = {move[2], move[3]};
        return gameBoard->moveto(pos, dest);
    } else {
        // choose random regmove
        vector<int> move = regmove[rand() % (regmove.size())];
        int pos[] = {move[0], move[1]};
        int dest[] = {move[2], move[3]};
        return gameBoard->moveto(pos, dest);
    }
}
