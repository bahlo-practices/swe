#include <iostream>
#include <exception>
#include "Control.h"

using namespace std;
int main() {
  try {

    // Create control class
    Control control;

    control.run();

  } catch(string &e) {
    cerr << e << endl;
    return 1;
  } catch(...) {
    cerr << "Ein unbekannter Fehler ist aufgetreten." << std::endl;
    return 2;
  }

  return 0;
}
