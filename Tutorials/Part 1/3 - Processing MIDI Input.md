
# Tutorial 3 – Processing MIDI input 

In this practical we will focus on processing MIDI input data, and building our first synthesizer. By the end of this practical you should have knowledge of:

1.	Callback functions.
2.	Aserve filters.
3.	MIDI note numbers and note frequencies.

## Callbacks

In computer program design we have two opposing principles for dealing with input. Either continuously check if something has changed (known as *polling*). Or we can set things up to alert us when something has changed (we call this second method a *callback*).  

In the previous exercise we used **std::cin** to wait for the user to enter some text that we could then process and display. This input method is sometimes called "blocking" or "busy waiting" - because our program must wait until the input is complete before moving on.

In this exercise we will use a *callback* to be alerted when MIDI information is received. This is sometimes called "interrupt driven" or "event driven" input - because our program can be interrupted by an event (e.g. someone pushing a MIDI key) to react accordingly. 

Programs designed with event driven input deal with inputs separately (QWERTY keyboard, MIDI keyboard, mouse, audio, touch, etc) swapping between tasks as needed.


## Exercise 1: Adding a callback

We will learn more about what has to go in IAP.h in future practicals, but for now please find the line ***callbackNoteRecived*** in IAP.h and remove the two // characters (single line comment) at the start.

```cpp
//void callbackNoteReceived (int note, int velocity, int channel);
```
Should now look like:

```cpp
void callbackNoteReceived (int note, int velocity, int channel);
```
Back inside the IAP.cpp file add the following block of code **under** IAP::run(), **after the last }**

```cpp
void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
   	std::cout << "Note Received: " << note;
	std::cout <<  " Velocity: " << velocity << "\n";
}
```
**Make sure you type this code exactly.**

Add the following piece of code inside IAP::run(), between the opening **{** and closing braces **}**.

```cpp
while (true) 
{
aserveSleep(1000);
}
```

Ensure that Aserve is open before running your program in Xcode. Information should be printed inside Xcode’s console window when you push keys on either the virtual keyboard inside Aserve, or on the physical Impulse keyboard.

You may wonder why our program is still able to print values despite the fact our main loop is now sleeping continuously. This is because we now have two threads going on at once. A technical definition of threads is beyond the scope of IAP - but we cover them in more detail in later years.

Part of our program is dealing with incoming MIDI, and the other part (our run loop) is free to do other things. In future we will use IAP::run() to process data and text input, and we will use callback functions such as callbackNoteReceived() for dealing with MIDI input.

Let’s look in more detail at the function we have just used. The first part of this is referred to as the return datatype (1), however will we not worry about this until the next practical. (2) refers to ownership (or namespace), again will not worry about this until future practicals, but for now ensure that this is added. (3) Is the name of our callback function, these must be typed exactly as they appear, other callback functions have similar names (i.e. for mod wheel). Finally, (4) is the parameters of our callback function, these are the pieces of data passed to us for processing.

```cpp
(1) void (2) IAP:: (3) callbackNoteReceived (4) (int note, int velocity, int channel)
```
Inside our note received function we simply print the values we receive. Do not worry if you do not fully grasp this concept yet.

## Exercise 2: Printing Values for Octave and Pitch

Inside our note callback we want to print two more useful pieces of information. We can use the following formulae to work out pitch and octave from the note number.

```cpp
octave = note / 12
pitch = note % 12
```

Covert the above into C++ code and print the values out inside our callback function. Add your code underneath the existing **std::cout** statements.

## Exercise 3: Our first monophonic synthesizer

Music, much like many other fields, involves some mathematical principles. One of these is the formula for converting MIDI note numbers into frequencies. We manually wrote note frequencies in practical 1 when programming our first sequence, however this is not effective when we do not know what MIDI notes we will receive. We can use the following formula to calculate note frequencies in real time.

<img src="../images/Screen%20Shot%202019-02-21%20at%2012.27.15.png" height=60/>


whereby 'f' is our frequency, and 'n' is our note number. You will need to use the power function to calculate the exponent (the part written above the number '2'). 

The pow() function takes two arguments x and y and returns the result of x to the power y. 
That is, the equation: 


<img src="../images/Screen%20Shot%202019-02-21%20at%2012.27.20.png" height=60/>

can be written in C++ as: 

```cpp
p = pow (x, y);
```

Do not worry if you do not understand this fully yet. Complete this exercise by arranging the following code in the correct order. If you are up for the challenge, have a go at implementing this yourself.

```cpp
1.	int freq = 440 * power;
2.	int power = pow(2, octave);
3.	aserveOscillator (0, freq, 1.0, 0);
4.	int octave = (note – 69) / 12;
```

Run and test your program before moving on.

## Error

You should notice that there is an error when we run our program. That is no matter what note we play, we hear the note A, in different octaves.

The reason that the program does not work correctly is due to integers. Since note frequencies have decimal parts, we will need to replace *int* datatypes with *float* datatypes.

The last thing we need to do is to swap the 12 on statement 4, to be 12.0. The constant 12 is not the same as 12.0, to ensure we use floating point datatypes everywhere we have to specify 12.0. Try swapping these two values and witness the result.

**As an optional challenge try writing the frequency conversion equation on one line of code**

## Exercise 4: Filter Control

Lets now have a go at using a second callback function, this time for the modulation wheel.

Firstly in our IAP.h file we need to un-comment the callback function for modwheel events.

```cpp
    //void callbackModWheelMoved (int value);

    void callbackModWheelMoved (int value);
```

Return to the  IAP.cpp and add the following code next to your note callback code.

```cpp
void IAP::callbackModWheelMoved (int value)
{
}
```

Aserve has a low pass filter with a cutoff range between 20-20000hz, and our mod wheel has a range of ……

Use a std::out to print the value of the mod wheel. Write down the min and max values of the mod wheel. You can then use this formula to covert the new value to a more suitable range.

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/cuttoff_a.png" height=60/>

```cpp
cutoff = ((value / [insert maximum value here].0) * 19800) + 20;
```

**Remember if you do not declare your maximum as a floating point number we will again use integer division, which will likely result in errors.**

You should now be able to call:

```cpp
aserveLPF(cutoff);
```

All being well, you now have a working monophonic synth with a simple filter control assigned to the keyboards modwheel. If you can’t hear the effect taking place, try changing the wave type of our synth to use either a square or saw (wave type 1 or 2).

## Debug Exercise

Give a single reason to why the following code will not work.

```cpp
        int number;
        std::cin >> number;
        std::cout << "this number doubled is << number * 2;
```

## Challenge Exercise: Better Filter Control

To improve the range of controls for the filter you may use the following formula:

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/cuttoff_b.png" height=60/>

```cpp
cutoff = ( pow((value / [insert maximum value here and remove square brackets].0), 3.0) * 19800) + 20;
```

This will apply a logarithmic scale to the filter control to gives us a more natural sounding filter control. You may also wish to adjust the constants 19800 and 20 to observe what effect this might have over the program.

## Homework
Add in the pitchbend callback, and use this to control one of the other aserve filters, remember to first print the pitchbend value to help you work out the min and max values for entering into the cutoff formula.  As an additional challenge work out how to get the synthesizer to react to velocity values.

## Conclusion
Ensure that you understand how to use callback functions before next weeks practical, as they will be used in every practical in future. 

## Important Material

Knowledge of the following will be assumed in next week’s practical:

1. How to use callback functions
2. How to convert note numbers to frequency values
3. The use of the pow function





