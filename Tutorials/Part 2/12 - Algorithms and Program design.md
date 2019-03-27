# Tutorial 12 – Algorithms and Program design

This week we will explore building a number of programs and explore several algorithms. We will not be learning any new syntax this week, but rather reinforce our understanding of the concepts covered so far.

You are encouraged to complete all of the programs outlined, however you may choose to do these in any order (however you will need to complete 2 before 3).
The projects are as follows:

1.	Synth with attack and release envelopes
    - Supplied as two files, comment placeholders are supplied
2.	Polyphonic synth
    - Supplied as a pseudocode 
3.	Arpeggiator
    - Supplied as a flowchart file
4.	A generative music application
    - Supplied as a basic program
    
## Program 1: Attack and Release Envelopes.

Firstly, download and open the supplied files from <a href="https://github.com/Sjhunt93/IAP-2018-2019/tree/master/Code%20Exercises/Tutorial%2012/AR%20Synth">here</a> and copy them into both IAP.h and IAP.cpp.

For this exercise you will fill in the blanks by following the comments in the supplied file. All the **shared variables** you will require for this program are provided for you, and you should not need to declare any others. A brief description of the program is provided bellow.

On most synthesizer it is desirable for the sound to ramp up it to its full amplitude, rather than produce its full amplitude instantaneously.  For example, a piano has a very short attack time, meaning that it reaches its full amplitude very quickly, where as a stringed instrument (e.g. violin) can gradually increase its amplitude. Release time is the opposite of attack and determines how quickly a note will reduce its amplitude to 0 (stop). In this program we will ramp the volume up and down in the run part of our program, increasing or decreasing the *amplitude* in small amounts each 1ms. The callbacks will be used to trigger the attack and release stages. 

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/asdr.png" />

## Program 2: Polyphonic Synthesizer

Firstly, download and open the supplied files from <a href="https://github.com/Sjhunt93/IAP-2018-2019/tree/master/Code%20Exercises/Tutorial%2012/Polyphonic%20Synth">here</a> and copy them into both IAP.h and IAP.cpp.

Historically in previous practical’s we have simply updated the frequency of an oscillator each time a new note is played, and by keeping the channel number the same each time we have limited ourselves to a monophonic synth. As Aserve has 24 channels, we can in theory have 24 oscillators all at different frequencies playing at once. Therefore, what we want to do is apply the following logic:

### Note on:
Each time a new note on message is receive we want to find a free oscillator i.e. one that is currently not playing, and use this to synthesize the note. If channel 2 is the first free oscillator, then we will synthesize the incoming note on channel 2.

### Note off:
Each time a note off message is received we want to find the oscillator that is playing ‘this note’s frequency’ and switch if off.

To illustrate what should happen each time a note message is received a table of input events and corresponding Aserve oscillator states are shown.

<hr>

| ﻿Message input              |      |          | Aserve                                                                  |       |       |
|----------------------------|------|----------|-------------------------------------------------------------------------|-------|-------|
| Event                      | Note | Velocity | Osc 1                                                                   | Osc 2 | Osc 3 |
| First note is pushed here  |      |          | 0                                                                       | 0     | 0     |
| 1                          | 60   | 127      | Puts note 60 on Osc 1                                                   |       |       |
| Second note is pushed here |      |          | 60                                                                      | 0     | 0     |
| 2                          | 62   | 127      | Puts note 62 on Osc 2 as Osc 1 is being used                            |       |       |
| Third note is pushed here  |      |          | 60                                                                      | 62    | 0     |
| 3                          | 65   | 127      | Puts note 65 on Osc 3 as other Osc 2 and Osc 1 are being used           |       |       |
| First is turned off        |      |          | 60                                                                      | 62    | 65    |
| 4                          | 60   | 0        | Find channel this playing note 60 and switch it off, in this case OSC 1 |       |       |
|                            |      |          | 0                                                                       | 62    | 65    |
| 5                          | 65   | 0        |                                                                         |       |       |
|                            |      |          | 0                                                                       | 62    | 0     |
| 6                          | 67   | 127      |                                                                         |       |       |
|                            |      |          | 67                                                                      | 62    | 0     |

<hr>

We will need to keep track of the state of each oscillator inside our program. As there are 24 oscillators it would make sense that we use an array for keeping track of each oscillators current note. You should initialize each element of the array to be -1, and use -1 to represent a free oscillator. 

## Program 3: Arpegiator

To implement this program, you need to first have completed the previous exercise. Firstly, remove both calls to aserveOscillator from your callbackNoteReceived code. We will be now be controlling the synthesis of notes from within the run() function.

You will now need to implement the following flowchart inside your run loop.

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/flowchart.png" />


## Extensions

Once you have setup the basic arpeggiator there are a few extensions we can apply. Firstly, ensure you have completed last weeks’ homework exercise. We can add a feature to this arpeggiator that controls in which order the notes are played. At the moment notes are arpeggiated in the order in which the keys are pushed down. However, we can sort the notes array so that notes are arpeggiated in either ascending or descending order. The steps to achieve this are as follows:

1.	Add a shared variable called order.
2.	Create a function called setPlayOrder()
    - If order is equal to 0, then apply **std::sort** on the notes array
    - If order is equal to 1, then apply **std::sort** on the notes array, then call **std::reverse** on the notes array
3.	Add a suitable callback that can be used to modify the value of ‘order’
4.	Think carefully about where you might want to call setPlayOrder().


## Program 4: Generative music sampler

You are supplied with the start of a very basic generative music application (<a href="https://github.com/Sjhunt93/IAP-2018-2019/tree/master/Code%20Exercises/Tutorial%2012/Generative%20Music%20Application">available here</a>). However, it does not (objectively) sound very good. There are a number of things we can do to improve this application.



## Random number generation

The **arc4random()** function can be used to generate random numbers, to generate numbers in a given range we can do the following:

```cpp
    int note = arc4random() % 128;
```

The modulo (%) operator is used to limit values so that they are less than the value supplied, in this case up to and including the value of 127. To produce values between 5 & 10 we could do the following.

```cpp
    int num = (arc4random() % 6) + 5;
```

The current application generates numbers in the range 0-127, which is not ideally suited to a musical application.

1.	First change the range of numbers, so that they are generated in the range 48-72.
2.	Pass each note through the **majorScale** function we developed last term.

The notes that are played now should be a lot more musical and only trigger notes within a suitable scale, however the notes can have quite a wide jump, much larger then you would find commonly in music, to solve this you may wish to use the following idea:

1.	Keep track of the last note that was played. 
2.	If the new note to be played is more than 12 semitones above, then subtract 12. 
3.	If the new note to be played is less than 12 semitones bellow, then add 12.

At this point the melody should start to sound quite reasonable, however the rhythm is still very chaotic. An idea for improving this is as follows:

1.	Create an array called rhythm values (a suggestion is shown below)
2.	Instead of generating a random rhythm value generate a random index into the above array, and then use this as the aserveSleep value. Think carefully about the maximum index that can be generated.

```cpp
Rhythm values: 125, 250, 375, 500, 750, 1000
```

Try experimenting with different values inside the rhythm values array including adding multiples of the same value.



