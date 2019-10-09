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
        
        int note = arc4random() % 127;
        int sleep = arc4random() % 500;
             
        aserveOscillator(0, mtof(note), 1.0, 0);
        aserveSleep(sleep);
    }
    
}

float IAP::mtof (int note)
{
    return 440.0 * pow(2.0, (note - 69) / 12.0);
}