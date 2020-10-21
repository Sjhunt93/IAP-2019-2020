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
    
    AserveTests aTests;
    
    aTests.testOscRegisters(*this);
    
    while (true) {
        aserveSleep(1000);
    }
    
    aserveOscillator(0, 440.0, 1.0, 2);
    aserveSleep(4000);
    aserveOscillator(0, 0, 0, 0);
    aserveSleep(1000);
    
    for (int i = 0; i < 24; i++) {
        aserveSetRegister(0x10+i, 100+i*100);
        aserveSetRegister(0x30+i, 0.5);
        aserveSleep(100);
    }
    
    
    
}
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    aserveOscillator(0, 440.0 * pow(2.0, (note-69.0)/12.0), velocity/127.0, 1);
    
}

void IAP::callbackCCValueChanged (int cc, int value)
{
    
}
