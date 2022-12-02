#include "chess.h"
#include <iostream>

#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

using namespace std;

Chess::Chess(Board* curBoard, Board* prevBoard, string curPlayer, Player* white, Player* black, bool gameRunning, 
            int result, int whiteWin, int blackWin): curBoard{curBoard}, prevBoard{prevBoard}, curPlayer{curPlayer}, 
            white{white}, black{black}, gameRunning{false}, result{-1}, whiteWin{0}, blackWin{0} {}



void Chess::takeTurn(Board* gameBoard) {
    string command;
    while (cin >> command) {
        if (command == "move") {
        
            // implement move in player class
            if (curPlayer == "white") {
                white->move(gameBoard);
            } else {
                black->move(gameBoard);
            }

            // print board aftermove is completed
            cout << gameBoard;

            prevBoard = curBoard;
            curBoard = gameBoard;

            gameRunning = true;
            
            // switch cur player
            if (curPlayer == "white") {
                curPlayer = "black";
            } else {
                curPlayer = "white";
            }

        } else if (command == "resign") {
            forfeit();
        } else if (command == "setup") {
            string moveCommand;
            string type;
            int xCor;
            int yCor;

            while (cin >> command) {
                cin >> type;
                cin >> moveCommand;
                xCor = moveCommand[0] - 'a';
                yCor = moveCommand[1] - '0';
                // checkif the current square is occupied
                if (command == "+") {
                    if (gameBoard->theBoard[xCor][yCor] != nullptr) {
                        delete gameBoard->theBoard[xCor][yCor];
                        gameBoard->theBoard[xCor][yCor] = nullptr;
                    }
                    if (type == "K") {
                        gameBoard->theBoard[xCor][yCor] = new King(xCor, yCor, "white", false, false);
                    } else if (type == "Q") {
                        gameBoard->theBoard[xCor][yCor] = new Queen(xCor, yCor, "white", false, false);
                    } else if (type == "R") {
                        gameBoard->theBoard[xCor][yCor] = new Rook(xCor, yCor, "white", false, false);
                    } else if (type == "B") {
                        gameBoard->theBoard[xCor][yCor] = new Bishop(xCor, yCor, "white", false, false);
                    } else if (type == "N") {
                        gameBoard->theBoard[xCor][yCor] = new Knight(xCor, yCor, "white", false, false);
                    } else if (type == "P") {
                        gameBoard->theBoard[xCor][yCor] = new Pawn(xCor, yCor, "white", false, false, false);
                    } else if (type == "k") {
                        gameBoard->theBoard[xCor][yCor] = new King(xCor, yCor, "black", false, false);
                    } else if (type == "q") {
                        gameBoard->theBoard[xCor][yCor] = new Queen(xCor, yCor, "black", false, false);
                    } else if (type == "r") {
                        gameBoard->theBoard[xCor][yCor] = new Rook(xCor, yCor, "black", false, false);
                    } else if (type == "b") {
                        gameBoard->theBoard[xCor][yCor] = new Bishop(xCor, yCor, "black", false, false);
                    } else if (type == "n") {
                        gameBoard->theBoard[xCor][yCor] = new Knight(xCor, yCor, "black", false, false);
                    } else if (type == "p") {
                        gameBoard->theBoard[xCor][yCor] = new Pawn(xCor, yCor, "black", false, false, false);
                    } 
                } else if (command == "-") {
                    delete gameBoard->theBoard[xCor][yCor];
                    gameBoard->theBoard[xCor][yCor] = nullptr;
                } else if (command == "=") {
                    string nextTurn;
                    cin >> nextTurn;
                    if (nextTurn == "white") {
                        curPlayer = "white";
                    } else if (nextTurn == "black") {
                        curPlayer = "black";
                    }
                } else if (command == "done") {
                    break;
                }
            }
        }
    }
}


void Chess::forfeit() {
    if (curPlayer == "white") {
        result = 0;
        ++whiteWin;
    } else {
        result = 1;
        ++blackWin;
    }
}