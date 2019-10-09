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
    /* declare vector */
    int exit = 0;
    do {
        
        std::cout << "Enter a number";
        int num;
        std::cin >> num;
        
        /* push_back num */
        
        std::cout << "Would you like to exit, enter 0 to exit, enter 1 to continue";
        std::cin >> exit;
        
    } while (exit != 0);
    
    int sum = 0;
    
    for (int i = 0; i < /* vector size */ ; i++) {
        sum += // each element from the vector
    }
    std::cout << "Average is : " << sum / /* vector size */ << "\n";
}