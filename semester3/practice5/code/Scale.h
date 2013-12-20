//@(#) Scale.h

#ifndef SCALE_H_H
#define SCALE_H_H

#include "Subject.h"
//Die Waage mischt das Gewicht des Mischbehälters
class Scale: public Subject
{

public:
    Scale();
    int getWeight() const;
    int getRealWeight() const;
    void resetDelta();
    void adjustWeightBy(int weight);
private:
    int offset;
    int weight;
};

#endif
