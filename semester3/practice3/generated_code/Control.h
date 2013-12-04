#include <vector>
#include <string>
#include "Scale.h"
#include "DosingFeeder.h"
#include "Pounder.h"
#include "Mixer.h"
#include "MixableRecipeBook.h"
#include "string.h"

// Steuert den Ablauf und weist den Dosierer an
class Control
{
public:
    // Constructor
    Control();
    // Read ingredients
    void readIngredients(std::string filename);
    // Start turbo
    void startTurbo();
    // Stop turbo
    void stopTurbo();

private:
    // The 10 dosing feeders
    DosingFeeder dosingFeeder[10];
    // The ingredients
    std::vector<std::string> * ingredients;
    // The recipe book
    MixableRecipeBook mixableRecipeBook;
    // The mixer
    Mixer mixer;
    // The pounder
    Pounder pounder;
    // The scale
    Scale scale;
    // Turbomode?
    bool turbo;
};
