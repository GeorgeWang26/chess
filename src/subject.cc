#include "subject.h"

void Subject::attach(Observer* os) {
    observers.emplace_back(os);
}
void Subject::detach(Observer* os) {
    observers.pop_back();
}
void Subject::notifyObservers() {
    for (auto os:observers) {
        os->notify();
    }
}
Subject::~Subject() {}

