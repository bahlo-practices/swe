//@(#) Mixer.cpp


#include "Mixer.h"
#include "Timer.h"
#include <iostream>

using namespace std;

//
Mixer::Mixer() : isEmpty(true), scale(Scale()) {}

Mixer::Mixer(Scale& s) : isEmpty(true), scale(s){}

//
void Mixer::clean()
{
	cout << endl << "Cleaning: ";
	for (int i = 0; i < 5; i++){
		Timer::wait(1000);
		cout << "*" << flush;
	}
}

//
void Mixer::mix(int seconds)
{
  start();
  cout << endl << "Mixing (" << seconds << "s): ";
  for (int i = 0; i < seconds; i++){
	Timer::wait(1000);
	cout << "*" << flush;
  }
  stop();
}

//
void Mixer::drain()
{
  open();
  
  while (!isEmpty){
	  Timer::wait(1000);
	  scale.adjustWeightBy(-25);
	  cout << "*" << flush;
  }
  
  close();
}

void Mixer::start() {
  // Start mixing
}

void Mixer::stop() {
  // Stop mixing
}

void Mixer::open() {
	scale.attach(this);
	cout << endl << "Draining: ";
}

void Mixer::close() {
	isEmpty = true;
	scale.detach(this);
}

void Mixer::update(){
	if (scale.getWeight() == 0) close();
}