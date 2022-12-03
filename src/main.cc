#include "chess.h"
#include "textrender.h"
#include <iostream>

using namespace std;

int main() {
    Chess chess;
    TextRender text {&chess};
    while (true) {
        chess.takeTurn();
    }
    cout << "Final Score:" << endl;
    cout << "White: " << chess.whiteWin << endl;
    cout << "Black: " << chess.blackWin << endl;
}