#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1, BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapRaised(d, w);

    Pixmap pix = XCreatePixmap(d, w, width, height, DefaultDepth(d, DefaultScreen(d)));
    gc = XCreateGC(d, pix, 0,(XGCValues *)0);

    XFlush(d);
    XFlush(d);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;
    char color_vals[10][10]={"white", "black", "red", "green", "blue", "cyan", "yellow", "magenta", "orange", "brown"};

    cmap=DefaultColormap(d,DefaultScreen(d));
    for(int i=0; i < 5; ++i) {
        XParseColor(d,cmap,color_vals[i],&xcolour);
        XAllocColor(d,cmap,&xcolour);
        colours[i]=xcolour.pixel;
    }

    XSetForeground(d,gc,colours[Black]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    XSynchronize(d,True);

    usleep(1000);

    // Make sure we don't race against the Window being shown
    XEvent ev;
    while(1) {
        XNextEvent(d, &ev);
        if(ev.type == Expose) break;
    }
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg) {
    XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

void Xwindow::drawR(int x, int y) {
    //Xwindow w{100, 100};
    // w.fillRectangle(0, 0, 100, 100, w.Black);
    // w.fillRectangle(0, 0, 10, 10, w.Green);
    // w.fillRectangle(10, 0, 10, 10, w.Green);
    // w.fillRectangle(20, 0, 10, 10, w.Green);
    // w.fillRectangle(20, 20, 10, 10, w.Green);
    // w.fillRectangle(0, 10, 10, 10, w.Green);
    // w.fillRectangle(0, 20, 10, 10, w.Green);
    // w.fillRectangle(0, 30, 10, 10, w.Green);
    // w.fillRectangle(0, 40, 10, 10, w.Green);
    // w.fillRectangle(0, 50, 10, 10, w.Green);
    // w.fillRectangle(10, 20, 10, 10, w.Green);
    // w.fillRectangle(30, 0, 10, 10, w.Green);
    // w.fillRectangle(30, 10, 10, 10, w.Green);
    // w.fillRectangle(30, 20, 10, 10, w.Green);
    // w.fillRectangle(10, 30, 10, 10, w.Green);
    // w.fillRectangle(20, 40, 10, 10, w.Green);
    // w.fillRectangle(30, 50, 10, 10, w.Green);

/*
    // horizontal
    for(int i = 0; i < 4; ++i) {
        w.fillRectangle(i*10, 0, 10, 10, w.Black);
    }
    // column
    for(int i = 0; i < 7; ++i) {
        w.fillRectangle(0, i*10, 10, 10, w.Black);
    }
    for(int i = 1; i < 4; ++i) {
        w.fillRectangle(i * 10, 0, 10, 10, w.Black);
    } 
    for(int i = 1; i < 4; ++i) {
        w.fillRectangle(i * 10, 30, 10, 10, w.Black);
    }
    for(int i = 1; i < 4; ++i) {
        w.fillRectangle(i * 10, 30, 10, 10, w.Black);
    }
    for(int i = 1; i < 3; ++i) {
        w.fillRectangle(40, i * 10, 10, 10, w.Black);
    }
    for(int i = 2; i < 5; ++i) {
        w.fillRectangle(i * 10, (4 + i - 2) * 10 , 10, 10, w.Black);
    }
*/
/*
    for(int i = 3; i < 7; ++i) {
        w.fillRectangle(i*10, 0, 10, 10, w.Black);
    }
    // column
    for(int i = 0; i < 7; ++i) {
        w.fillRectangle(30, i*10, 10, 10, w.Black);
    }
    for(int i = 4; i < 7; ++i) {
        w.fillRectangle(i * 10, 0, 10, 10, w.Black);
    }
    for(int i = 4; i < 7; ++i) {
        w.fillRectangle(i * 10, 30, 10, 10, w.Black);
    }
    for(int i = 4; i < 7; ++i) {
        w.fillRectangle(i * 10, 30, 10, 10, w.Black);
    }
    for(int i = 1; i < 3; ++i) {
        w.fillRectangle(60, i * 10, 10, 10, w.Black);
    }
    for(int i = 5; i < 8; ++i) {
        w.fillRectangle(i * 10, (4 + i - 5) * 10 , 10, 10, w.Black);
    }
*/
    for(int i = 3; i < 7; ++i) {
        fillRectangle(i*10, 20, 10, 10, Black);
    }
    // column
    for(int i = 2; i < 9; ++i) {
        fillRectangle(30, i*10, 10, 10, Black);
    }
    for(int i = 4; i < 7; ++i) {
        fillRectangle(i * 10, 50, 10, 10, Black);
    }
    for(int i = 3; i < 5; ++i) {
        fillRectangle(60, i * 10, 10, 10, Black);
    }
    for(int i = 5; i < 8; ++i) {
        fillRectangle(i * 10, (4 + i - 3) * 10 , 10, 10, Black);
    }
    while(true) {
        continue;
    }
}

void Xwindow::drawB(int x, int y) {
    Xwindow w{100, 100};
    for(int i = 3; i < 7; ++i) {
        fillRectangle(i*10, 20, 10, 10, Black);
    }
    for(int i = 3; i < 7; ++i) {
        fillRectangle(i*10, 50, 10, 10, Black);
    }
    for(int i = 3; i < 7; ++i) {
        fillRectangle(i*10, 80, 10, 10, Black);
    }
    for(int i = 2; i < 9; ++i) {
        fillRectangle(30, i*10, 10, 10, Black);
    }
    for(int i = 3; i < 9; ++i) {
        if ( i != 2 && i != 5 && i != 8) {
            fillRectangle(70, i*10, 10, 10, Black);
        }
    }
    while(true) {
        continue;
    }
}

void Xwindow::drawN(int x, int y) {
    Xwindow w{100, 100};
    for(int i = 2; i < 9; ++i) {
        fillRectangle(30, i*10, 10, 10, Black);
    }
    fillRectangle(40, 40, 10, 10, Black);
    fillRectangle(50, 50, 10, 10, Black);
    fillRectangle(60, 60, 10, 10, Black);
    for(int i = 2; i < 9; ++i) {
        fillRectangle(70, i*10, 10, 10, Black);
    }
    while(true) {
        continue;
    }
}

void Xwindow::drawQ(int x, int y) {
    //Xwindow w{100, 100};
    for(int i = 3; i < 8; ++i) {
        fillRectangle(30, i*10, 10, 10, Black);
    }
    for(int i = 3; i < 8; ++i) {
        fillRectangle(70, i*10, 10, 10, Black);
    }
    for(int i = 4; i < 7; ++i) {
        fillRectangle(i*10, 20, 10, 10, Black);
    }
    for(int i = 4; i < 7; ++i) {
        fillRectangle(i*10, 80, 10, 10, Black);
    }
    fillRectangle(60, 70, 10, 10, Black);
    fillRectangle(50, 60, 10, 10, Black);
    while(true) {
        continue;
    }
}

void Xwindow::drawK(int x, int y) {
    Xwindow w{100, 100};
    for(int i = 3; i < 9; ++i) {
        fillRectangle(30, i*10, 10, 10, w.Black);
    }
    fillRectangle(40, 50, 10, 10, Black);
    fillRectangle(50, 50, 10, 10, Black);
    fillRectangle(50, 50, 10, 10, Black);
    fillRectangle(50, 50, 10, 10, Black);
    fillRectangle(60, 40, 10, 10, Black);
    fillRectangle(60, 60, 10, 10, Black);
    fillRectangle(70, 30, 10, 10, Black);
    fillRectangle(70, 40, 10, 10, Black);
    fillRectangle(70, 70, 10, 10, Black);
    fillRectangle(70, 80, 10, 10, Black);
    while(true) {
        continue;
    }
    
}

void Xwindow::drawP(int x, int y) {
    //Xwindow w{100, 100};
    for(int i = 2; i < 9; ++i) {
        fillRectangle(30, i*10, 10, 10, Black);
    }
    for(int i = 4; i < 7; ++i) {
        fillRectangle(i*10, 20, 10, 10, Black);
    }
    for(int i = 4; i < 7; ++i) {
        fillRectangle(i*10, 50, 10, 10, Black);
    }
    fillRectangle(70, 30, 10, 10, Black);
    fillRectangle(70, 40, 10, 10, Black);
    while(true) {
        continue;
    }   
}

void Xwindow::drawChessBoard() {
    //drawR(0, 0);
    //drawB(0, 0);
    //drawN(0, 0);
    //drawQ(0, 0);
    //drawK(0, 0);
    //drawP(0, 0);
    Xwindow w{950, 950};
    string curr = "white";
    string curr_row = "8";
    string curr_col = "a";
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (x == 0) {
                drawString((x+1)*50, (y+1.5)*100+5, curr_row);
                curr_row[0] -= 1;
            }
            if (curr == "black") {
                fillRectangle( (x+1)*100, (y+1)*100, 100, 100, Brown);
            }
            else {
                fillRectangle( (x+1)*100, (y+1)*100, 100, 100, Blue);
            }
            if (x != 7) {
                curr = curr == "white" ? "black" : "white";
            }
        }
    }
    for (int z = 0; z <= 8; ++z) {
        if (z == 0) {
            continue;
        }
        drawString((z + 0.5)*100 + 5, 50, curr_col);
        curr_col[0] += 1;
    }
    while(true) {
        continue;
    }
}


    

/*
g++14 window.cc -lX11
./a.out
*/
