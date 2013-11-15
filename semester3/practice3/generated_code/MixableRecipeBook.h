//@(#) MixableRecipeBook.h

#ifndef MIXABLERECIPEBOOK_H_H
#define MIXABLERECIPEBOOK_H_H

#include "Rezeptbuch.h"
#include <string>

//Stellt alle mischbaren Rezepte bereit
class MixableRecipeBook: public Rezeptbuch
{
    
public:
    //
    vector<Rezept> getReceipes();
    //
    MixableRecipeBook();
    MixableRecipeBook(vector<string>* ingredients);
    
};

#endif

