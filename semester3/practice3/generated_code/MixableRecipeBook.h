//@(#) MixableRecipeBook.h

#ifndef MIXABLERECIPEBOOK_H_H
#define MIXABLERECIPEBOOK_H_H

#include "Rezeptbuch.h"
#include "string.h"
//Stellt alle mischbaren Rezepte bereit
class MixableRecipeBook: public Rezeptbuch
{
    
public:
    //
    Rezept getReceipes();
    //
    MixableRecipeBook(std::string ingredients);
    
};

#endif
