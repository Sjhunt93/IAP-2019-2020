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


void IAP::callbackCCValueChanged (int cc, int value)
{
    if (cc >= 51 && cc <= 56) {
        /*
         Set wavetype to be cc-51
         */
    }
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (velocity > 0) {
        /*
         play note
         */
    }
    else {
        /*
         stop note
         */
    }
}
