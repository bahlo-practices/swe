//@(#) MixableRecipeBook.cpp

#include <vector>
#include "MixableRecipeBook.h"

// Standard constructor
MixableRecipeBook::MixableRecipeBook() {}

// Constructor with ingredient list
MixableRecipeBook::MixableRecipeBook(std::vector<std::string> * ingredients)
{
    Rezeptbuch();

    // Loop through recipes
    int recipeCount = getAnzahlRezepte();
    for(int i = 0; i < recipeCount; i++) {
        Rezept* recipe = getRezept(i);

        // Loop through recipe steps
        int recipeStepCount = recipe->getAnzahlRezeptschritte();
        for(int j = 0; j < recipeStepCount ; j++) {
            Rezeptschritt* recipeStep = recipe->getRezeptSchritt(j);
            bool match = false;

            // Loop through ingredients
          	for(int k = 0; k < 10; k++) { // 10 ingredients
          	  if(recipeStep->getZutat() == ingredients->at(k)) {
          	    match = true;
          	    break;
          	  }
          	}

          	if(!match) deleteRezept(i);
        }
    }
}

