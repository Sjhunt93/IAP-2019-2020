//
//  Aserve.h
//  IAP DEV 1
//
//  Created by Samuel Hunt on 02/08/2018.
//
//

#ifndef IAP_DEV_1_Aserve_h
#define IAP_DEV_1_Aserve_h

/*
 This file contains all of the aserve OSC commands
 */
namespace AserveOSC
{
    
    static const String aserve = "/aserve/";
    
    static const String note = aserve + "note";
    static const String control = aserve + "control";
    static const String mod = aserve + "modwheel";
    static const String pitchBend = aserve + "pitchbend";
    static const String aftertouch = aserve + "aftertouch";
    static const String pressure = aserve + "channelpressure";
    static const String MIDI = aserve + "midi";
    
    static const String oscilator = aserve + "osc";
    static const String sample = aserve + "sample";
    static const String pitchedSample = aserve + "samplepitch";
    static const String setPixelGrid = aserve + "pixelgrid";
    static const String pixelGridClicked = aserve + "clickedpixelgrid";
    static const String loadsample = aserve + "loadsample";
    static const String loadPitchedSample = aserve + "loadpitchedsample";
    static const String lpf = aserve + "lpf";
    static const String hpf = aserve + "hpf";
    static const String bpf = aserve + "bpf";
    static const String brf = aserve + "brf";
    
    static const String loadDefaultSounds = aserve + "loaddefaults";
    static const String reset = aserve + "reset";
    static const String mode = aserve + "mode";
    static const String pan = aserve + "pan";
    static const String reg = aserve + "register";
    
    static const String fPath = aserve + "path";

}


#endif
