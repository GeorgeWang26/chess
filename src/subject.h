#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "board.h"
#include "observer.h"

class Subject {
    std::vector<Observer*> observers;
public:
    virtual ~Subject();
    void attach(Observer* os);
    void detach(Observer* os);
    void notifyObservers();
    virtual Board* getState() const = 0;
};

#endif
