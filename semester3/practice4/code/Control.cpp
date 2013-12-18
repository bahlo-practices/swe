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
    mixableRecipeBook.printRecipes();
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
