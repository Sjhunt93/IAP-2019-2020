//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>

void IAP::run ()
{
    while (true) {
        aserveSleep(1000);
    }
}

void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
    float f = 440.0 * pow(2.0, ((note-69.0) / 12.0));
    aserveOscillator(0, f, 1.0, 0);
}
