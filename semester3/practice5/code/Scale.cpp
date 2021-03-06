//@(#) Scale.cpp

#include <iostream>

#include "Scale.h"

//
Scale::Scale() : offset(0), weight(0) {}

int Scale::getWeight() const
{
  if(offset > weight) return 0;
  return weight + offset;
}

void Scale::resetDelta()
{
  offset = -weight;
}

void Scale::adjustWeightBy(int by)
{ 
  weight = (weight + by < 0)
    ? 0
    : weight + by;
  notify();
}

int Scale::getRealWeight() const 
{
  return weight;
}