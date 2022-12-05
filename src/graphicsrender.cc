#include "graphicsrender.h"
#include "subject.h"
#include "xwindow.h"
#include "board.h"
#include "piece.h"
#include <string>

using namespace std;

GraphicsRender::GraphicsRender(Subject *sub):
    subject{sub}, xwindow{950, 950}
{
    subject->attach(this);
}


GraphicsRender::~GraphicsRender() {
    subject->detach(this);
}


void GraphicsRender::notify() {
    Board* theBoard = subject->getState();
    
    //print the board:
    xwindow.drawChessBoard();
    //print pieces:
    for (i = 7; i >= 0; --i) {  
        for (j = 0; j < 8; ++j) {
            Piece* p = theBoard[i][j]; //start at the top left
            string type  = p->getType();
            int color = p->getTeam() == "white" ? xwindow.White : xwindow.Black;
            if (type == "rook") {
                xwindow.drawR((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
            else if (type == "bishop") {
                xwindow.drawB((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
            else if (type == "knight") {
                xwindow.drawN((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
            else if (type == "queen") {
                xwindow.drawQ((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
            else if (type == "king") {
                xwindow.drawK((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
            else if (type == "pawn") {
                xwindow.drawP((abs(i - 7) + 1) * 100 , (j+1) * 100, color);
            }
        }
    }
}
