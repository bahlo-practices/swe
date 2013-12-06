//@(#) Pounder.cpp


#include "Pounder.h"
#include "Timer.h"

Pounder::Pounder() {}

void Pounder::pound(int seconds) {
  start();
  Timer::wait(seconds * 1000);
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

