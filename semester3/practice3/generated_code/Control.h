#include <vector>
#include <string>
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
    
    // Constructor
    Control();
    
    //
    void readIngredients(std::string filename);
    
    //
    void startTurbo();
    
    //
    void stopTurbo();
    private:
    
    //
    DosingFeeder dosingFeeder[10];
    
    //
    std::vector<std::string> * ingredients;
    
    //
    MixableRecipeBook mixableRecipeBook;
    
    //
    Mixer mixer;
    
    //
    Pounder pounder;
    
    //
    Scale scale;
    
    //
    bool turbo;
    
};
