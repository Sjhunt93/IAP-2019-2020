//
//  AserveTests.cpp
//  iapProj (ConsoleApp)
//
//  Created by Samuel Hunt on 10/12/20.
//

#include "AserveTests.hpp"

//AserveTests::AserveTests (AserveComs & _coms) : coms(_coms)
//{
//
//}

void AserveTests::testOscRegisters (AserveComs & coms)
{
    
    const int startChan = 0;
    const int endChan = 2;
    
    ///------------------------- Oscialltor --------------------------------------------------
#if 0
    for (int chan = startChan; chan < endChan; chan++) {
        coms.aserveSetRegister(0x30+chan, 0.3);
        for (float f = 0; f < 44100/2; f+=30) {
            coms.aserveSetRegister(0x10+chan, f);
            coms.aserveSleep(1);
        }
    }
#endif
    ///------------------------- Amp --------------------------------------------------
    
#if 0
    
    coms.aserveSetRegister(0x0, 0);
    for (int chan = startChan; chan < endChan; chan++) {
        coms.aserveSetRegister(0x10+chan, 440.0);
        for (float f = 0; f < 1.0; f += 0.001) {
            coms.aserveSetRegister(0x30+chan, f);
            coms.aserveSleep(1);
        }
        coms.aserveSetRegister(0x30+chan, 0);
        
    }
#endif
    
    ///------------------------- Wave --------------------------------------------------
    
#if 0
    coms.aserveSetRegister(0x0, 0);
    for (int chan = startChan; chan < endChan; chan++) {
        coms.aserveSetRegister(0x10+chan, 440.0);
        coms.aserveSetRegister(0x30+chan, 1.0);
        for (int w = 0; w < 6; w++) {
            coms.aserveSetRegister(0x50+chan, w);
            coms.aserveSleep(100);
        }
        coms.aserveSetRegister(0x30+chan, 0);
        
    }
#endif
    
#if 0
    coms.aserveSetRegister(0x0, 0);
    for (int chan = startChan; chan < endChan; chan++) {
        coms.aserveSetRegister(0x10+chan, 440.0);
        coms.aserveSetRegister(0x30+chan, 1.0);
        coms.aserveSetRegister(0x50+chan, 0);
        for (float f = -1.0; f <= 1.0; f += 0.003) {

            coms.aserveSetRegister(0x70+chan, f);
            coms.aserveSleep(1);
        }
        coms.aserveSetRegister(0x30+chan, 0);
        
    }
#endif
    
#if 0 //attack
    coms.aserveSetRegister(0x0, 0);
    for (int chan = startChan; chan < endChan; chan++) {
        
        for (float f = 0; f <= 1.0; f += 0.25) {

        
            coms.aserveOscillator(chan, 0, 0, 0);
            coms.aserveSetRegister(0x90+chan, 1.0-f);
            
        
            coms.aserveSetRegister(0x10+chan, 440.0);
            coms.aserveSetRegister(0x30+chan, 1.0);
            coms.aserveSetRegister(0x50+chan, 0);
            
            coms.aserveSleep(1000);
            coms.aserveOscillator(chan, 0, 0, 0);
            coms.aserveSleep(10);

        }
        
        
    }
#endif
    
    
#if 1 //release
    coms.aserveSetRegister(0x0, 0);
    for (int chan = startChan; chan < endChan; chan++) {
        
        for (float f = 0; f <= 1.0; f += 0.25) {
            
            
            coms.aserveOscillator(chan, 0, 0, 0);
            coms.aserveSetRegister(0xB0+chan, 1.0-f);
            
            
            coms.aserveSetRegister(0x10+chan, 440.0);
            coms.aserveSetRegister(0x30+chan, 1.0);
            coms.aserveSetRegister(0x50+chan, 0);
            
            coms.aserveSleep(500);
            coms.aserveOscillator(chan, 440.0, 0, 0); 
            coms.aserveSleep(1000);
            
        }
        
        
    }
#endif
    
}
