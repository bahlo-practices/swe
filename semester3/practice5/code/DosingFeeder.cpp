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
  targetWeight = step.getMenge();
  string ingredient = step.getZutat();

  open();

  // Simulate scale
  while(isOpen) {
    if(ingredient == "Eis") {
      subject->adjustWeightBy(20);
      cout << "*";
      Timer::wait(1000);
    } else if(ingredient == "Limettenstuecke") {
      subject->adjustWeightBy(10);
      cout << "*";
      Timer::wait(1000);
    } else {
      subject->adjustWeightBy(1);
      cout << "*";
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
  isOpen = true;
  subject->attach(this);
  subject->resetDelta();
}

void DosingFeeder::close()
{
  isOpen = false;
  subject->detach(this);
}
