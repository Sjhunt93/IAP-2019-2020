//
//  AserveTests.cpp
//  iapProj (ConsoleApp)
//
//  Created by Samuel Hunt on 10/12/20.
//

#include "AserveTests.hpp"


void AserveTests::testOscRegisters (AserveComs & coms)
{
    
#if 1
    const int startChan = 0;
    const int endChan = 2;
#endif
    ///------------------------- Oscialltor --------------------------------------------------
#if 1
    for (int chan = startChan; chan < endChan; chan++) {
        coms.aserveSetRegister(0x30+chan, 0.3);
        for (float f = 0; f < 44100/2; f+=30) {
            coms.aserveSetRegister(0x10+chan, f);
            coms.aserveSleep(1);
        }
    }
#endif
    ///------------------------- Amp --------------------------------------------------
    
#if 1
    
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
    
#if 1
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
    ///------------------------- Pan --------------------------------------------------
#if 1
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
    
    
    ///------------------------- Attack --------------------------------------------------
    
#if 1
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
    
    ///------------------------- Release --------------------------------------------------
    
#if 1
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

    ///------------------------- Filters --------------------------------------------------
#if 1
    coms.aserveSetRegister(0x0, 0);
    coms.aserveOscillator(0, 440.0, 0.7, 2);
    for (float f = 20000; f > 20; f-=10) {
        coms.aserveSetRegister(0x100, f);
        coms.aserveSleep(1);
    }
    coms.aserveSetRegister(0x100, 20000);
    for (float f = 20; f < 20000; f+=10) {
        coms.aserveSetRegister(0x101, f);
        coms.aserveSleep(1);
    }
#endif
    
    
    ///------------------------- BitGrid --------------------------------------------------
    
#if 1
    coms.aserveSetRegister(0x0, 0);
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x200+i, 1.0);
        coms.aserveSleep(10);
    }
    //red
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x300+i, i);
        coms.aserveSleep(10);
    }
    //red reset
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x300+i, 0);
    }
    
    // green
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x400+i, i);
        coms.aserveSleep(10);
    }
    
    // green reset
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x400+i, 0);
    }
    
    // blue
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x500+i, i);
        coms.aserveSleep(10);
    }
    
    // blue
    for (int i = 0; i < 256; i++) {
        coms.aserveSetRegister(0x500+i, 0);
    }
    
	Random r;
    for (int i = 0; i < 10000; i++) {
        const int randomA = (abs(r.nextInt()) % 0x300) + 0x300;
        const int colour = abs(r.nextInt()) % 256;
		jassert(randomA < 0x600);
		jassert(randomA >= 0x300);
        coms.aserveSetRegister(randomA, colour);
        coms.aserveSleep(1);
    }
    
#endif

    
}
