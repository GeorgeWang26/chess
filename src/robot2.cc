#include "robot2.h"
#include "piece.h"
#include "board.h"

using namespace std;

Robot2::Robot2(string team):
    Player{team}
{}

Board* Robot2::move(Board* gameBoard, bool &success) {
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
                        bool fake;
                        if (p->validmove(*gameBoard, dest, false, canCheck, canCapture, fake)) {
                            if (canCapture || canCheck) {
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