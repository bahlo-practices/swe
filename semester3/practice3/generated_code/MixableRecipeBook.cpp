//@(#) MixableRecipeBook.cpp

#include <vector>

#include "MixableRecipeBook.h"

//
MixableRecipeBook::MixableRecipeBook() 
{
  // Fuck this shit
}

//
MixableRecipeBook::MixableRecipeBook(vector<string>* ingredients)
{
    Rezeptbuch();
    
    int recipeCount = getAnzahlRezepte();
    for(int i = 0; i < recipeCount; i++) {
      Rezept* recipe = getRezept(i);
      
      int recipeStepCount = recipe->getAnzahlRezeptschritte();
      for(int j = 0; j < recipeStepCount ; j++) {
	Rezeptschritt* recipeStep = recipe->getRezeptSchritt(j);
	bool match = false;
	
	for(int k = 0; k < 10; k++) { // 10 ingredients
	  if(recipeStep->getZutat() == ingredients->at(k)) {
	    match = true;
	    break;
	  }
	}
	
	if(!match) {
	  deleteRezept(i);
	}
      }
    }
}

