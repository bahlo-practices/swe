//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include <vector>
#include "Observer.h"
//
class Subject
{
    
public:
    //
    void attach(const Observer * observer);
    //
    void detach(const Observer * observer);
    //
    void notify();
    
private:
    //
    std::vector<Observer *> observers;    
};

#endif
