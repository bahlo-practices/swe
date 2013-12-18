#include <iostream>
#include <exception>
#include "Control.h"

using namespace std;
int main() {
  try {
    // Create control class
    Control control;

    // Banner, because we're faboulus
    std::cout << std::endl;
    std::cout << "  _____           _    _        _ _ _____           " << std::endl;
    std::cout << " / ____|         | |  | |      (_) |  __ \\          " << std::endl;
    std::cout << "| |     ___   ___| | _| |_ __ _ _| | |__) | __ ___  " << std::endl;
    std::cout << "| |    / _ \\ / __| |/ / __/ _` | | |  ___/ '__/ _ \\ " << std::endl;
    std::cout << "| |___| (_) | (__|   <| || (_| | | | |   | | | (_) |" << std::endl;
    std::cout << " \\_____\\___/ \\___|_|\\__\\__\\__,_|_|_|_|   |_|  \\___/ " << std::endl << std::endl;

    while(true) control.run();

  } catch(string &e) {
    cerr << e << endl;
    return 1;
  } catch(...) {
    cerr << "Ein unbekannter Fehler ist aufgetreten." << endl;
    return 2;
  }

  return 0;
}
