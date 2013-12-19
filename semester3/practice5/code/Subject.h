//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include <vector>
#include "Observer.h"
//
class Subject {

public:
    //
    void attach(Observer * observer);
    //
    void detach(Observer * observer);
    //
    void notify();

private:
    //
    std::vector<Observer *> observers;
};

#endif
