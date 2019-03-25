# Tutorial 10 – Arrays


In this practical you will learn how to create and work with arrays: a useful data structure that enables lots of variables of the same type to be collected into a single data structure. We will learn: 

1. How to create an array
2. How to read and write data into an array
3. How to refactor variables into an array


## Array

When writing a program that stores a single value, previously you have created a single variable specifically for the job. If it is necessary to store multiple values, multiple variables must be declared. For example, if a problem requires us to store four separate note numbers, we could write the following declarations: 

```cpp
    int note1;
    int note2;
    int note3;
    int note4;
```

This method is acceptable, to a point, but becomes cumbersome when we require many more variables (imagine trying to store a sequence of 1000 integer notes, or one second of CD quality audio (2 × 44100 floats)!). Arrays allow us to create any number of variables of the same type in a single statement. For example, an array of integer variables for our four note numbers can be created by the following declaration: 

```cpp
std::array<int, 4> notes;
```

Each element of the array can be used like any normal variable, but must be accessed using the element index in the correct format. This is achieved by writing the array name followed by an element number (**index**) enclosed within the **square brackets [].** The array syntax for setting each element of the notes array is shown below. 

```cpp
notes[0] = 60; //set the first element to be 60
notes[3] = 67; //set the last element to be 67
```

Note that array indices always start at 0 for the first element and go up to the array’s size minus one. Note that doing the following is invalid.

```cpp
notes[4] = 69; //ERRROR! out of bounds
```
## General form

The general form of an array declaration is as follows.

```cpp
std::array<type, size> name;
```

```cpp
std::array
```
This is the type specification for creating an array, in C++ arrays belong to the std library and look similar to std::string.

```cpp
<type, size>
```
std::array is a type of template class (an advance C++ topic) and so requires some us to use some new syntax. The triangle brackets ( < > ) are used to tell the compiler what kind of array you want. Two arguments are supplied; the first is the **type** which can be any of the data types we have covered so far (int, float, bool etc) but can also contain more complex data types (e.g. classes). The second is the **size** of the array, this is how many elements you want to store.

```cpp
name;
```
The last part of the array declaration is the **name** of your array. Array names should by convention start with a lower-case letter.

Note that once an array has been created it can only hold the data types specified from its declaration. For example, it can only hold **ints or floats, not a mix of both.** Also note that once the size of the array is set it cannot be changed. We will cover resizing arrays in the <a href="">next practical</a>.

## Size

To get the size of an array the following code can be used (shown below). The size function is a class method for the std::array class, and returns the number of elements in the array.

```cpp
array.size()
```

## Exercise 1: Creating our first array

We will now create a simple program using an array to hold a sequence of notes, and play these back in order. To complete this exercise, rearrange the following snippets of code. All code should be placed inside the run() function. Note you will need to use and include your mtof function for this exercise (or use your synth class from last week)

```cpp
1.	 int note = notes[i]; // get element at index 'i'
2.	 aserveSleep(500);
3.	 for (int i = 0; i < notes.size(); i++) {
4.		std::array<int, 4> notes;
5.	  }
6.	 aserveOscillator(0, mtof(note), 1.0, 1);
```

**Finally, after the declaration of the array but before the for-loop you will need to put values into each element of the array, refer to the previous page if you are unsure of how to achieve this.**


## Exercise 2: Second array

Extended the previous exercise to include a second array for storing amplitude values. The static **1.0** value for amplitude inside the call to aserveOscillator should be replaced by the value from this new array. This new array should be called **amps** and be of type **float** and be the same size as the other array. 

## Exercise 3: refactoring 

For this exercise we will be refactoring a badly written program using arrays. You will need to download the files from <a href="">here</a>, and copy them into your project overriding the contents of your existing .cpp and .h files.

**Note for this exercise we will be using the IAPSynth class that we built during last weeks practical. You will need to complete last weeks practical before starting this one. You will need to add the IAPSynth class to the top of IAP.h.**

The current program is designed as follows. As a slider is moved and the callback is triggered the first 4 slider values (CC41 – CC44) are checked and their current position stored in 1 of 4 slider variables. These variables are then used as `note’ values to trigger notes in our synth. We therefore have a 4 step step-sequencer. The program should work without error; however, it is inefficient. Follow the steps bellow to refactor this program using an array.



1.	Remove the 4 slider variable declarations from IAP.h and replace this with a single **std::array** declaration called sliderValues. This array should have 4 elements.
2.	Inside our CC callback replace each old slider variable to use the sliderValues array.
3.	Inside our run() function replace each old slider variable to use the sliderValues array.

Your program should operate as it did previously, however it is not much more concise than the previous version. However, we can still do more!


### Part 1
1.	Inside the our **run()** function create a for-loop that starts at 0 and goes up to the value of sliderValues.size().
2.	You can now place a single call to **synth.playNote**, and **aserveSleep** inside the for loop.
3.	Think carefully about how you might access each element of the array.

**Ensure you test your program before moving on!**

### Part 2
1.	Remove the switch case structure from the CC callback. 
2.	Then add the following code inside the if-statement

```cpp
sliderValues[cc-41] = value;
```

Your finished program should operate exactly the same as before but this time be a lot more concise. The process of refactoring is about restructuring existing code so that it is cleaner and more concise without changing its functionality. If you compare the program you had at the start of this exercise with what we have ended up with, you should clearly see the difference.

**Before moving on and saving your solution to code book, ensure that your program is suitability commented.**

## Exercise 4: 8-step sequencer 

It should now be relatively easy to extend our program to use 8 rather than 4 steps. Something that would have been much harder had we used 8 single variables instead of an array. To achieve this:

1.	Change your **arrayValues** array to be 8 elements in size rather than 4
2.	Modify the the CC callback accordingly 

By changing only two lines of code we have gone from having a 4-step sequencer to an 8-step sequencer. Using arrays allows our programs to scale very quickly and we end up writing a lot less code.

## Exercise 5: Amplitude control

Add a second array called **rotaryValues**, that get their values from the 8 rotary controls on the impulse keyboard. These values should control the velocity argument of the synth.playNote function call.

## Challenge exercises: Extensions

A number of extensions can be added to this program. Feel free to try adding your own features also.

1.	Before writing the CC’s value into the sliderValues array, scale it so that it has a range between 48 and 72.
2.	Before passing the sliderValue into the playNote function call, pass it through one of the scale functions we developed last term, therefore creating a more ‘musical’ application.
3.	Modify the for loop so that it plays in reverse.
4.	Add an option so that the user can toggle between the loop playing forward and the loop playing backwards.




