//@(#) Scale.cpp


#include "Scale.h"

//
Scale::Scale()
{
    
}

void Scale::resetDelta() 
{
  offset = weight;
}

int Scale::getWeight() 
{
  if(offset > weight) return 0;
  return weight - offset;
}

void Scale::adjustWeightBy(int by) 
{
  weight += (weight + by < 0) 
    ? 0 
    : weight + by;
}