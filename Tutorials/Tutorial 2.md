# Practical 2 - Variables and Program Input/Output 

In this practical, we will build on last week’s work by enabling our programs to receive and respond to user input. By the end of this practical you should be familiar with: 

1.	Variables and data types in C++.  
2.	The std::cin function for reading data from the QWERTY keyboard into variables within our programs.  
3.	How to display variable values with std::cout.
4.	A basic loop for repeating blocks of code.  


## Getting stated
Ensure that your run function is empty, and that any work from last week is appropriately saved.

## Recap

We can use the std::out command to print text to the user:

```cpp
std::cout << "Hello Person";
```

## Variables

Write the following code into your main run function:

```cpp
int year = 2018; 
std::cout << "The Value of Year: " << year << "\n";
```


Check that it compiles and runs, and that the value 2018 is printed.

The first line of this program is called a variable declaration, and there is usually 4 parts. The first part is the type of variable we want to have, in this instance we have a variable of type int (see the bellow table for different types). The second part of this is the variables name, in this case we call it year. Part 3 is the assignment operator, used to give variables a value. And finally part 4 is the value we wish to assign, in this case 2018.

```cpp
(1) int	(2) year (3) = (4) 2018; 
```

We then use the std::cout command to print the value of the variable year. Note we can chain up as many messages and variables for printing as we like as long as we separate them by the << symbol.

We will use 3 main data types in IAP for storing data and these are, int, float and std::string. There are 2 other data types that you also might come across and these are included in the table for reference. Will not be using (bool, char) data types during this practical
    

Data Type | Description | Range of values
--- | --- | ---
int |	Store whole numbers, i.e. 1670, 5, 123985718275 |	-2147483648 to 2147483647 
float |	Store numbers with a decimal part. i.e. 0.76, 440.56 | 10^38 to −10^38 
std::string |	Store strings of characters, i.e. “IAP” , “I Love programming” | ASCII characters
bool | Stores true or false values only | True or false
char | Store single characters, i.e. ‘a’, ‘b’, ‘5’ | A single ASCII character

An example of using each of these is shown bellow.

```cpp
int age = 25;
std::string name = "Sam";
float height = 1.83;
bool btnState = true;
char decision = 'y';
```

There are many other data types, but we will explore these in detail in later practicals. 

## Data Input

By definition variables are designed to hold data that might change, but the examples so far have used data that is the same each time the program runs. One way to change the values of such variables by user input is to use the std::cin command.

```cpp
int age = 0;
std::cin >> age;
```

In the above code snippet we declare a variable called age of type int and give it an initial value of 0. To get the users input we use the std::cin command, followed by the >> symbol (note the direction of flow, we want to put data from the input into age). We then specify the variable that we want to write into.


## Exercise 1: Basic input
Copy the following code into your run loop.

```cpp
void IAP::run ()
{
    int age = 0;
    std::cout << "please enter your age\n";
    std::cin >> age;
    std::cout << "Your age is: " << age << "\n";
}
```

Note that as we are supply the value of the variable age via the std::cin command, therefore the value we supply on the first line (0) is not needed. However, it is ALWAYS good practice to give a variable a default value, in this case 0.

## Exercise 2: Frequency Input Into Aserve

Firstly, clear the main run loop and then copy and rearrange the following code into the correct order so that it executes correctly.

```cpp
1.	std::cin >> frequency;
2.	float frequency = 23000;
3.	aserveOscillator(0, frequency, 1.0, 0);
4.	aserveSleep(1000);
5.	std::cout << "Please enter a frequency value in hz \n";
```



## Exercise 3: Adding Amplitude Control

Extend the above exercise by adding amplitude control, remember that a variable can only hold a single piece of data at once, so you will need to add a second variable. Follow these steps:

1.	Create another floating-point variable with an appropriate name.
2.	Prompt the user to enter an amplitude value.
3.	Read the entered value into the variable created above.
4.	Display the entered amplitude value as well as the frequency value.
5.	Set the oscillator amplitude to the value entered by the user. 


## Exercise 4: Loops

The exercise above will exit once the user has entered a single frequency and amplitude value, in reality the user will most likely want to enter another set of frequency and amplitude values without having to run the program again. For this we can use the following loop.

