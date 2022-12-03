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


Board* Human::move(Board* gameBoard) {
    string command;
    string startPos;
    string endPos;
    int start[2];
    int* endDest = new int[2];

    // start position
    cin >> startPos;
    cin >> endPos;

    if ((startPos[0] >= 'a') && (startPos[0] <= 'h') && (startPos[1] >= '1') && (startPos[1] <= '8')) {
        if ((endPos[0] >= 'a') && (endPos[0] <= 'h') && (endPos[1] >= '1') && (endPos[1] <= '8')) {
            start[0] = startPos[0] - 'a';
            start[1] = startPos[1] - '1';
            endDest[0] = endPos[0] - 'a';
            endDest[1] = endPos[1] - '1';

            Piece *p = gameBoard->theBoard[start[0]][start[1]];
            if (p != nullptr && p->getTeam() == team) {
            bool fake = false;
            // check for valid move
            if (p->validmove(*gameBoard, endDest, false, fake, fake, fake)) {
                p->moveto(*gameBoard, endDest);
            }
            cout << gameBoard;
        }
        } else {
            cout << "invalid command, ending move is out of range" << endl;
        }
    } else {
        cout << "invalid command, starting move is out of range" << endl;
    }

    // cin >> pos;

    // if ((pos[0] >= 'a') && (pos[0] <= 'h') && (pos[1] >= '1') && (pos[1] <= '8')) {
    //     start[0] = pos[0] - 'a';
    //     start[1] = pos[1] - '1';
    //     // check if the start position is valid (piece exists and is of the same team)
    //     Piece *p = gameBoard->theBoard[start[0]][start[1]];
    //     if (p != nullptr && p->getTeam() == team) {
    //         // end position
    //         cin >> pos;
    //         endDest[0] = pos[0] - 'a';
    //         endDest[1] = pos[1] - '1';

    //         bool fake = false;
    //         // check for valid move
    //         if (p->validmove(*gameBoard, endDest, false, fake, fake, fake)) {
    //             p->moveto(*gameBoard, endDest);
    //         }
    //         cout << gameBoard;
    //     }
    // } else {
    //     cout << "invalid command, move is out of range" << endl;
    // }

    delete endDest;
}


