//@(#) Scale.h

#ifndef SCALE_H_H
#define SCALE_H_H

#include "Subject.h"
//Die Waage mischt das Gewicht des Mischbehälters
class Scale: public Subject
{
    
public:
    //
    unsigned int getWeight();
    //
    Scale();
    //
    void setOffset(int _offset);
    
private:
    //
    int offset;
    
    
};

#endif
