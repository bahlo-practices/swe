//@(#) Control.h

#ifndef CONTROL_H_H
#define CONTROL_H_H

#include <vector>
#include <string>

#include "Scale.h"
#include "DosingFeeder.h"
#include "Pounder.h"
#include "Mixer.h"
#include "MixableRecipeBook.h"

using namespace std;

//Steuert den Ablauf und weist den Dosierer an
class Control
{
    
public:
    //
    Control();
    //
    void readIngredients(string);
    //
    void startTurbo();
    //
    void stopTurbo();
    
private:
    //
    bool turbo;
    
    //
    vector<string>* ingredients;
    
    //
    DosingFeeder dosingFeeder[10];
    
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
