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
```

However, it is possible to connect multiple conditional statements such that they can be tested as one big conditional expression using the logical AND operator (&&) as follows: 

```cpp
if (amp >= 0.0 && amp <= 1.0)
{
	aserveOscillator(0, 440.0, amp, 0);
}
```

If both the conditional statements either side of the logical AND (&&) operator are **true**, the outcome of the entire conditional expression is **true** and the oscillator is turned on. If either, or both of the statements are **false**, then the outcome of the entire expression is **false** and the call to aserveOscillator() is skipped. 

In the latter situation an else condition could be used to inform the user that the value they entered was outside of the expected 0.0 to 1.0 range. 

## Logical OR ||

The OR (||) logical operator may be used to test whether a series of the conditions are true. For example, in practical 2 we may have wanted to check to see if the user had entered either ‘yes’ or ‘YES’.

```cpp
while (text == "yes" || text == "YES") 
{

}
```
If one (or any) of the conditional statements on either side of the logical OR operator (||) are true, the outcome of the entire conditional expression is true and therefore the loop will continue to run.

## Logical Not !

It is also possible to invert the outcome of a conditional expression using the logical NOT operator (!). For example, the following code will print *‘funds available’* when the variable cash is **not** 0.

```cpp
if (cash != 0) 
{
	std::cout << "Funds Avaliable";
}
```

## Brackets
The && operator and || operator have the same order of precedence, meaning that you cannot be sure the order in which they will be executed.

For example:
```cpp
if (time > 600 && time < 1800 || override == 0) 
{
	std::cout << "turning lights off\n";
}
```cpp

It would seem natural that the && symbol would be computed between both sets of time variable comparisons; however, this cannot be guaranteed, and this will often result in a compiler warning. When chaining together multiple logical operations it is best practice to place them in brackets.

```cpp
if ( (time > 600 && time < 1800) || override == 0) 
{
	std::cout << "turning lights off\n";
}
```

# Exercise 3: Logical Operations

Using what you have learnt about logical operators work out which of the following statements will get printed. Try and complete this exercise without using xcode.

### 1:
```cpp
    int temperature = 11;
    if (temperature > 10 && temperature < 13) 
    {
        std::cout << "Is Just right \n";
    }
    else 
    {
        std::cout << "Is too hot, or too cold\n";
    }
```

### 2
```cpp
    int num1 = 10;
    int num2 = 12;
    if (num1 == 10 && num2 != 12) 
    {
        std::cout << "Great!";
    }
    else 
    {
        std::cout << "Not Great!";
    }
```
### 3
```cpp
    float amplitude = 1.3;
    if (amplitude < 0.0 || amplitude > 1.0) 
    {
        std::cout << "Too Loud!";
    }
    else 
    {
        std::cout << "Is ok!";
    }
```

### 4

```cpp
    float config = 1;
    float freq = 20000;
    
    if ( (freq < 0.0 || freq > 22000 ) &&
        ((config != 0) || config != 1 || config != 2 )) 
    {    
        std::cout << "Out of range values \n";
    }
    else 
    {
        std::cout << "Start Synth \n";
    }
```
   









