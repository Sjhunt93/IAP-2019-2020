//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>

float IAP::mtof (int note)
{
    return 440.0 * pow(2.0, (note - 69) / 12.0);
}


void IAP::run ()
{
    while (true) {
        aserveSleep(1000);
    }
}

void callbackNoteReceived  (int note, int velocity, int channel)
{
    
}
