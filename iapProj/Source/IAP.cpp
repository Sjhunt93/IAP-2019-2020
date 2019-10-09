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
	aserveOscillator(0, 440.0, 1.0, 3);
	aserveSleep(1000);

	aserveClearOscillator(0);
	aserveSleep(1000);

	aserveOscillator(0, 440.0, 1.0, 3);
	aserveSleep(1000);
}

