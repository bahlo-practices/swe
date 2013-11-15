//@(#) Scale.h

#ifndef SCALE_H_H
#define SCALE_H_H

//Die Waage mischt das Gewicht des Mischbehälters
class Scale
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
