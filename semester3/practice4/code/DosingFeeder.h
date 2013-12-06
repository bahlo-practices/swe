//@(#) DosingFeeder.h

#ifndef DOSINGFEEDER_H_H
#define DOSINGFEEDER_H_H

#include "Observer.h"
#include "Scale.h"
//Der Dosierer gibt die Zutat für eine bestimmte Zeit in den Mischbehälter
class DosingFeeder: public Observer
{
    
public:
    //
    void close();
    //
    DosingFeeder();
    //
    DosingFeeder(Scale & scale);
    //
    void open();
    

    //
    void update();
private:
    //
    Scale * subject;
    
};

#endif
