//@(#) Control.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "Control.h"

// Reads ingredients and filters recipe book
Control::Control() {
    // Read ingredients
    readIngredients("zutaten.txt");
    mixableRecipeBook = MixableRecipeBook(&ingredients);
    mixableRecipeBook.printRecipes();
}

// Reads ingredients
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

// Stops the turbo
void Control::stopTurbo() {
    turbo = false;
}

// Starts the turbo
void Control::startTurbo() {
    turbo = true;
}
