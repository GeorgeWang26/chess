#include "textrender.h"
#include "subject.h"
#include <iostream>

using namespace std;

TextRender::TextRender(Subject* sub): subject{sub} {
    subject->attach(this);
}


TextRender::~TextRender() {
    subject->detach(this);
}


void TextRender::notify() {
    cout << subject->getState();
}
