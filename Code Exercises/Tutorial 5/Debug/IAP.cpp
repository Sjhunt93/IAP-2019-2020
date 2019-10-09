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
    
    /*
     The following program gives intructions to the user depending on the time of day entered.
     
     If the time of day is after 600 then the program should print "open windows"
     If the time of day is after 900 but before 2000 then the program should print "unlock doors"
     If the time of day is after 1800 then the program should print "close windows"
     If the time of day is after 2000 then the program should print "lock doors"
     If the time of day is after 2200 then the program should print "set alarm"
     
     You need to fix the following broken program.
     
     There are both compile time errors x3
     and run time errors x2
     
     */
    
    int timeOfDay;

    std::cout << "Enter time of day: \n";
    std::cin >> time;
    
    std::cout << "Tasks to do are as follows:\n";

    if (timeOfDay < 1800)
    {
        std::cout << "close windows\n";
    }
    else if (timeOfDay > 600)
    {
        std::cout << "open windows\n";
    }
    
    if (timeOfDay > 900 ) {
        if (timeOfDay < 2000) {
            std::cout << "unlock doors\n";
        }
        if else (timeOfDay > 2000) {
            std::cout << "lock windows\n";
        }
        
    }
    
    if (timeOfDay > 2200) {
        std::cout "set alarm\n";
    }
    
    
}
