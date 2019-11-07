# Tutorial 5 – Functions

In this practical we will learn how common functionality in larger programs can be written as smaller sub-components called 'functions'. On successful completion of this practical you will have an understanding of: 

1.	How programs can be organized into functions.
2.	How to declare, define and call your own functions.
3.	How to pass values into functions.
4.	How to return values from functions. 

Practicals from here on will assume knowledge of functions so please ensure you complete this week’s practical. This is a very IMPORTANT practical.

## Motivation

C++ 'functions' enable multiple statements to be executed by a single statement referred to as a function call. We have already written programs which use functions, e.g. aserveOscillator(), pow() are both function calls. However, an important part of any programming language is to define your own functions - to group multiple statements together which can be called.  If you know how to do this, any large complex program can be divided into smaller blocks of code. This makes programs easier to design, read and maintain. 

It is possible to write your program **without** using custom functions, however your programs will end up being:
-	Overwhelmingly large
-	Challenging to understand
-	Difficult to maintain
-	Repetitive
-	Potentially error prone (e.g. typos in repetitions)


## First function

To illustrate when we might to make a function, open up an empty project and copy the following code to the run() in IAP.cpp. Study the code inside the main run loop.

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

Study the code above. 

There are four groups of statements, each marginally different. If we look closely, the only difference is the variable we are storing our data in. 

If you find yourself writing code like this, you should re-write it as a function. 
Doing so avoids duplication of code, and makes your code easier to change.


## Exercise 1: Our first function

In the IAP.h file, place the following line of code under the FUNCTIONS label, after the run function that is already there.

```cpp
int readNumber ();
```

Back in our IAP.cpp file we need to write the following code under our main run() function.

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

We can now remove repeated blocks of code in our IAP run function to use our new readNumber function.

```cpp
int numberA = readNumber();
```

Make sure the program operates as it did previously. You should now be able to see how much more clear the code is to read. We will now look at functions in more detail.

## Declaring Functions

When declaring your own function, there are two steps that should be taken before it can be used (or called). 

1.	Write a function **declaration** (in the IAP.h file, underneath the FUNCTIONS label).
2.	Write the function **definition** (at the bottom of the IAP.cpp file, after the run loop). 

The function **declaration** tells the compiler how the function can be used (to enable error checking at compile time), while the function **definition** specifies what the function does when it is called. 	


The general form of the function declaration is as follows: 

```cpp
return-type functionName ( argument-type(s) ); 
```

The return-type indicates the data type of the value which is returned from the function. The argument-types indicate the data types of any values that are passed into the function. The function-name should indicate what the function does. 

The readNumber() function provided at the beginning of this practical does not take any arguments, but returns an int. C++ functions can take many arguments but only return one. If a function does not return anything, the return type must be written as **void**.

Examples of a few function declarations are shown bellow.

```cpp
//A function that does not return anything, nor have any arguments

void makeErrorTone ();

//A function that does not return anything, but takes a single argument.

void printTime (int time);

//A function that returns a int value, and takes a single argument.    

int covertCtoF (int centigrade);

// A function that does not return anything, but takes 3 arguments.

void setNote (int note, int velocity, int wave);
```

## Function Definitions

Function definitions should appear in IAP.cpp separated from the IAP::run() function. The first line of the definition should match the declaration, but have the IAP:: statement placed between the return type and function name. This must be followed by opening and closing braces that enclose the statements that are to be executed when the function is called. Note that the semi-colon included in the declaration is not used in the definition.

## Exercise 2: mtof function

Back in practical 3 we used a formula for converting note numbers into frequencies. This formula will be used frequently throughout this module, so it would make sense to put this code inside a function. Download the practical 5.2 files from [here](https://github.com/Sjhunt93/IAP-2019-2020/tree/master/Code%20Exercises/Tutorial%205/Exercise%202) and copy in the code for both the .h and .cpp file.

The prototype for the mtof function looks like this:

```cpp
float mtof (int note);
```

Our mtof function takes an int (midi note number) as its argument and returns a float (frequency).  The steps to achieve this our as follows:

1. Add the mtof function **declaration** to the IAP.h file.
2. Add the mtof function **definition** to the IAP.cpp file.
3. Put the relevant code from our note callback function into our mtof function.
4. You will need to use the return keyword to **return** the value of frequency.
5. Use the mtof function to calculate our frequency value.
6. Pass the frequency value to our oscillator function.	  

Now we have an mtof function it should be very easy to add a second oscillator whose frequency value is 7 semitones higher than our original note. 

## Exercise 3: Chord Machine 

We will now create two more functions, called **majorChord** and **minorChord**. These functions will take a single argument (a note number) but not return anything. 

The **major** function will covert three note numbers to frequencies and supply these to three separate oscillators. The first frequency value will be calculated on the supplied note number, the second frequency will be calculated based on the supplied note number + 4, and the third note number + 7.

The minor function is the same except oscillator two will be calculated based on the original note number + 3.

The code for the note callback function is supplied bellow, **ensure that you have correctly added the two chord functions before trying to run the code**. The bottom 4 drum pads on the impulse control correspond to the 4 chords. 

```cpp
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (note == 60)
    {
        majorChord(60); // C Major
    }
    else if (note == 62)
    {
        majorChord(65); // F Major
    }
    else if (note == 64)
    {
        majorChord(67); // G Major
    }
    else if (note == 65)
    {
        minorChord(69); // A Minor
    }
}
```

## Exercise 4: More Chords

Add 2 or more chord functions, some suggestions for chords are given bellow. You should map these chords to the other 4 drum pads.

| Chord Name | Intervals |
| --- | --- |
| Major 7 | +4, +7, +11 |
| Minor 7 | +3, +7, +10 |
| Dominant 7 | +4, +7, +10 |
| Diminished | +3, +6 |
| Maj7 add6 | +4, +7, +9 |
| Min7 add6 | +3, +7, +9 |
| Sus4 | +5, +7 |
| Sus2 | +2, +7 |

## Debug Exercise.

Open debug exercise 5 and then fix the broken exercise. Make sure you save your solution to codeBook.

https://github.com/Sjhunt93/IAP-2019-2020/tree/master/Code%20Exercises/Tutorial%205/Debug

## Challenge Exercise: 

Add a nested if statement to the note callback function in exercise 4 so that chords are only switched on when the velocity value is greater than 0, otherwise turn off all the current oscillators. 

## Important Material:

Further practicals assume knowledge of functions so please ensure you have completed this week’s practical. This is a very IMPORTANT practical!

Understanding of the following will be assumed next week: 

1. How programs can be organized into functions.
2. How to declare, define and call your own functions.
3. How to pass values into functions. 



