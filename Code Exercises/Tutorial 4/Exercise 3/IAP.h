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


class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES

    //---------------------------------------------------------------------------------
    // FUNCTIONS

    void run ();
    
    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS

    void callbackNoteReceived  (int note, int velocity, int channel);
//    void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //void callbackCCValueChanged (int cc, int value);
    

private:

};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
