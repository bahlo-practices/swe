#include <iostream>
#include <exception>
#include "Control.h"

using namespace std;

int main() {
  try {
    // Create control class
    Control control;

    // Banner, because we're faboulus
    cout << endl;
    cout << "  _____           _    _        _ _ _____           " << endl;
    cout << " / ____|         | |  | |      (_) |  __ \\          " << endl;
    cout << "| |     ___   ___| | _| |_ __ _ _| | |__) | __ ___  " << endl;
    cout << "| |    / _ \\ / __| |/ / __/ _` | | |  ___/ '__/ _ \\ " << endl;
    cout << "| |___| (_) | (__|   <| || (_| | | | |   | | | (_) |" << endl;
    cout << " \\_____\\___/ \\___|_|\\__\\__\\__,_|_|_|_|   |_|  \\___/ " << endl << endl;

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
