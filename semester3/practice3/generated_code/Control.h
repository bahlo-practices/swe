//@(#) Control.h

#ifndef CONTROL_H_H
#define CONTROL_H_H

#include "Scale.h"
#include "DosingFeeder.h"
#include "Pounder.h"
#include "Mixer.h"
#include "MixableRecipeBook.h"
#include "string.h"
//Steuert den Ablauf und weist den Dosierer an
class Control
{
    
public:
    //
    Control();
    //
    void readIngredients();
    //
    void startTurbo();
    //
    void stopTurbo();
    
private:
    //
    bool turbo;
    
    //
    unsigned int uptime;
    
    //
    std::string zutaten;
    
    //
    std::vector<DosingFeeder*> dosingFeeder;
    
    //
    MixableRecipeBook mixableRecipeBook;
    
    //
    Mixer mixer;
    
    //
    Pounder pounder;
    
    //
    Scale scale;
    
    
};

#endif
