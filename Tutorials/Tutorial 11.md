
## Practical 11 – Vector

In last weeks practical we learnt how to create arrays of a fixed length. This week we will learn to use an array whose length can grow and shrink dynamically at run time. We will learn:

1. How to create a vector
2. How to read and write data into a vector


Vector

The std::arry type allow us to create any number of variables of the same type in a single statement. For example, an array of integer variables for our 10 note numbers can be created by the following declaration: 

```cpp
  std::array<int, 10> notes;
```

We can then put numbers in this sequence like so.
```cpp
  notes[0] = 60;
  notes[1] = 62;
  ...
```

However, once we reach:

```cpp
  notes[9] = 78; //end of array
  notes[10] = 80; //Error cannot do this
```

We cannot therefore store more than 10 values in this array without creating a larger array. There are many times where we cannot determine how many values we might want to store. Luckily there is a built in type we can use to solve this issue.

## Vector

A vector is a special type of array that does not have a fixed size, instead elements can be continuously added and the vector will resize automatically. To declare a vector type we do the following:

```cpp
  std::vector<int> noteVector;
```

std::vector is also a template class so requires you to supply the type of data the vector will store within the triangle brackets. In this case the vector can only hold ints.


To add data to a vector we use the class method push_back(), like so:

noteVector.push_back(60);

Each time we call push_back() the supplied value gets added to end of the list.

You can read and write to a vector using the same syntax we learned previously.

```cpp
  noteVector[0] = 10; //set first element
  int firstElement = noteVector[0]; //read first element
```

You can set the intial size of a vector using the class method resize and supplying a new size.

```cpp
  noteVector.resize(10);
```

However, like an array it is still possible to try and accesses out-of-bound values which results in unexpected behavior.

```cpp
  noteVector.resize(10);
  noteVector[12] = 48; //ERROR out of bounds
```


Both of these code snippets will achieve the same result.

```cpp
  std::vector<int> noteVector;
    
  //example 1
  noteVector.resize(3);
  noteVector[0] = 11;		 	
  noteVector[1] = 12;    	
  noteVector[2] = 13;			
  
  //example 2
  noteVector.push_back(11);
	noteVector.push_back(12);
  noteVector.push_back(13);
```


Note that doing the following, will first create a vector with 3 elements, and then add 14 as the fourth element in the array. Note, the first 3 elements will be uninitialized. 

```cpp
  std::vector<int> noteVector;
  noteVector.resize(3);
  noteVector.push_back(14);
```

## Exercise 1: Using a vector I

We will modify last weeks’ sequencer practical to use a vector instead. Firstly, reload your solution to practical 10, exercise 1. 

1.	Replace the std::array with a **std::vector**
2.	After the **std::vector** declaration call resize on the vector to set its size use the same size value as your did for your array

Your program should work exactly as it did before. We will now show another way to add data to a vector.

## Exercise 2: Using a vector II

To practice using a vector we will create a simple program that computes the average of a sequence of numbers. The code for this exercise is supplied <a href="">here</a>.

For this exercise you are completing a partially built program that is designed to average as many numbers as the user enters. We will be using a vector to store the numbers the user enters. You will need to add 4 lines of code to fix this program, the /* */ comment placeholders highlight the locations. Before adding the complete program to codebook make sure you leave suitable comments explaining the programs operation. You may delete the pre-supplied comments.

Instead of specifying an initial size for the vector we simply call **push_back** each time we want to add an element.

## Exercise 3: Building a music sequencer

We will now use our knowledge of vectors to build a fully fledged note sequencer. The steps to achieve this are as follows.

Use the supplied template on blackboard for starting this exercise. **You will also need to add your IAPSynth class as we have done previously.**

1.	First add a std::vector as a shared variable called **noteList**
2.	Add a second shared variable of type bool called **playBtn**, and set it to false.
3.	Uncomment the note and control change callback function **declarations** from IAP.h
4.	Add the required function **definitions** for both callbacks to IAP.cpp

## Note callback

Inside the note callback function add the incoming note number to the **noteList** only if the velocity value is above 0, you can use push_back() for this. You should also synthesize the incoming note.

## CC callback

Inside the CC callback set the **playBtn** variable to be true if the incoming cc number matches that of the Impulse keyboards ‘play’ button.


## Run 

Inside the run function add the following code.

1.	Inside the while loop add an if statement that checks to see if playBtn is true, else sleep for a short while
2.	If playBtn is true add the relevant code from the exercise 1 that cycles through and plays back notes from a vector.
3.	After the if statement place an aserveSleep(1).


If everything has been added correctly then you should be able to play as many notes as you like, and when you push play you should hear the notes you input played back to you.

Once you have the basic setup working add the following:
1.	Add two more if statements to the CC callback
2. If the user pushes stop then playback should be stopped
3. If the user pushes ‘record’ then you should clear the vector, to do this you can call the vector member function **clear().**


## Challenge exercises: Extensions

A number of extensions can be added to this program; you are encouraged to complete this before the next tutorial.

1.	Add a second vector that stores the velocity values for your input sequence
2.	Add a third vector that stores a time stamp for each event, you can get the current time by calling **aserveGetTime()**
3.	To make your sequencer play back in time complete the following:
4.	Before playback add the current time to the vector storing time stamps
5.	Instead of sleeping for a constant, subtract the current time stamp value from the next value in the time stamp vector, and sleep for this value instead.
6.	If the user pushes the reset button on the Impulse keyboard call the clear() method on each of your vectors which will remove all of their current content so the user can record a new sequence.








