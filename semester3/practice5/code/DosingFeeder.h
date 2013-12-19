//@(#) DosingFeeder.h

#ifndef DOSINGFEEDER_H_H
#define DOSINGFEEDER_H_H

#include "Observer.h"
#include "MixableRecipeBook.h"
#include "Scale.h"

//Der Dosierer gibt die Zutat für eine bestimmte Zeit in den Mischbehälter
class DosingFeeder: public Observer
{
    
public:
    DosingFeeder();
    //
    DosingFeeder(Scale& scale);
    //
    void dose(const Rezeptschritt& step);
    
    //
    void update();
private:
    Scale* subject;
    bool isOpen;
    
    void open();
    void close();
    float targetWeight;
};

#endif
