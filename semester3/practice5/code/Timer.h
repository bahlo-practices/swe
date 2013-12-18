//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include "Subject.h"

//
class Timer : public Subject
{
public:
    //
    static void setTurbo(bool turbo);
    static void wait(long milliseconds);
private:
    //
    static bool turbo;
};

#endif
