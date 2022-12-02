#include "subject.h"

Subject::~Subject() {}


void Subject::attach(Observer* obs) {
    observers.emplace_back(obs);
}


void Subject::detach(Observer* obs) {
    observers.pop_back();
}


void Subject::notifyObservers() {
    for (auto obs : observers) {
        obs->notify();
    }
}
