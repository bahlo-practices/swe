//@(#) Subject.cpp


#include "Subject.h"

void Subject::attach(Observer* observer)
{
  observers.push_back(observer);
}

void Subject::notify()
{
  int countObservers = observers.size();
  for(int i = 0; i < countObservers;++i) {
    observers.at(i)->update();
  }
}

void Subject::detach(Observer* observer)
{
  int countObservers = observers.size();
  for(int i = 0; i < countObservers;++i) {
    if(observer == observers.at(i)) {
      observers.erase(observers.begin() + i);
      break;
    }
  }
}
