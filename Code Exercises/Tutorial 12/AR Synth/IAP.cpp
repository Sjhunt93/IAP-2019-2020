//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>

// This is our main function code.

void IAP::run ()
{

    /* #
     set attack and release times to be 0.01
     */
    
    /* #
     create local variable called ramp value
     */
    
    
    while (true) { //loop
        
      
        /* #
          if ramp state is 1
            increase ramp value by attack time
         
            if ramp value exceeds 1
                fix ramp value to 1
                set ramp state to 2
         */
        
        
        /* #
         if ramp state is 3
         
          - decrease ramp value
          - once ramp value is 0, switch of oscillator, reset current note, reset ramp state
         
         */
        
        /* #
         switch on oscillator, think carefully about what values the function should take
         */
        
        aserveSleep(1);
        
    }
    
}

void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    /* #
      if note is on
        store current note
        set ramp state to 1
     else
        check to see if note equals current note
            set ramp state to 3
     */

}


void IAP::callbackCCValueChanged (int cc, int value)
{
    /* #
     - pick two rotary controls
     - set the attack & release time based on the following formula

      Y = 1.0 / ((X / 127.0) * 1000.0) + 0.00001;
     */
}
