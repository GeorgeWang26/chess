#include "robot3.h"
#include "piece.h"
#include "board.h"

using namespace std;

Robot3::Robot3(string team):
    Player{team}
{}

Board* Robot3::move(Board* gameBoard, bool &success) {
    success = true;
    int pos[2];
    int dest[2];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 0; j++) {
            Piece *p = gameBoard->theBoard[i][j];
            if (p != nullptr && p->getTeam() == team) {
                for (int m = 0; m < 8; m++) {
                    for (int n = 0; n < 8; n++) {
                        bool canCheck;
                        bool canCapture;
                        bool canEscape;
                        if (p->validmove(*gameBoard, dest, false, canCheck, canCapture, canEscape)) {
                            if (canCapture || canCheck || canEscape) {
                                return p->moveto(*gameBoard, dest);
                            }
                        }
                    }
                }
                for (int m = 0; m < 8; m++) {
                    for (int n = 0; n < 8; n++) {
                        bool fake;
                        if (p->validmove(*gameBoard, dest, false, fake, fake, fake)) {
                            return p->moveto(*gameBoard, dest);
                        }
                    }
                }
            }
        }
    }
}