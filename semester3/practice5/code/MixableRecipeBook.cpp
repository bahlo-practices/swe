//@(#) MixableRecipeBook.cpp
#include <iostream>
#include <map>

#include "MixableRecipeBook.h"

using namespace std;

// Standard constructor
MixableRecipeBook::MixableRecipeBook() {
  Rezeptbuch();
}

// Constructor with ingredient list
MixableRecipeBook::MixableRecipeBook(const map<string, int>& ingredients) {
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

		string ingredient = recipeStep->getZutat();
		if(ingredients.find(ingredient) != ingredients.end() || ingredient == "Mischen" || ingredient == "Stampfen") continue;

		// Ingredient not found, bye
		deleteRezept(i);
		recipeCount--;
		break;
    }
  }
}

// Print recipes
void MixableRecipeBook::printRecipes() {
  int recipeCount = getAnzahlRezepte();
  std::cout << "Verfügbare Rezepte: " << std::endl;
  for(int i = 0;i < recipeCount;++i) {
    Rezept *recipe = getRezept(i);
    std::cout << i+1 << ") " << recipe->getName() << std::endl;
  }
  std::cout << std::endl;
}
