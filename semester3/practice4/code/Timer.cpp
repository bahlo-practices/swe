#include "Timer.h"

#include <ctime>

Timer::Timer() {}

static void Timer::setTurbo( bool turbo ) {
  this::turbo = turbo;
}


static void Timer::sleep (long milliseconds) {
  if(this::turbo) milliseconds /= 10;
  clock_t limit;
  clock_t now = clock();
  limit = now + milliseconds * CLOCKS_PER_SEC /1000;
  while ( limit > now )
  now = clock();
}
