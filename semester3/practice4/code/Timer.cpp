#include "Timer.h"

#include <ctime>

bool Timer::turbo = false;

void Timer::setTurbo( bool on ) {
  Timer::turbo = on;
}

void Timer::wait(long milliseconds) {
  if(Timer::turbo) milliseconds /= 10;
  clock_t limit;
  clock_t now = clock();
  limit = now + milliseconds * CLOCKS_PER_SEC /1000;
  while ( limit > now )
  now = clock();
}
