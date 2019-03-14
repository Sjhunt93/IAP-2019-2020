
#include "IAP.h"
#include <iostream>

// This is our main function code. Nearly Everything goes in here..

void IAP::run ()
{
    
    while (true) {
        aserveSleep(1000);
    }

}
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    std::cout << "Note Recived: " << note <<  "Velocity: " << velocity << "\n";

    float octave = (not - 69) / 12;
    float power = pow(2, octave);
    float freq = 440 * power;
    aserveOscillator(0, 1.0, freq, 7);
    
}
