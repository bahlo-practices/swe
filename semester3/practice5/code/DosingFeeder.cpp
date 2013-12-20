//@(#) DosingFeeder.cpp

#include <string>
#include <iostream>

#include "DosingFeeder.h"
#include "Timer.h"
#include "Mixer.h"

//
DosingFeeder::DosingFeeder() : isOpen(false){}

//
DosingFeeder::DosingFeeder(Scale& scale) : isOpen(false), subject(&scale) {}


void DosingFeeder::dose(const Rezeptschritt& step) {
  string ingredient = step.getZutat();
  
  // Get target weight by ingredient
  if(ingredient == "Limettenstuecke") {
      targetWeight = step.getMenge() * 10;
  } else {
    targetWeight = step.getMenge();
  }

  open();
  
  // Simulate scale
  while(isOpen) {
    if(ingredient == "Eis") {
      subject->adjustWeightBy(20);
      cout << "*" << flush;
      Timer::wait(1000);
    } else if(ingredient == "Limettenstuecke") {
      subject->adjustWeightBy(10);
      cout << "*" << flush;
      Timer::wait(1000);
    } else {
      subject->adjustWeightBy(1);
      cout << "*" << flush;
      Timer::wait(250);
    }
  }
}


//
void DosingFeeder::update()
{	
    if(subject->getWeight() >= targetWeight) close();
}

void DosingFeeder::open()
{
  subject->resetDelta();
  isOpen = true;
  subject->attach(this);
}

void DosingFeeder::close()
{
  isOpen = false;
  targetWeight = 0;
  subject->detach(this);
}
