//
//  IAP.h
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

//---------------------------------------------------------------------------------
// USER CREATED CLASS


class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES (IAP member variables)
    

    //---------------------------------------------------------------------------------
    // FUNCTIONS (IAP class methods)
    void run ();

    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    
    //void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackCCValueChanged (int cc, int value);
    
    //void callbackMIDIReceived (MIDI message);
    //void callbackPixelGrid (int x, int y);
    


	//---------------------------------------------------------------------------------
	// WINDOWS ONLY

#ifdef JUCE_WINDOWS
	void aserveLoadDefaultSounds()
	{
		//make sure you set these to be your own file paths
		aserveLoadSample(0, "C:\\Users\\Sam\\Desktop\\IAP 2018\\IAP-2018-2019\\sounds\\bd.wav");
		aserveLoadSample(1, "C:\\Users\\Sam\\Desktop\\IAP 2018\\IAP-2018-2019\\sounds\\sd.WAV");
		aserveLoadSample(2, "C:\\Users\\Sam\\Desktop\\IAP 2018\\IAP-2018-2019\\sounds\\chh.WAV");
		aserveLoadSample(3, "C:\\Users\\Sam\\Desktop\\IAP 2018\\IAP-2018-2019\\sounds\\ohh.WAV");
		aserveLoadPitchedSample(0, "C:\\Users\\Sam\\Desktop\\IAP 2018\\IAP-2018-2019\\sounds\\pianoSample.WAV", 60, 0.01, 0.3);
	}
#endif // JUCE_WINDOWS



private:
    
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
