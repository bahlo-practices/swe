//@(#) MixableRecipeBook.cpp

#include <vector>

#include "MixableRecipeBook.h"

//
vector<Rezept> MixableRecipeBook::getReceipes()
{
    return m_Rezepte;
}

//
MixableRecipeBook::MixableRecipeBook() 
{
  // Fuck this shit
}

//
MixableRecipeBook::MixableRecipeBook(vector<string>* ingredients)
{
    new Rezeptbuch(); // Chris' fault
    int ingredientsCount = ingredients.size();
    
    for(int i = 0, int length = getAnzahlRezepte(); i < length; i++) {
      Rezept recipe = m_Rezepte.at(i);
      
      for(int j = 0, int length = recipe.getAnzahlRezeptschritte(); j < length; j++) {
	Rezeptschritt recipeStep = recipe.getRezeptschritt(j);
	bool match = false;
	
	for(int k = 0; k < ingredientsCount; k++) {
	  if(recipeStep.m_Zutat == ingredients.at(k)*) {
	    match = true;
	    break;
	  }
	}
	
	if(!match) {
	  m_Rezepte.erase(m_Rezepte.end() - i);
	}
      }
    }
}

