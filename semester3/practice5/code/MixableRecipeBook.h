//@(#) MixableRecipeBook.h

#ifndef MIXABLERECIPEBOOK_H_H
#define MIXABLERECIPEBOOK_H_H

#include <string>
#include <map>
#include "Rezeptbuch.h"

// Provides mixable recipe book
class MixableRecipeBook: public Rezeptbuch {
public:
    // Standard constructor
    MixableRecipeBook();
    // Constructor with ingredient list
    MixableRecipeBook(const map<string, int>& ingredients);

    // Print recipes
    void printRecipes();
};

#endif
