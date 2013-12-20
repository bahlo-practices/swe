//@(#) Control.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Control.h"
#include "Timer.h"

using namespace std;

// Constructor
Control::Control() : turbo(false) {
    // Read ingredients
    readIngredients("zutaten2.txt");
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
    if(cocktail > mixableRecipeBook.getAnzahlRezepte()){
      cout << endl << "Dieses Rezept gibt es nicht!" << endl << endl << endl;
      return;
    } else if(cocktail == 0) {
      cout << endl << "Unbekannter Befehl!!!!!!!!11111einseinseinself" << endl << endl << endl;
      return;
    }
    
    // mix it:
    Rezept* recipe = mixableRecipeBook.getRezept(cocktail-1); // recipeBook[0] = Cocktail #1
    if(recipe != NULL) {
        cout << endl << "---------------------------------------------------------" << endl;
        cout << recipe->getName() << endl;
        cout <<  "---------------------------------------------------------" << endl;
        cout << "Dosierer |  Zutat/Aktion   | Menge |     Fortschritt" << endl;
        cout << "-------- | --------------- | ----- | --------------------" << endl;
        for(int recipeStep = 0; recipeStep < recipe->getAnzahlRezeptschritte(); ++recipeStep) {
            Rezeptschritt *step = recipe->getRezeptSchritt(recipeStep);
            int dosingf = ingredients[step->getZutat()];
	    bool isFeeder = (step->getZutat() != "Stampfen" && step->getZutat() != "Mischen");
	    
            cout << setw(8) << left;
	    if(isFeeder) cout << dosingf;
	    else	 cout << "";
	    cout << " | ";
            cout << setw(15) << left << step->getZutat() << " | ";
            cout << setw(5) << step->getMenge() << " | " << flush;

            if(step->getZutat() == "Mischen") {
                mixer.mix(step->getMenge());
            } else if(step->getZutat() == "Stampfen") {
                pounder.pound(step->getMenge());
            } else {
                dosingFeeder[dosingf].dose( *step );
            }

            cout << endl;
        }
        
        // drain it:
	cout << setw(8) << left << "" << " | " << setw(15) << left << "Entleeren" << " | " << setw(5) << "" << " | " << flush;
        mixer.drain();
	
        // clean:
	cout << endl << setw(8) << left << "" << " | " << setw(15) << left << "Säubern" << "  | " << setw(5) << "" << " | " << flush;
        mixer.clean();
	
	
        cout << endl << "---------------------------------------------------------" << endl;

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
