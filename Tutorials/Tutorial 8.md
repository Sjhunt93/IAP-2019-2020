# Tutorial 8 – Flow Control: Loops


In this practical you will learn how to control program flow using three different types of loops: 

1. the **while** loop.
2. the **do-while** loop. 
3. the **for** loop 

## While
In previous sessions the large majority of exercises have employed a ‘never-ending’ while(true) loop. Last week we learned that it was possible to control the number of times the loop cycled with a condition in place of the true keyword. 

From now on, you should only include loops in your program if you need one, and it should **always** be controlled by a conditional statement, such that it is possible to exit the program in some way. 

## Exercise 1: High frequency test

Write a program that will test the frequency range of your hearing. To do this you should set up a while loop to sweep the frequency of a sinusoidal oscillator from 0 - 20,000Hz. The program should produce a frequency sweep that lasts approximately 20 seconds, while printing the current frequency. The program should exit when the oscillator reaches a frequency of 20,000Hz. **Please ensure you are using headphones for this test!**

The steps to achieve this are as follows: (you can write all code in the your IAP::run() function)
1.	Initialise frequency variable
2.	Enter while loop with condition frequency < 20000
3.	Set oscillator to frequency variable value
4.	Display frequency value
5.	Add 50 to frequency value

*This program will only provide an indication of your hearing range, results will not be accurate as the apparatus in labs is quite limited.*


## Exercise 2: High Frequency Test 2

You may have noticed in the last test that it is difficult to see the exact frequency at which the sweep is no longer audible. Extend the last program such that the sweep stops when the modulation wheel is moved from its zero position. You should now have two conditions inside your while loop. Think carefully about which **logical** operator to use.

Modify the while loop condition to achieve this. You will need to set up and use the modwheel callback. You should create a shared variable that is written to by the modwheel callback and then read inside the while loop condition. Run the test with your eyes closed and find out the highest frequency that you can hear. 

## Do while

In the conventional while loop, the test condition appears at the beginning of the loop structure. The general form of the while loop is indicated below: 

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/while.png" height=300/>


An alternative looping mechanism is the do-while construction, which operates in exactly the same way as the while loop only the test condition is positioned at the end of the loop, rather than at the beginning. The general form of the do while loop is as follows. 

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/dowhile.png" height=300/>

It is more appropriate to use a do while rather than a while loop when the outcome of the condition is controlled by the statements within the loop. Or that you need to always do something once regardless of the condition.

Consider the example where a program repeats a set of statements that read a note character (‘A’-‘G’) from the QWERTY keyboard and play a tone at the appropriate frequency. The program should exit the loop if the user enters the character ‘x’.
 
As the ‘x’ can only be detected after the input character has been read, it would be appropriate to use to use a do-while loop, such that the character is read before the condition is tested. If a while loop were used instead, the character variable in which the note is stored will be tested in the loop condition before it has been given a value by the program user. 

## Exercise 3 : High Frequency Test 3

Modify the solution to the exercise High Frequency Test 2 such that at the end of the sweep the user is asked if they would like to repeat the test. The program should then read a **string**. If the string is **‘yes’** the sweep should repeat, otherwise the program should exit. To do this you will need to place the code that implements the sweep within a second loop which checks for the ‘yes’ character.  A general template for this program looks like so:

```coo
do 
{
  //Start of frequency test
  while () 
  {
            
  }
  //End of frequency test
        
  //ask user if they would like to repeat

} while (  );
```

## For Loops

The for keyword provides the third looping construction in the C++ programming language. As well as the end condition, the for loop contains additional information about the parameters of the loop. The general form is as follows (note the following code is not valid C++ code, it just provides the general form of a for loop, see the later example for the complete syntax): 

```cpp
for (initialisation; condition; update) 
{
   do something;
}
```

-	The **initialization** statement is often used to initialize a variable (i.e. a counter). Think of this as what value do I want to start my loop at.
-	 The **condition** statement sets the condition that controls whether the loop should continue or stop, this is normally a conditional test to see whether the counting variable has reached the value you wish to count to. 
-	The **update** statement controls how the value of the counting variable is modified for each cycle of the loop. 


For example, the following code fragment would produce the numbered sequence 0-4

```cpp
for (int count = 0; count < 5; count = count + 1) 
{
   std::cout << count << "\n";
}
```

The process is as follows: 
1.	The initialisation statement sets the start value for the variable count. Initializes count to zero in the above example. Note that we can declare variables here for use in our loop. 
2.	The condition is tested to check the value of the counting variable to establish whether the loop should continue or exit. In this example the loop continues while count is less than 5.
3.	If the outcome of condition is true, the statements enclosed within the braces of the for loop are executed.
4.	The value of the counting variable is then changed by the update statement. In the above example the value of count is increased by one.
5.	Steps 2 - 4 then repeat until the outcome of the condition (step 2) is found to be false.

## Exercise 4: For loop MIDI – Frequency Table

Write a program that prints out a table of MIDI note numbers and their corresponding frequencies in Hz. 

MIDI note numbers are encoded into 7-bits, which gives the note range 0 to 127 (C-1 to G9). Use a for loop to count from 0 up to and including 127, printing the note number and converted frequency value at each cycle of the loop (recall the formula for converting note numbers to frequencies from earlier practical’s).  You may wish to use the mtof() function.

Once you have this working, modify the loop so that the table is displayed in descending order, from 127 to 0. 


## Challenge Exercise: Making a saw wave from sine waves

Load the example code (link) into your IAP.h and IAP.cpp files.

We will now add two for loops to our monophonic synthesizer to artificially create a low-fi saw wave oscillator from a series of sine waves. To achieve this **rearrange** and **add** the following code to the note on branch of the if statement inside the note callback function.


```cpp
1.	float amplitude = 1.0 / (counter + 1);

2.	float oscFreq = frequency * (counter + 1);

3.	aserveOscillator(counter, oscFreq, amplitude, 0);

4.	for (int counter = 0; counter < 16; counter++) 

   {

5.	float frequency = mtof(note);

6.	}
```

**Add a separate for loop to the else condition for turning off all 16 oscillators.**

for more information on additive synthesis see the following links:

<a href="https://www.youtube.com/watch?v=K3D1fPjWAnc">Video 1</a>

<a href="https://www.youtube.com/watch?v=YsZKvLnf7wU">Video 2</a>

## Important Material

In general a for loop is the most commonly used loop, and you are far more likely to see a while loop than a do-while.

Knowledge of the following will be assumed in the next practical: 

1.	while loops.
2.	do while loops.
3.	for loops. 

## Extra material
If you have finished this practical within the allocated time, then please complete the number conversion practical found on blackboard. It can be found in Learning materials -> Extra Practical’s.





