# Tutorial 7 - Switch Case and Combinational if Statements

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
```

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

## Exercise 4: Scale Quantization


Open exercise 7.4 and copy the code into your project, replacing the existing contents of IAP.cpp and IAP.h.

For this exercise we are going to a make a function called majorScale that quantizes all incoming notes into the C major scale. One method of doing scale quantization is to check the pitch class of a note, and if it is not in the current scale, to increment the note by 1. For example, the pitch C# would get increment by 1 to be D.

1. Firstly, add a new function declaration to your IAP.h file, called majorScale that takes **one int argument** called note, and has **int** as its return type.
2. Add the definition to the IAP.cpp file.

### To build the majorScale function.

1. Inside the function compute the pitch of a note by doing the following sum:
	*pitch = note % 12*
2. If the value of pitch is, 1, 3, 6, 8 or 10, increment the value of note by 1.
3. Return note from the function.

You should now be able to pass the incoming note from the note callback to this new function, before calculating the frequency.

```cpp
note = majorScale(note);
```

*There are multiple ways to check the value of pitch in step 2 above, think carefully about what we have learnt so far and apply the most appropriate method.*


## Switch Case.

A switch/case structure can often be used in place of a multi-way selection if...else if structure to create more readable and efficient flow control. If an if...else if structure tests an integer variable against a number of constant values, a switch/case structure is the preferred method.
 
For example, a nested if structure may be used to display the days of the working week by testing the integer variable **day**, which represents the days Monday to Friday with a number in the range 0-4. 

```cpp
    if( day == 0 )
    {
        std::cout << "Monday\n";
    }
    else if( day == 1 )
    {
        std::cout << "Tuesday\n";
    }
    else if( day == 2 )
    {
        std::cout << "Wednesday\n";
    }
    else if( day == 3 )
    {
        std::cout << "Thursday\n";
    }
    else if( day == 4 )
    {
        std::cout << "Friday\n";
    }
    else
    {
        std::cout << "Invalid!\n";
    }
```

As the variable day (in the example on the previous page) is compared with constants, this nested if structure may be replaced by the more elegant switch/case structure: 

```cpp
    switch (day)
    {
        case 0:
            std::cout << "Monday\n";
            break;
        case 1:
            std::cout << "Tuesday\n";
            break;
        case 2:
            std::cout << "Wednesday\n";
            break;
        case 3:
            std::cout << "Thursday\n";
            break;
        case 4:
            std::cout << "Friday\n";
            break;
        default:
	    std::cout << "Invalid!\n";
            break;
    }
```

The variable enclosed in the brackets, day in this example, is tested against each case from top to bottom. If a matching case is found, the subsequent statements are executed until the break statement is reached, whereupon the switch/case structure terminates. If the variable does not match a specified case, the default case is executed. 

Omission of the break keyword results in all statements preceding the next break statement being executed. This enables multiple cases to *fall through*, such that one set of statements can be executed for multiple cases. We will discuss this again shortly but first.

## Exercise 5: A Second Scale

Using the steps as before add another function to your project called pentatonicMajorScale. This time we will use switch case rather than an if statement to decide if we need to move a pitch up or down. For this exercise use a single case for each relevant pitch. A table of pitches to check for and how much to modify the input note by, is given on the next page.

| Pitch | Change Note |
| --- | --- |
| 1 | Increment by 1 |
| 3 | Increment by 1 |
| 5 | Decrement by 1 |
| 6 | Increment by 1 |
| 8 | Increment by 1 |
| 10 | Decrement by 1 |
| 11 | Increment by 1 |


Note that a variable can be increment by 1 by using the shorthand ++ operator. For example

```cpp
note++;
```
This is equivalent to doing:

```cpp
note = note + 1;
```
The -- operator can be used to decrement by 1.

## Multiple switch case 

When using an if statement you can use the || operator to check for multiple conditions inside a single if statement.

```cpp
if (day == 5 || day == 6) 
{
	std::cout << "It’s the weekend!";
}
```

We can do the same with a switch case. Note that we can have multiple case statements, but we must eventually have a break tag. In this example if day is either equal to 5 or 6, then ‘It’s the weekend’ will get printed. 

```cpp
	case 5:
	case 6:
   		std::cout << "It's the weekend!";
	break;
```

A common error is to use a switch case but forget to use a break tag!

```cpp
switch (day)
{
        case 0:
            std::cout << "Monday\n";
        case 1:
            std::cout << "Tuesday\n";
            break;
        case 2:
            std::cout << "Wednesday\n";
            break;
}

```

If the variable day is equal to 0, then both Monday and Tuesday will be printed, as the user has forgot to put a break tag before case 1.

## Challenge Exercise: Refactoring

Refactor your solution to exercise 5 by using a switch case, with a collection of cases for the pitches that result in the output note being increment by 1, and a second collection of cases for the pitches that result in the output note being decrement by 1.

## Important Material

Knowledge of the following will be assumed in next week’s practical: 

1. While loop conditions. 
2. logical operators.
3. Using a basic string 
4. Switch/case statements. 





