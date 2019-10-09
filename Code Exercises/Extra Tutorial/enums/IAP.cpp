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

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (velocity > 0) {
        
        float frequency = 440.0 * pow(2.0, (note - 69.0) / 12.0);
        float amp = velocity / 127.0;
        aserveOscillator(0, frequency, amp, waveType);
    }
    else {
        aserveOscillator(0, 0, 0, 0);
    }
}

void IAP::callbackCCValueChanged (int cc, int value)
{
    if (cc == 59) {
        if (value) {
            filterType = 1;
        }
        else {
            filterType = 2;
        }
    }
    if (cc == 21) {
        if (value < 42) {
            waveType = 0;
        }
        else if (value < 84) {
            waveType = 1;
        }
        else {
            waveType = 2;
        }
        
    }

}


void IAP::callbackModWheelMoved (int value)
{
    float fLog = pow(value / 127.0, 3.0);
    float cutoff = fLog * 18000 + 10;
    if (filterType == 1) {
        aserveLPF(cutoff);
    }
    else if (filterType == 2) {
        aserveHPF(cutoff);
    }
}
