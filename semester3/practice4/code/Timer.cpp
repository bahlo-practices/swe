#include "Timer.h"

#include <ctime>

void msleep (long milliseconds) {
  clock_t limit;
  clock_t now = clock();
  limit = now + milliseconds * CLOCKS_PER_SEC /1000;
  while ( limit > now )
  now = clock();
}

Timer::Timer() {}

static void Timer::setTurbo( bool turbo ) {
  this.turbo = turbo;
}