```cpp
void IAP::run ()
{
    while (true) 
	{
        //Code from previous exercise
    }   
}
```

This is a **loop** and it enables any code that is between the { and {} to be repeated. The **true** part of the while loop makes this section of code repeat forever. Adjust your solution to the previous exercise by adding in a while loop.

## Variable initialization and introduction to debugging

Save your solution to the previous exercise and add the following code to your main run loop.

```cpp
void IAP::run ()
{
    int x = 0;
    int y = 0;
    x = 5;
    y = x;
    x = 7;
}
```

We will open up and use the debugger to see what is happening on each line.

Firstly, click on the line number where int x = 0 has been written, to drop a break point. (see below). Break points appear in blue. (note that your line numbers may be different to those shown in the figure)


![Debug 1](https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/debug2_1.png)

When you run your program you should now see that the program pauses where you have placed the break point.

Ensure that the debug window (1) is being shown at the bottom of the Xcode project. We can now use the step over button (2) to manual step through the program as its running. Observe what happens on each step in the debug window (1) on each press of the step over button.

![Debug 2](https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/debug2_2.png)

On step 2 you should see that the variable **y** appears in the debug window and is given the value 0. Remember that before this point (step 1) the variable **y** was not known to the program.

Step 3 should show how **x** now holds the number 5. Step 4 should show how both **x and y** now have the same value. Finally, the last step should should show the the program ends with **y** having a value of 5 and **x** a value of 7.

![Debug 3](https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/debug2_3.png)


Although this may seem a trivial example, debugging is a very important part of learning any programming language. We will continue to use the debugger in future practicals to fix broken code and understand what is happening on each line of a program.

To end the debugging process, grab the blue break point marker and drag it away to the right to remove it.

## Operators

A crucial feature of any programming language is the ability to describe operations on data. For example we can use the + operator to add two numbers together.

```cpp
int sum = 10 + 5;
```

A list of common arithmetic operators is provided in the table below:

Operator | Meaning
--- | ---
" = " | Assign
" + " | Add
" - " | Subtract
" * " | Multiply
" / " | Divide
" % " | Modulus or remainder

*It's worth noting >> and << are also operators that we've used with std::cin and std:cout, however these are not arithmetic operators like those listed above.*


## Rules of precedence
It is important to consider the rules of precedence when creating arithmetic expressions. The operators * / % have higher precedence than the + - operators. This means that in a single expression, all * / % operators are computed prior to the + - operators. Therefore, you may have to use brackets to ensure that a calculation is performed as intended. An example is provided below: 

1 + 2 * 3 is computed as 1 + 6 = 7 whereas

( 1 + 2 ) * 3 is computed as 3 * 3 = 9

## Challenge Exercise: Simple Average
Write a program that reads two numbers from the user and computes their average.
To compute an average of two values, you can simply do the following (assuming that num1, num2 and result are our variables)

```cpp
result = num1 + num2 / 2.0;
```

The steps for getting started are as follows:

1.	Create two float variables called num1 and num2
2.	Use std::cout to instruct the user to enter the first number
3.	Use std::cin to read a number from the user
4.	Repeats steps 2-3 for the second number
5.	Compute the result using the above sum
6.	Use std::cout to print the result to the user

## Debug exercise
Give two reasons why the following code will the not work:

```cpp
std::cout >> "I am broken, please fix me…"
```

## Homework
Firstly, ensure that you have completed exercise 4.

Extend exercise 4 to use std::cin to read in the users choice of wave type but before switching on oscillators. Secondly switch on a second oscillator that has a frequency value that is twice the value of the original. Finally add a third oscillator that is half the value of the original. You should end up with a program that switches on three oscillators at the same time with a specified base frequency, amplitude and wavetype.


## Important Material

Knowledge of the following will be assumed in next week’s practical:

1.	The properties of the data types int, float, and std::string.
2.	The use and meaning of the while(true) loop. 
3.	The use of std::cin and std::cout to store and display variable values.
4.	The conventions for declaring and identifying/naming variables. 
5.	The basics of applying arithmetic operators to variables.






