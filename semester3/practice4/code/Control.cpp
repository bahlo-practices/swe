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

    string line;
    while(getline(in, line)) if(line.length > 2) ingredients.push_back(line);

    in.close();
}

void Control::run(){
    // show all available cocktails:
    mixableRecipeBook.printRecipes();

    // get user's choice:
    cout << "Mische Cocktail #";
    int cocktail;
    cin >> cocktail;

    // mix it:
    Rezept recipe = mixableRecipeBook.getRezept(cocktail-1); // recipeBook[0] = Cocktail #1
    for(int recipeStep = 0; recipeStep < recipe.getAnzahlRezeptschritte(); recipeStep++) {
        cout << "step " << recipeStep;
        //#### MISSING #####
    }

    // drain it:
    mixer.drain();

    // clean:
    mixer.clean();
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
