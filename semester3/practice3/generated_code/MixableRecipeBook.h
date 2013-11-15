//@(#) MixableRecipeBook.h

#ifndef MIXABLERECIPEBOOK_H_H
#define MIXABLERECIPEBOOK_H_H

#include "string.h"
#include "Rezeptbuch.h"
#include <string>

//Stellt alle mischbaren Rezepte bereit
class MixableRecipeBook: public Rezeptbuch
{
    
public:
    //
    MixableRecipeBook();
    //
    MixableRecipeBook(std::vector<std::string> * ingredients);
    
};

#endif
