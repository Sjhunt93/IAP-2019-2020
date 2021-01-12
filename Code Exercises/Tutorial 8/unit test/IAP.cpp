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
    while (modwheelVal == 0) {
        aserveSleep(100);
    }
    
    //insert your high frequency test here.
}

void IAP::callbackModWheelMoved (int value)
{
    //set modwheelVal here
}
