/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
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

