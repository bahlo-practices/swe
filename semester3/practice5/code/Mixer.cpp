//@(#) Mixer.cpp


#include "Mixer.h"
#include "Timer.h"
#include <iostream>

using namespace std;

//
Mixer::Mixer() : isEmpty(true) {}

Mixer::Mixer(Scale& scale) : isEmpty(true), subject(&scale) {}

//
void Mixer::clean()
{
	for (int i = 0; i < 5; i++){
		Timer::wait(1000);
		cout << "*" << flush;
	}
}

//
void Mixer::mix(int seconds)
{
  for (int i = 0; i < seconds; i++){
  	Timer::wait(1000);
  	cout << "*" << flush;
  }
}

//
void Mixer::drain()
{
  open();

  isEmpty = false;

  while (!isEmpty){
	  Timer::wait(1000);
	  subject->adjustWeightBy(-25);
	  cout << "*" << flush;
  }
}

void Mixer::open() {
	subject->attach(this);
}

void Mixer::close() {
	isEmpty = true;
	subject->detach(this);
}

void Mixer::update(){
  if (subject->getRealWeight() <= 0) {
    isEmpty = true;
    close();
  }
}
