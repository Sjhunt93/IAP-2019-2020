//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>

// This is our main function code. Nearly Everything goes in here..

void IAP::run ()
{
    while (true) {
        aserveSleep(1000);
    }
}

void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
    float freq = 440.0 * pow(2.0, (note-69)/12.0);
    aserveOscillator(0, freq, 1.0, 0);
}









