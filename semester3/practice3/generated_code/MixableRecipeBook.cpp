//@(#) MixableRecipeBook.cpp
#include <iostream>
#include <vector>

#include "MixableRecipeBook.h"

// Standard constructor
MixableRecipeBook::MixableRecipeBook() {
  Rezeptbuch();
}

// Constructor with ingredient list
MixableRecipeBook::MixableRecipeBook(std::vector<std::string> *ingredients) {
  Rezeptbuch();

  // Loop through recipes
  int recipeCount = getAnzahlRezepte();
  for(int i = 0; i < recipeCount; ++i) {
    Rezept* recipe = getRezept(i);

    // Loop through recipe steps
    int recipeStepCount = recipe->getAnzahlRezeptschritte();

    // If there are no steps, don't even try
    if(recipeStepCount == 0) {
      deleteRezept(i);
      recipeCount--;
      continue;
    }

    // Loop through steps
    for(int j = 0; j < recipeStepCount; ++j) {
      Rezeptschritt* recipeStep = recipe->getRezeptSchritt(j);
      bool match = false;

      // Loop through ingredients
      int ingredientCount = ingredients->size();
    	for(int k = 0; k < ingredientCount; ++k) {
        std::string ingredient = recipeStep->getZutat();
    	  if(ingredient == ingredients->at(k) || ingredient == "Mischen" || ingredient == "Stampfen") {
    	    match = true;
          break;
    	  }
    	}

      // Ingredient not found, bye
      if(!match) {
        deleteRezept(i);
        recipeCount--;
      }
    }
  }
}

// Print recipes
void MixableRecipeBook::printRecipes() {
  int recipeCount = getAnzahlRezepte();
  std::cout << "=================" << std::endl;
  for(int i = 0;i < recipeCount;++i) {
    Rezept *recipe = getRezept(i);
    std::cout << recipe->getName() << std::endl;
    std::cout << "-----------------" << std::endl;
    int stepCount = recipe->getAnzahlRezeptschritte();
    for(int j = 0;j < stepCount;++j) {
        Rezeptschritt *step = recipe->getRezeptSchritt(j);
        std::cout << "- " << step->getZutat() << std::endl;
    }
    std::cout << "=================" << std::endl;
  }
}
