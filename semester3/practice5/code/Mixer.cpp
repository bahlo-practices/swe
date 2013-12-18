//@(#) Mixer.cpp


#include "Mixer.h"
#include "Timer.h"
#include <iostream>

using namespace std;

//
Mixer::Mixer() : isCleaned(false) {}

//
void Mixer::clean()
{
	cout << endl << "Cleaning: ";
	for (int i = 0; i < 5; i++){
		Timer::wait(1000);
		cout << "*" << flush;
	}
	isCleaned = true;
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
  cout << endl << "Draining: ";
  for (int i = 0; i < 5; i++){
	  Timer::wait(1000);
	  cout << "*" << flush;
  }
  //#### MISSING: SCALE ######
  close();
}

void Mixer::start() {
  // Start mixing
}

void Mixer::stop() {
  // Stop mixing
}

void Mixer::open() {
  // Open drain
}

void Mixer::close() {
  // Close drain
}
