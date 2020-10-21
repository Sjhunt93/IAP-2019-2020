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

#if JUCE_WINDOWS
typedef unsigned char Byte;
#endif // JUCE_WINDOWS


class AserveComs :
private OSCReceiver,
private OSCReceiver::Listener<OSCReceiver::RealtimeCallback>
{
public:
    
    //------------------------------------------------------------------------------------------
    /**
     Function to control aserve's oscillators.
     
     Arguments control the oscillator parameters. Setting the amplitude
     of an oscillator to 0.0 will switch it off.
     
     @param		oscillatorNumber	selects the oscillator: 0 - 23
     @param		frequency			sets the selected oscillator's frequency: 0.0Hz - 20000.0Hz
     @param		amplitude			sets the selected oscillator's amplitude: 0.0 to 1.0
     @param		wave				sets the selected oscillator's waveform: 0 = sine, 1 = pulse, 2 = saw, 3 = reverse saw, 4 = triangle, 5 = noise
     
     Example usage:
     @code
     //Set the first oscillator to a 1kHz sinusoidal tone at max amplitude
     aserveOscillator(0, 1000, 1.0, 0); 
     @endcode
     */
    void aserveOscillator (int channel, float frequency, float amplitude, int wavetype);
    void aserveClearOscillator (int channel); //turns off the oscillator
    
    /**
     Causes program execution to pause for the specified time in milliseconds.
     
     @param		milliseconds		sleep time in ms
     
     Example usage:
     @code
     //pause for 1 second
     aserveSleep(1000);
     @endcode
     */
    void aserveSleep (int milliseconds);
    
    /**
     Returns the number of milliseconds elapsed since program startup
     
     @return The time in ms.
     
     Example usage:
     @code
     //assigns the time since program startup in ms to time
     time = aserveGetTime();
     @endcode
     */
    int aserveGetTime ();
    
    /**
     Loads a sample in to the sample window.
     
     The sample window can load up to 4 .wav/.aiff files located on the file system. This function allows
     samples to be loaded programmatically.
     
     @param		channel		specifies the channel into which the file will be loaded: 0 - 3
     @param		filePath	specifies the path to the file to be loaded (in windows use '/' and not '\' in the file path)
     
     Example usage:
     @code
     //load the sample at the path "/Users/tjmitche/bd.wav" into the top row of the sample window.
     aserveLoadSample(0, "/Users/tjmitche/bd.wav");
     @endcode
     
     @see aserveSample
     */
    void aserveLoadSample (int channel, std::string filePath);
    
    /**
     Play back files in the sample window.
     
     File loaded into a specified channel are played back at the specified amplitude. An amplitude value of
     0.0 will stop playback.
     
     @param		channel			specifies the sample row to playback: 0 - 3
     @param		amplitude	    specifies the playback amplitude: 0.0 - 1.0
     
     Example usage:
     @code
     //plays the 3rd sample
     aserveSample(2, 1.0);
     @endcode
     
     @see aserveLoadSample
     */
    void aservePlaySample (int channel, float amplitude);
    
    /**
     Loads a sample in to the pitches sample window.
     
     The sample window can load up to 4 .wav/.aiff files located on the file system. This function allows
     samples to be loaded programmatically. This differs from aserveLoadSample() in that samples can have thier pitch changed during playback
     
     @param		channel		specifies the channel into which the file will be loaded: 0 - 3
     @param		filePath	specifies the path to the file to be loaded (in windows use '/' and not '\' in the file path)
     @param     originalPitch   original midi note number of the sample
     @param     attack      attack time in seconds
     @param     decay       decay time in secionds
     
     Example usage:
     @code
     //load the sample at the path "/Users/tjmitche/bd.wav" into the top row of the sample window.
     aserveLoadSample(0, "/Users/tjmitche/bd.wav", 60, 0.03, 0.04);
     @endcode
     
     @see aservePlayPitchedSample
     */
    void aserveLoadPitchedSample (int channel, std::string filePath, int originalPitch, float attack, float decay);
    
    /**
     Play back pitched samples in the sample window.
     
     Files loaded into a specified channel are played back at the specified amplitude and at a given pitch. Supplying an amplitude value of 0 will stop the sample

     
     @param		channel			specifies the sample row to playback: 0 - 3
     @param		amplitude       specifies the playback amplitude: 0.0 - 1.0
     @param     note            the pitch to trigger the sample at.
     
     Example usage:
     @code
     //triggers a sample at its original pitch.
     aservePlayPitchedSample(0, 60, 1.0);
     @endcode
     
     @see aserveLoadPitchedSample
     */
    void aservePlayPitchedSample (int channel, int note, float amplitude);
    
    /**
     Loads default sounds stored inside aserve. These are 
     sample channel 0:  kick drum
     sample channel 1:  snare drum
     sample channel 2:  closed hat
     sample channel 3:  open hat
     
     pitched channel 0: piano sample at midi note 60
     
     @endcode
     */
    void aserveLoadDefaultSounds ();
    
    /**
     Sets up the values for the inbuilt Low pass filter
     
     @param		cutoff      sets of the cuttoff frequency: 20.0Hz - 22050.Hz
     
     Example usage:
     @code
     //LPF filter with 500hz cutoff
     aserveLPF (500);
     @endcode
     */
    void aserveLPF (float cutoff);
    
    /**
     Sets up the values for the inbuilt High pass filter
     
     @param		cutoff      sets of the cuttoff frequency: 20.0Hz - 22050.Hz
     
     Example usage:
     @code
     //HPF filter with 30hz cutoff
     aserveHPF (500);
     @endcode
     */
    void aserveHPF (float cutoff);

    /**
     Sets up the values for the inbuilt band pass filter
     
     @param		freq    sets the band pass filter's frequency: 20.0Hz - 22050.Hz
     @param     q       sets the filters Q value. values must be greater than > 0.0
     @param     gain    gain to boost the band pass filters output
     Example usage:
     @code
     //BPF filter with 1000hz boost
     aserveBPF (500, 3.0, 3.0);
     @endcode
     */
    void aserveBPF (float freq, float q, float gain);


    

    /**
     Transmits the specified MIDI message on aserve's active output ports.
     
     @param		status	specifies the status byte of the message to be transmitted: 128 - 255
     @param		data1	specifies the first data byte of the message to be transmitted: 0 - 127
     @param		data2	specifies the second data byte of the message to be transmitted: 0 - 127
     
     Example usage:
     @code
     // send a note on message on channel 1 for note C4 at max velocity
     aserveSetMidi(144, 60, 127);
     @endcode
     
     */
    void aserveSendMIDI (int status, int data1, int data2);
    
    /**
     sets the pixel grid visualizer in aserve.
     
     @param     row     row to set
     @param     value   value of the row, whereby each bit determines whether or not the pixel is lit
     
     Exampe usage:
     @code
     //set part of the grid.
     
     @endcode
     */
    void aserveSetPixelGrid (int row, int value);
    
    /**
     Synthesises text into speech (Mac only).
     
     @param		message	the text to be synthesised.
     
     Example usage:
     @code
     //synthesises the text
     aserveSay("hello world");
     @endcode
     */
    void aserveSay(std::string message);
        
    /**
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
    
    /**
     callback for receiving note messages
     
     @param		note        specifies the midi note number
     @param		velocity	specifies the velocity value
     @param		channel     specifies the channel value
     
     */
    virtual void callbackNoteReceived (int note, int velocity, int channel) {}
    
    /**
     callback for receiving changes to the mod wheels position
     
     @param		value       specifies the mod wheel's value
     
     */
    virtual void callbackModWheelMoved (int value) {}
    
    /**
     callback for receiving changes to the pitchbend wheels position
     
     @param		value       specifies the pitchbend wheel's value
     
     */
    virtual void callbackPitchbendWheelMoved (int value) {}
    
    /**
     callback for receiving changes for a control change message
     
     @param     cc          controller number
     @param		value       control value
     
     */
    virtual void callbackCCValueChanged (int cc, int value) {}
    
    /**
     callback for receiving pressure values
     
     @param		pressure    value of the pressure change
     
     */
    virtual void callbackPressureValueChanged (int pressure) {}
    
    /**
     callback for when a user clicks on the pixel grid in aserve
     
     @param     x           x coordinate
     @param     y           y coordinate
     */
    virtual void callbackPixelGrid (int x, int y) {}
    
    
    /**
     class for storing 3-byte MIDI messages
     
     @param		status	specifies the status byte of the message
     @param		data1	specifies the first data byte of the message
     @param		data2	specifies the second data byte of the message
     
     */
    class MIDI
    {
    public:
        int status;
        int data1;
        int data2;
    };

    /**
     callback for receiving generic MIDI messages. Note this is allways called in addition to specific MIDI messages above.
     
     @param		message         MIDI message
     
     */
    virtual void callbackMIDIReceived (MIDI message) {}
    
    
    enum eOscillatorMode
    {
        eNormal = 0,
        eFm8,
    };
    /**
     When using the FM 8 mode, the top 8 oscillators (16-23) act as modulators for oscillators 0-7.
     They modulators are set the same as any other oscillator except that the amplitude value is used as the FM depth control
     and can be scalled to be greater than 1
     THIS IS AN EXPERIMENTAL FEATURE
     */
    void aserveConfigureOscillatorMode (eOscillatorMode mode);
    
    /**
     Can be used to pan oscillators left/right
     
        @param     channel      oscillator channel to pan
        @param     left         amount of left pan range 0 - 1.0
        @param     right        amount of right pan range 0 - 1.0

     */
    void aservePanOscillator (int channel, float left, float right);
    
    //------------------------------------------------------------------------------------------
    
    /**
     This feature is used to set (or hack) some of the underlying features of aserve and simulates register writes/reads
     
     //  --------
     //  address             property                        value range
     //
     //  0x00 - 0x0F         resets and reserved messages    n/a
     //  --------------      Oscillator controls, these are banked sequentially ------------------------------------
     
     //  0x10 - 0x2F         oscillator frequency            0 - sample rate / 2.0
     //  0x30 - 0x4F         oscillator amplitude            0 - 1.0
     //  0x50 - 0x6F         oscillator waveforms            0 - 6
     //  0x70 - 0x8F         oscillator pan                  -1.0 - 1.0 (full left = -1.0, full right = 1.0)
     //  0x90 - 0xAF         oscillator attack               0 - 1.0
     //  0xB0 - 0xCF         oscillator release              0 - 1.0
     
     //  --------------      Filter controls, these are global ------------------------------------
     
     //  0x100               low pass filter cutoff          20 - sample rate / 2.0
     //  0x101               high pass filter cutoff         20 - sample rate / 2.0
     //  0x102               band pass filter cutoff         20 - sample rate / 2.0
     //  0x103               band pass filter Q              > 0
     //  0x103               band pass filter gain           > 0
     
     //  --------------      Aserve bit grid, these are global ------------------------------------
     
     
     //  0x200 - 0x2FF       bit grid states                 encoded row by row, = x + y * 16
     
     //  There are 3 sets of registers for setting custom colours on the bit grid visualiser
     //  these are stored in rows and then column
     //  For example to set the red component of x:5, y:7 if would be register 0x275
     //  generic format 0x (R/G/B) (Y) (X)
     
     //  0x300 - 0x3FF       bit grid visualiser colours     red values
     //  0x400 - 0x4FF       bit grid visualiser colours     green values
     //  0x500 - 0x5FF       bit grid visualiser colours     blue values
     
     
     //  ------------------------------------------------------------------------------------------
     
     THIS IS AN EXPERIMENTAL FEATURE */
    
    void aserveSetRegister (int reg, float value);
    
    
    AserveComs ();
    virtual ~AserveComs ();
    void aserveDoRegisterTest ();
private:
    void oscMessageReceived (const OSCMessage& message) override;
    void sendMIDI (Byte s, Byte d1, Byte d2);
    
    OSCSender sender;
    Thread::ThreadID mainThreadId;
};


#endif /* defined(__IAP_DEV_1__AserveComs__) */
