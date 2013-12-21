#include <iostream>
#include <iomanip>
#include <exception>
#include "Control.h"

using namespace std;

int main() {
  setlocale(0,"DE");

  try {
    // Create control class
    Control control;

    while(true) control.run();

  } catch(const string &e) {
    cerr << e << endl;
    return 1;
  } catch(const std::exception &e) {
    cerr << e.what() << endl;
  } catch(...) {
    cerr << "Ein unbekannter Fehler ist aufgetreten." << endl;
    return 2;
  }

  return 0;
}
