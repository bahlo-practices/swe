#include <iostream>
#include <exception>
#include "Control.h"

using namespace std;

int main() {
  try {
    // Create control class
    Control control;

    cout << endl;
    cout << "   ______           __   __        _ ______" << endl;
    cout << "  / ____/___  _____/ /__/ /_____ _(_) / __ \\_________" << endl;
    cout << " / /   / __ \\/ ___/ //_/ __/ __ `/ / / /_/ / ___/ __ \\" << endl;
    cout << "/ /___/ /_/ / /__/ ,< / /_/ /_/ / / / ____/ /  / /_/ /" << endl;
    cout << "\\____/\\____/\\___/_/|_|\\__/\\__,_/_/_/_/   /_/   \\____/" << endl << endl;

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
