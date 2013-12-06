//@(#) Control.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "Control.h"

// Constructor
Control::Control() {
    // Read ingredients
    readIngredients("zutaten.txt");
    mixableRecipeBook = MixableRecipeBook(&ingredients);
    mixableRecipeBook.printRecipes();
}

// Read ingredients
void Control::readIngredients(std::string filename) {
    ifstream in;

    in.open(filename.c_str(), ios::in);

    if( !in ) {
	   throw "File not found: " + filename;
    }

    std::string zeile;
    while(getline(in, zeile)){
	    ingredients.push_back(zeile);
    }

    in.close();
}

// Stop turbo
void Control::stopTurbo() {
    turbo = false;
}

// Start turbo
void Control::startTurbo() {
    turbo = true;
}
