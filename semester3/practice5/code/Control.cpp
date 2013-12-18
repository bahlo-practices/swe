//@(#) Control.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "Control.h"

using namespace std;

// Constructor
Control::Control() {
    // Read ingredients
    readIngredients("zutaten.txt");
    mixableRecipeBook = MixableRecipeBook(ingredients);
}

// Read ingredients
void Control::readIngredients(const string& filename) {
    ifstream in;

    in.open(filename.c_str());
    if( !in ) throw "File not found: " + filename;

	string ingredient;
	int feeder = 0;
	while (getline(in, ingredient)) if (ingredient.length() > 2) ingredients.insert(make_pair(ingredient, feeder++));

    in.close();
}

void Control::run(){
    // show all available cocktails:
    mixableRecipeBook.printRecipes();

    // get user's choice:
    cout << "Cocktail wählen (0 zum Beenden): ";
    int cocktail;
    cin >> cocktail;

    if(cocktail == 0) exit(0);

    // mix it:
    Rezept* recipe = mixableRecipeBook.getRezept(cocktail-1); // recipeBook[0] = Cocktail #1
    if(recipe != NULL) {
        cout << "Zutaten für "<< recipe->getName() << endl;
        for(int recipeStep = 0; recipeStep < recipe->getAnzahlRezeptschritte(); recipeStep++) {
            int dosingf = ingredients[ recipe->getRezeptSchritt(recipeStep)->getZutat() ];
            cout << "#" << dosingf << ": " << recipe->getRezeptSchritt(recipeStep)->getMenge() << endl;
            //#### MISSING #####
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
    turbo = false;
}

// Start turbo
void Control::startTurbo() {
    turbo = true;
}

//
void Control::update()
{

}
