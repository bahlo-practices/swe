//@(#) Pounder.cpp

#include <iostream>
#include "Pounder.h"
#include "Timer.h"

using namespace std;

Pounder::Pounder() {}

void Pounder::pound(int seconds) {
  start();
  cout << endl << "Pounding (" << seconds << "s): ";
  for (int i = 0; i < seconds; i++){
	  Timer::wait(1000);
	  cout << "*";
  }
  stop();
}

void Pounder::stop()
{
  // Stop pounding
}

void Pounder::start()
{
  // Start pounding
}

