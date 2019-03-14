

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
// USER CREATED CLASSES


class Body {
public:
    int x;
    int y;
    bool isActive;
};

class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES
    
    int currentVelocityX = 1;
    int currentVelocityY = 0;
    
    
    //---------------------------------------------------------------------------------
    // FUNCTIONS
    void run ();
    void clearGrid ();
    void initSnake ();
    bool moveSnake ();
    void drawSnake (Body target);
    
    Body getNewTarget ();
    
    std::array<Body, 16> snake;
    
    //---------------------------------------------------------------------------------
    // CALLBACK FUNCTIONS
    
    void callbackNoteReceived  (int note, int velocity, int channel);
    //void callbackModWheelMoved (int value);
    //void callbackPitchbendWheelMoved (int value);
    //    void callbackCCValueChanged (int cc, int value);
    
    //void callbackMIDIRecived (MIDI message);
    //    void callbackPixelGrid (int x, int y);
    
private:
    
};

#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
