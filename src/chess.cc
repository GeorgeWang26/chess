#include "chess.h"
#include <iostream>

#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include "player.h"
#include "human.h"

using namespace std;

// Chess::Chess(Board* curBoard, Board* prevBoard, string curPlayer, Player* white, Player* black, bool gameRunning, 
//             int result, int whiteWin, int blackWin): curBoard{curBoard}, prevBoard{prevBoard}, curPlayer{curPlayer}, 
//             white{white}, black{black}, gameRunning{false}, result{-1}, whiteWin{0}, blackWin{0} {}

// Chess::Chess():
//     gameRunning{false}, whiteWin{0}, blackWin{0}
// {}


Chess::~Chess() {
    delete curBoard;
    delete prevBoard;
    delete white;
    delete black;
}

void Chess::takeTurn() {
    string command;
    while (cin >> command) {
        if (command == "game") {
            if (gameRunning) {
                cout << "invalid command, game in progress" << endl;
                continue;
            }

            string whiteP, blackP;
            cin >> whiteP >> blackP;

            if ((whiteP == "human" || whiteP == "computer1" || whiteP == "computer2" || whiteP == "computer3" || whiteP == "computer4") && 
            (blackP == "human" || blackP == "computer1" || blackP == "computer2" || blackP == "computer3" || blackP == "computer4")) {
                delete prevBoard;
                delete curBoard;
                delete white;
                delete black;
                prevBoard = nullptr;
                curBoard = new Board{};
                gameRunning = true;
                curPlayer = "white";
                
                if (whiteP == "human") {
                    white = new Human{"white"};
                } 
                // else if (whiteP == "computer1") {
                //     white = new Computer1{"white"};
                // } else if (whiteP == "computer2") {
                //     white = new Computer2{"white"};
                // } else if (whiteP == "computer3") {
                //     white = new Computer3{"white"};
                // } else {
                //     white = new Computer4{"white"};
                // }
                if (blackP == "human") {
                    black = new Human{"black"};
                }
                //  else if (blackP == "computer1") {
                //     black = new Computer1{"black"};
                // } else if (blackP == "computer2") {
                //     black = new Computer2{"black"};
                // } else if (blackP == "computer3") {
                //     black = new Computer3{"black"};
                // } else {
                //     black = new Computer4{"black"};
                // }
            } else {
                cout << "invalid command, unknown player type" << endl;
            }
        // end of "game"

        } else if (command == "resign") {
            if (!gameRunning) {
                cout << "invalid command, no game in progress" << endl;
            }
            if (curPlayer == "white") {
                blackWin++;
                cout << "Black wins!" << endl;
            } else {
                whiteWin++;
                cout << "White wins!" << endl;
            }
            delete curBoard;
            delete prevBoard;
            delete white;
            delete black;
            curBoard = nullptr;
            prevBoard = nullptr;
            white = nullptr;
            black = nullptr;
            gameRunning = false;
        // end of "resign"

        } else if (command == "move") {
            gameRunning = true;
            // implement move in player class
            delete prevBoard;
            prevBoard = curBoard;
            if (curPlayer == "white") {
                curBoard = white->move(prevBoard);
            } else {
                curBoard = black->move(prevBoard);
            }
            // print board aftermove is completed
            cout << curBoard;
            // switch player
            curPlayer = curPlayer == "white" ? "black" : "white";

            // check if stalemate/checkmate/check && display message
        // end of "move"
        
        } else if (command == "setup") {
            string pos;
            char type;
            int row;
            int col;

            while (cin >> command) {
                // checkif the current square is occupied
                if (command == "+") {
                    cin >> type >> pos;
                    // SOME SANITY CHECK HERE FOR VALID TYPE AND POS
                    if ((pos[0] >= 'a') && (pos[0] <= 'h') && (pos[1] >= '1') && (pos[1] <= '8')) {
                        row = pos[1] - '1';
                        col = pos[0] - 'a';
                        Piece *p = curBoard->theBoard[row][col];
                        if (p != nullptr) {
                            delete curBoard->theBoard[row][col];
                            curBoard->theBoard[row][col] = nullptr;
                        }
                        if (type == 'K') {
                            p = new King(row, col, "white", false, false);
                        } else if (type == 'Q') {
                            p = new Queen(row, col, "white", false, false);
                        } else if (type == 'R') {
                            p = new Rook(row, col, "white", false, false);
                        } else if (type == 'B') {
                            p = new Bishop(row, col, "white", false, false);
                        } else if (type == 'N') {
                            p = new Knight(row, col, "white", false, false);
                        } else if (type == 'P') {
                            p = new Pawn(row, col, "white", false, false, false);
                        } else if (type == 'k') {
                            p = new King(row, col, "black", false, false);
                        } else if (type == 'q') {
                            p = new Queen(row, col, "black", false, false);
                        } else if (type == 'r') {
                            p = new Rook(row, col, "black", false, false);
                        } else if (type == 'b') {
                            p = new Bishop(row, col, "black", false, false);
                        } else if (type == 'n') {
                            p = new Knight(row, col, "black", false, false);
                        } else if (type == 'p') {
                            p = new Pawn(row, col, "black", false, false, false);
                        } 
                    } else {
                        cout << "invalid command, move is out of range" << endl;
                    }
                } else if (command == "-") {
                    cin >> pos;
                    // SOME SANITY CHECK HERE FOR VALID TYPE AND POS
                    if ((pos[0] >= 'a') && (pos[0] <= 'h') && (pos[1] >= '1') && (pos[1] <= '8')) {
                        row = pos[1] - '1';
                        col = pos[0] - 'a';
                        Piece *p = curBoard->theBoard[row][col];
                        if (p != nullptr) {
                            delete p;
                            curBoard->theBoard[row][col] = nullptr;
                            // notify observers to redisplay
                        }
                    } else {
                        cout << "invalid command, move is out of range" << endl;
                    }
                } else if (command == "=") {
                    string team;
                    cin >> team;
                    if (team == "white" || team == "black") {
                        curPlayer = team;
                    } else {
                        cout << "invalid command, unknown colour" << endl;
                    }
                } else if (command == "done") {
                    // upon leaving setup mode, set all piece moved to be true, AKA disable castle and enpassant
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            Piece *p = curBoard->theBoard[i][j];
                            if (p == nullptr) {
                                continue;
                            }
                            p->setMoved(true);
                        }
                    }
                    break;
                } else {
                    cout << "invalid command, unknown setup command" << endl;
                }
            }
        }
    }
}
