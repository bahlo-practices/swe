//@(#) Mixer.cpp


#include "Mixer.h"
#include "Timer.h"

//
Mixer::Mixer() : isCleaned(false) {}

//
void Mixer::clean()
{
  // Clean?
  Timer::wait(2000);
  isCleaned = true;
}

//
void Mixer::mix(int seconds)
{
  start();
  Timer::wait(seconds * 1000);
  stop();
}

//
void Mixer::drain()
{
  open();
  Timer::wait(5000); // Scale?
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
