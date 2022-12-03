#include "subject.h"

using namespace std;

void Subject::attach(Observer* obs) {
    observers.emplace_back(obs);
}


void Subject::detach(Observer* obs) {
    for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ) {
        if (*it == obs) { 
            it = observers.erase(it);
        } else {
            ++it;
        }
    }
}


void Subject::notifyObservers() {
    for (auto obs : observers) {
        obs->notify();
    }
}
