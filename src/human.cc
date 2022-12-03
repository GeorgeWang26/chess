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

Human::Human(string team):
    Player{team}
{}


Board* Human::move(Board* gameBoard, bool success) {
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

            Piece *p = gameBoard->theBoard[pos[0]][pos[1]];
            if (p != nullptr && p->getTeam() == team) {
                bool fake = false;
                // check for valid move
                if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                    success = true;
                    return p->moveto(*gameBoard, dest);
                } else {
                    cout << "invalid command, not valid move" << endl;
                }
            } else {
                cout << "invalid command, no allie piece at starting move" << endl;
            }
        } else {
            cout << "invalid command, ending move is out of range" << endl;
        }
    } else {
        cout << "invalid command, starting move is out of range" << endl;
    }

    // if reach here, then we know move is not valid
    success = false;
}