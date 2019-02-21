# Practical 5 – Functions

In this practical we will learn how to create our own functions, enabling us to divide larger programs into smaller sub-components. On successful completion of this practical you will have an understanding of: 

1.	How programs can be organized into functions.
2.	How to declare, define and call your own functions.
3.	How to pass values into functions.
4.	How to return values from functions. 


## Motivation

We have so far used two different types of functions ones that we call, e.g. aserveOscillator(), pow() etc, and call back functions that we have processed, e.g. callbackNoteRecived. However, an important part of any programming language is to write your own functions. Functions enable multiple C++ statements to be executed by a single statement which is referred to as a function call. With the use of functions, large complex programs can be divided into smaller blocks of code which makes programs easier to design, read and maintain. 

It is possible to write your program **without** using custom functions, however your programs will end up being:
-	Extremely large
-	Difficult to maintain
-	Increased chance of errors
-	Impossible to read

## First function

To illustrate when we might to make a function, open up an empty project and copy the following code to the run() in IAP.h. Study the code inside the main run loop.

```cpp
  int numberA = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberA;

  int numberB = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberB;

  int numberC = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberC;

  int numberD = 0;
  std::cout << "Please enter a number : \n";
  std::cin >> numberD;
```

We can see that the four number statements are marginally different, but if we look closely we can see that the only thing that changes is the variable we are storing our data in. This a prime reason to use a function to avoid duplication of code.

## Exercise 1: Our first function

In the IAP.h file, place the following line of code under the FUNCTIONS label, after the run function that is already there.

```cpp
int readNumber ();
```

Back in our IAP.cpp file we need to write the following code under our main run loop.

```cpp
int IAP::readNumber ()
{
    int number = 0;
    std::cout << "Please enter a number : \n";
    std::cin >> number;
	   return number;
}
```

*The IAP:: part of our statements, means that this function is owned by the IAP class. Classes will be explored in later practical’s.*

We can now replace each block of code in our main run loop to use our new function.

```cpp
int numberA = readNumber();
```

Make sure the program operates as it did previously. You should now be able to see how much clearer the code is to read. We will now look at functions in more detail.

## Declaring Functions

When declaring your own function, there are two steps that should be taken before it can be used (or called). 

1.	Write a function **declaration** (in the IAP.h file, underneath the FUNCTIONS label).
2.	Write the function **definition** (at the bottom of the IAP.cpp file, after the run loop). 

The function **declaration** tells the compiler how the function can be used (to enable error checking at compile time), while the function **definition** specifies what the function does when it is called. 	



