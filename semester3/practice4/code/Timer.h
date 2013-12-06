//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H
//
class Timer : public Subject
{
public:
    //
    static void setTurbo(bool turbo);
    static void sleep(long milliseconds);
private:
    //
    static bool turbo;
};

#endif
