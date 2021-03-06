#include "string.h"
#include <map>
#include <string>
#include "Scale.h"
#include "DosingFeeder.h"
#include "Pounder.h"
#include "Mixer.h"
#include "MixableRecipeBook.h"

using namespace std;

//
class Control // controls workflow
{
    public:
    // Constructor
    Control();

    // control workflow
    void run();

    // Read ingredients
    void readIngredients(const std::string & filename);

    // Start turbo
    void startTurbo();

    // Stop turbo
    void stopTurbo();

    //
    void update();
    private:
    // The 10 dosing feeders
    DosingFeeder dosingFeeder[10];

    // The ingredients
    std::map<std::string, int> ingredients;

    // The recipe book
    MixableRecipeBook mixableRecipeBook;

    // The mixer
    Mixer mixer;

    // The pounder
    Pounder pounder;

    //
    Scale scale;

    // Turbomode?
    bool turbo;

};
