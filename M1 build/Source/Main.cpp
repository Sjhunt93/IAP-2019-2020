/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "IAP.h"

//==============================================================================
int main (int argc, char* argv[])
{

    ScopedJuceInitialiser_GUI scopedJuceGui;
    
    File f = File::getSpecialLocation(File::SpecialLocationType::currentExecutableFile).getParentDirectory();
    f.setAsCurrentWorkingDirectory();
    
    IAP iap;
    iap.run();
    return 0;
}
