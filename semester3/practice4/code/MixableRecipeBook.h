//@(#) MixableRecipeBook.h

#ifndef MIXABLERECIPEBOOK_H_H
#define MIXABLERECIPEBOOK_H_H

#include "string.h"
#include <string>
#include <vector>
#include "Rezeptbuch.h"

// Provides mixable recipe book
class MixableRecipeBook: public Rezeptbuch {
public:
    // Standard constructor
    MixableRecipeBook();
    // Constructor with ingredient list
    MixableRecipeBook(std::vector<std::string> * ingredients);

    // Print recipes
    void printRecipes(void);
};

#endif
