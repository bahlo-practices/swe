//@(#) Control.cpp

#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "Control.h"

using namespace std;

// Constructor
Control::Control()
{    
    // Read ingredients
    readIngredients("zutaten.txt");
    mixableRecipeBook = MixableRecipeBook(ingredients);
}

//
void Control::readIngredients(std::string filename)
{
    ifstream in;

    in.open(filename.c_str(), ios::in);

    if( !in ) {
	string my_exception = "File not found: " + filename;
	throw my_exception;
    }

    string zeile;
    while(getline(in, zeile)){
	ingredients->push_back(zeile);
    }

    in.close();
}

//
void Control::stopTurbo()
{
    turbo = false;
}

//
void Control::startTurbo()
{
    turbo = true;
}
