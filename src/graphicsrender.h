#ifndef GRAPHICSRENDER_H
#define GRAPHICSRENDER_H

#include "observer.h"

class Subject;
class Xwindow;

class GraphicsRender : public Observer {
    Subject *subject;
    Xwindow xwindow;
public:
    GraphicsRender(Subject *sub);
    ~GraphicsRender() override;
    void notify() override;
};
#endif
