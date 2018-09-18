//
//  AserveComs.h
//  IAP DEV 1
//
//  Created by Samuel Hunt on 02/08/2018.
//
//

#ifndef __IAP_DEV_1__AserveComs__
#define __IAP_DEV_1__AserveComs__

#include "../JuceLibraryCode/JuceHeader.h"
#include <array>
#include <string>

class AserveComs :
private OSCReceiver,
private OSCReceiver::Listener<OSCReceiver::RealtimeCallback>
{
public:

    //------------------------------------------------------------------------------------------
    
    void aserveSleep (int value);
    void aserveOscillator (int channel, float frequency, float amplitude, int wavetype);
    
    void aserveLoadSample (int channel, std::string filePath);
    void aservePlaySample (int channel, float amplitude);
    void aserveLoadPitchedSample (int channel, std::string filePath, int originalPitch, float attack, float decay);
    void aservePlayPitchedSample (int channel, int note, float amplitude);
    void aserveLoadDefaultSounds ();
    
    void aserveLPF (float cutoff);
    void aserveBPF (float cutoff, float q, float gain);
    void aserveBRF (float cutoff, float q, float gain);
    
    int aserveGetTime ();
    
    void aserveSetPixelGrid (int row, int value);
    
    /*
     Callback Functions:
        To use these you need to include the function definition in your IAP.h file, (these are allready included for your convience but commented out)
        ...
            void callbackNoteReceived (int note, int velocity, int channel);
        ...
        Secondly, you will then need to add the function declaration to your IAP.cpp file
        ...
            void IAP::callbackNoteReceived (int note, int velocity, int channel)
            {  
                ..code
            }
        ...
     */
    
    virtual void callbackNoteReceived (int note, int velocity, int channel) {}
    virtual void callbackModWheelMoved (int value) {}
    virtual void callbackPitchbendWheelMoved (int value) {}
    virtual void callbackCCValueChanged (int cc, int value) {}
    virtual void callbackPressureValueChanged (int pressure) {}
    
    class MIDI
    {
    public:
        int status;
        int data1;
        int data2;
    };

    
    virtual void callbackMIDIRecived (MIDI message) {}
    
    //------------------------------------------------------------------------------------------
    

    
    AserveComs ();
    virtual ~AserveComs ();
    
private:
    void oscMessageReceived (const OSCMessage& message) override;
    void sendOsc (const int channel, const float frequency, const float amplitude, const int wavetype);
    void sendMIDI (Byte s, Byte d1, Byte d2);
    
    OSCSender sender;
    uint32 timeAtStart;
};


#endif /* defined(__IAP_DEV_1__AserveComs__) */
