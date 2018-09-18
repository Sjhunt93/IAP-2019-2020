//
//  AserveComs.cpp
//  IAP DEV 1
//
//  Created by Samuel Hunt on 02/08/2018.
//
//

#include "AserveComs.h"
#include "Aserve.h"

AserveComs::AserveComs ()
{
    if (! connect (9001)) {
        //alert
    }
    
    if (! sender.connect ("127.0.0.1", 9002)) {
        //error
    }
    
    // tell the component to listen for OSC messages matching this address:
    addListener (this);

    timeAtStart = Time::getCurrentTime().getMillisecondCounter();
    
    sender.send(AserveOSC::reset);
}
AserveComs::~AserveComs ()
{
    sender.send(AserveOSC::reset);
    removeListener(this);
}

void AserveComs::oscMessageReceived (const OSCMessage& message) 
{
  //  std::cout << message.getAddressPattern().toString() << "\n";

    //this could probably be refactored with string arrays etc..
    
    if (message.getAddressPattern().toString().startsWith(AserveOSC::note)) {
        if (message.size() == 3) {
            //we have to do loads of error checking, dont want asserts being thrown...
            if (message[0].isInt32() && message[1].isInt32() && message[2].isInt32()) {
                const int note = message[0].getInt32();
                const int velocity = message[1].getInt32();
                const int channel = message[2].getInt32();
                callbackNoteReceived(note, velocity, channel);
            }
            
        }
    }
    else if (message.getAddressPattern() == AserveOSC::mod) {
        if (message.size() == 1) {
            if (message[0].isInt32()) {
                const int mod = message[0].getInt32();
                callbackModWheelMoved(mod);
            }
        }
    }
    else if (message.getAddressPattern() == AserveOSC::pressure) {
        if (message.size() == 1) {
            if (message[0].isInt32()) {
                const int pressure = message[0].getInt32();
                callbackPressureValueChanged(pressure);
            }
        }
    }
    else if (message.getAddressPattern() == AserveOSC::control) {
        if (message.size() == 2) {
            if (message[0].getInt32() && message[1].getInt32()) {
                callbackCCValueChanged(message[0].getInt32(), message[1].getInt32());
            }
        }
    }
    else if (message.getAddressPattern() == AserveOSC::pitchBend) {
        if (message.size() == 1) {
            if (message[0].getInt32()) {
                callbackPitchbendWheelMoved(message[0].getInt32());
            }
        }
    }
//    MidiMessage a(<#int byte1#>, <#int byte2#>, <#int byte3#>)
//    if (message.getAddressPattern().matches(const juce::OSCAddress &address)) {
//        
//    }

}

void AserveComs::aserveSleep (int value)
{
    usleep(value * 1000);
}
void AserveComs::aserveOscillator (int channel, float frequency, float amplitude, int wavetype)
{
    sendOsc(channel, frequency, amplitude, wavetype);
}

void AserveComs::sendOsc (const int channel, const float frequency, const float amplitude, const int wavetype)
{
    bool state = sender.send(AserveOSC::oscilator, channel, frequency, amplitude, wavetype) ;
    std::cout << "State : " << state << "\n";
//    if (!) {
//        std::cout << "Error! \n";
//    }
}

void AserveComs::aserveLoadSample (int channel, std::string filePath)
{
    sender.send(AserveOSC::loadsample, channel, String(filePath));
}
void AserveComs::aservePlaySample (int channel, float amplitude)
{
    sender.send(AserveOSC::sample, channel, amplitude);
}

void AserveComs::aserveLoadPitchedSample (int channel, std::string filePath, int originalPitch, float attack, float decay)
{
    sender.send(AserveOSC::loadPitchedSample, channel, String(filePath), originalPitch, attack, decay);
}
void AserveComs::aserveLoadDefaultSounds ()
{
    sender.send(AserveOSC::loadDefaultSounds);
}
void AserveComs::aservePlayPitchedSample (int channel, int note, float amplitude)
{
    sender.send(AserveOSC::pitchedSample, channel, note, amplitude);
}

void AserveComs::aserveLPF (float cutoff)
{
    sender.send(AserveOSC::lpf, cutoff);
}

void AserveComs::aserveBPF (float cutoff, float q, float gain)
{
    sender.send(AserveOSC::bpf, cutoff, q, gain);
}
void AserveComs::aserveBRF (float cutoff, float q, float gain)
{
    sender.send(AserveOSC::brf, cutoff, q, gain);
}


int AserveComs::aserveGetTime ()
{
    return Time::getCurrentTime().getMillisecondCounter() - timeAtStart;
}

void AserveComs::aserveSetPixelGrid (int row, int value)
{
    sender.send(AserveOSC::setPixelGrid, row, value);
}

/*
void AserveComs::sendMIDI (MidiMessage m)
{
    OSCMessage mes(AserveOSC::MIDI, m.getraw);
    sender.send(AserveOSC::MIDI, m);
}


*/