//@(#) Control.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "Control.h"
#include "Timer.h"

using namespace std;

// Constructor
Control::Control() : turbo(false) {
    // Read ingredients
    readIngredients("zutaten.txt");
    mixableRecipeBook = MixableRecipeBook(ingredients);

    // Initialize dosingfeeders
    for(int i = 0;i < 10;++i) {
        dosingFeeder[i] = DosingFeeder(scale);
    }

    // Initialize Mixer
    mixer = Mixer(scale);
}

// Read ingredients
void Control::readIngredients(const string& filename) {
    ifstream in;

    in.open(filename.c_str());
    if( !in ) throw "Zutaten-Datei (" + filename + ") wurde nicht gefunden";

	string ingredient;
	int feeder = 0;
	while (getline(in, ingredient)) if (ingredient.length() > 2) ingredients.insert(make_pair(ingredient, feeder++));

    in.close();
}

void Control::run(){
    string input = "";
    int cocktail = 0;
    string prompt = "Cocktail wählen (q zum Beenden, t für Turbo): ";

    // show all available cocktails:
    mixableRecipeBook.printRecipes();

    // get user's choice:
    if(turbo) cout << "Turbo-";
    cout << prompt;
    cin >> input;

    while(input.at(0) == 't') {
        if(!turbo) {
            startTurbo();
            cout << "Turbo-";
        } else stopTurbo();
        cout << prompt;
        cin >> input;
    }

    if(input.at(0) == 'q') exit(0);
    cocktail = atoi(&input.at(0));

    // mix it:
    Rezept* recipe = mixableRecipeBook.getRezept(cocktail-1); // recipeBook[0] = Cocktail #1
    if(recipe != NULL) {
        cout << "Zutaten für "<< recipe->getName() << endl;
        for(int recipeStep = 0; recipeStep < recipe->getAnzahlRezeptschritte(); recipeStep++) {
            Rezeptschritt *step = recipe->getRezeptSchritt(recipeStep);
            int dosingf = ingredients[step->getZutat()];
            cout << "#" << dosingf << ": " << step->getMenge() << endl;
			dosingFeeder[dosingf].dose( *step );
        }

        // drain it:
        mixer.drain();

        // clean:
        mixer.clean();
    } else throw "Fehler: Ungültige Eingabe.";
    cout << endl << endl; // Next run!
}

// Stop turbo
void Control::stopTurbo() {
    Timer::setTurbo((turbo = false));
}

// Start turbo
void Control::startTurbo() {
    Timer::setTurbo((turbo = true));
}

//
void Control::update()
{

}
