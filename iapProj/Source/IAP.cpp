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
    aserveOscillator(0, 1000.0, 1.0, 0);
    aserveSleep(1000);

}

