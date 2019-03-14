# Practical 8 – Flow Control: Loops


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


