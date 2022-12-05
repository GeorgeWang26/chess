#include "graphicsrender.h"
#include "subject.h"
#include "window.h"
#include "board.h"
#include "piece.h"
#include <string>

using namespace std;

GraphicsRender::GraphicsRender(Subject* sub): subject{sub} {}

GraphicsRender::~GraphicsRender() {subject->detach(this);}

void GraphicsRender::notify() {
    Board* theBoard = subject->getState();
    
    //print the board:
    drawChessBoard();
    //print pieces:
    for (i = 7; i >= 0; --i) {  
        for (j = 0; j < 8; ++j) {
            Piece* p = theBoard[i][j]; //start at the top left
            string type  = p->getType();
            if (type == "rook") {
                drawR( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
            else if (type == "bishop") {
                drawB( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
            else if (type == "knight") {
                drawN( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
            else if (type == "queen") {
                drawQ( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
            else if (type == "king") {
                drawK( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
            else if (type == "pawn") {
                drawP( (abs(i - 7) + 1) * 100 , (j+1) * 100 );
            }
        }
    }
}
