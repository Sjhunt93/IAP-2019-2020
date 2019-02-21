
# Practical 3 – Processing MIDI input 

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
Back inside the IAP.cpp file add the following block of code next to IAP::run().

```cpp
void IAP::callbackNoteReceived (int note, int velocity, int channel)
{
   	std::cout << "Note Received: " << note;
	std::cout <<  " Velocity: " << velocity << "\n";
}
```
**Make sure you type this code exactly.**

