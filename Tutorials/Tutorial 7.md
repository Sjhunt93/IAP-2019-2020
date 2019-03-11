# Practical 7: Switch Case and Combinational if Statements

In this practical we will develop a deeper understanding of flow control using more advanced conditional expressions and switch/case structures. On successful completion of this practical you will have an understanding of: 

1. while loops with conditions.
2. logical operators and how they are used to connect conditional expressions. 
3. switch/case structures and how they may be used to control program flow. 
4. How to use a string

## while true

In previous sessions you have developed ‘never-ending’ programs using a while loop, for example:

```cpp
void IAP::run ()
{
  while (true) 
  {
  	aserveSleep(1000);
  }
}
```

You have seen this when using many of the callback based MIDI processing exercises.

By explicitly specifying the condition of the while loop as true the program will never exit on its own. As we learned with if statements, it is possible to insert a conditional statement in place of true so that the program flow (in this case the while loop) can be controlled at run-time. 


## Exercise 1: Program Exit

Open up the practical 7 exercise 1 files and copy them to your Xcode project. Modify the condition of the while loop so that the user can enter a number to cause the loop to exit. The steps you might follow to achieve this are listed below:

1.	Add a variable called programExit before the while loop
2.	Set this value to be equal to 1.
3.	Change the condition of the while loop so that it runs while the variable is equal to 1.
4.	Within the while loop add a std::cin command for changing the value of programExit.
5.	Remember to print useful instructions to the user
6.	Test the program and ensure that it exits

## Introduction to Strings 

In the previous exercise we used an **integer** variable to control the condition of a while loop. However, we often want to communicate with our users by using more literal forms of communication. For example, instead of saying enter 1 for the loop to continue, or enter 0 to quit. We can instead ask the user to type ‘Yes’ or ‘No’

We refer to variables that hold text as strings, or more specifically we use the variable type std::string.

```cpp
std::string name = "";
```
We can use std::cin to put text into our string from a user in the same way as we do with other variable types.

```cpp
std::cout << "Enter name";
std::cin >> name;
```

We can compare the value of a string by using the == operator:

```cpp
if (day == "Monday") 
{
	std::cout << "Worse day of the week :( \n";
}
```

## Exercise 2: Using Strings

Modify your solution to exercise 1, so that the condition of the while loop is controlled by a string variable. Whereby if the user enters the text **‘yes’** then the loop can continue, otherwise it will exit.

## Logical Operators

## Logical And &&

Sometimes programs need to test multiple conditions before executing certain code. For example, we may want to check that the value a user specifies for an oscillator’s amplitude is greater than or equal to 0.0 and less than or equal to 1.0 before starting an oscillator. Using the methods learned last week this would lead to the code: 

```cpp
if (amp >= 0.0)
{
	if (amp <= 1.0)
        {
            aserveOscillator(0, 440.0, amp, 0);
        }
}


