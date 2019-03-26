# Practical 12 – Algorithms and Program design

This week we will explore building a number of programs and explore several algorithms. We will not be learning any new syntax this week, but rather reinforce our understanding of the concepts covered so far.

You are encouraged to complete all of the programs outlined, however you may choose to do these in any order (however you will need to complete 2 before 3).
The projects are as follows:

1.	Synth with attack and release envelopes
    - Supplied as two files, comment placeholders are supplied
2.	Polyphonic synth
    - Supplied as a pseudocode 
3.	Arpeggiator
    - Supplied as a flowchart file
4.	A generative engine that samples from the inputs
    - An adaption of exercise 3 from last week
    
# Program 1: Attack and Release Envelopes.

Firstly, download and open the supplied files from blackboard and copy them into both IAP.h and IAP.cpp.

For this exercise you will fill in the blanks by following the comments in the supplied file. All the shared variables you will require for this program are provided for you, and you should not need to declare any others. A brief description of the program is provided bellow.

On most synthesizer it is desirable for the sound to ramp up it to its full amplitude, rather than produce its full amplitude instantaneously.  For example, a piano has a very short attack time, meaning that it reaches its full amplitude very quickly, where as a stringed instrument (e.g. violin) can gradually increase its amplitude. Release time is the opposite of attack and determines how quickly a note will reduce its amplitude to 0 (stop). In this program we will ramp the volume up and down in the run part of our program, increasing or decreasing the `amplitude’ in small amounts each 1ms. The callbacks will be used to trigger the attack and release stages. 
