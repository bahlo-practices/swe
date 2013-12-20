//@(#) Pounder.cpp

#include <iostream>
#include "Pounder.h"
#include "Timer.h"

using namespace std;

Pounder::Pounder() {}

void Pounder::pound(int seconds) {
  for (int i = 0; i < seconds; i++){
	  Timer::wait(1000);
	  cout << "*" << flush;
  }
}
