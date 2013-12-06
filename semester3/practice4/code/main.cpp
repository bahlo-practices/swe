#include <iostream>
#include <exception>
#include "Control.h"

int main() {
  try {
    // Create control class
    Control control;
  } catch(std::string &e) {
    std::cerr << e << std::endl;
    return 1;
  } catch(...) {
    std::cerr << "Ein unbekannter Fehler ist aufgetreten." << std::endl;
    return 2;
  }

  return 0;
}
