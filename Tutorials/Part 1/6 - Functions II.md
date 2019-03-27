
# Tutorial 6 - Functions II

Functions continue to be one of the most important concepts in building larger programs. In this practical we will focus on how to share variables between functions effectively. On successful completion of this practical you will have an understanding of:

1.	Variable scope
2.	Memory addresses
3.	When to declare shared variables in the IAP.h

## Getting started

Last practical we looked at functions and we will continue to do so in this practical also. **Please ensure you have completed last weeks practical, before attempting this one**. Reload your solution to practical 5 exercise 2: mtof function.

## Exercise 1: Variable scope

Add the following code to your IAP.cpp (bellow the run function) replacing the existing note callback function. 
Remember to uncomment the modwheel callback function from IAP.h 

```cpp
void IAP::callbackModWheelMoved (int value)
{
  int wave = 0;
  if (value >= 64)
	{
    wave = 1;
  }
	else 
	{
	  wave = 0;
	}
}
```

```cpp
void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
  int wave = 0;
  if (velocity > 0)
	{
    float frequency = mtof(note);
    aserveOscillator(0, frequency, 1.0, wave);
  }
  else
	{
    aserveOscillator(0, 0, 0, 0);
  }
}
```

This code is designed to switch between a sine wave and a square wave depending on the position of the modwheel. Run the program and check that this works correctly.

# Error
If we look closely at our program, we can see that we have two variables with the same name but they not do refer to same variable. To verify this, we will print the address of the variable. The address of a variable is it’s location in the computers RAM (random access memory). Every variable in C++ has a unique memory address.

# Exercise 2: Printing address

To print the address of a variable you can use the following line of code:

```cpp
  std::cout << "Address of variable : " << &wave << "\n";
```

The & symbol is used to get the address of a variable, make sure you place one of these statements in both the mod wheel and note callbacks. Modify each so you can distinguish each print statement appropriately. 

Now when you run the program again you should see that the address printed for each of the wave variables is different. (note that you will have different address values to those shown bellow)

```cpp
Address of variable wave (mod): 0x1013d2990
Address of variable wave (note): 0x1013d2988
```

The reason for this issue is because of our **variable scope**. When you declare a variable inside a function it exists only for as long as the function is being called. In the code bellow we can see that **int wave** will only exist when the function is called and then disappear once the function exits. 

```cpp
void IAP::callbackModWheelMoved (int value)
{
    int wave = 0; // declare new variable here
    if (value >= 64 ) 
    {
        wave = 1;
    }
    else  
    {
    	wave = 0;
    }
} // int wave will out of scope here.
```

## Exercise 3: Shared variables

To fix this issue we need to add a **shared variable** to our IAP.h file. Shared variables are variables that can be accessed between functions. Shared variables also retain their value while the program continues to run. Navigate to our IAP.h file and add a variable called **wave** of type **int**. Place this under the SHARED VARIABLES label.

```cpp
//-------------------------------------------------------------
// SHARED VARIABLES
int wave = 0;
```

Go back to our IAP.cpp file and delete both occasions where our old int wave variables were being declared. Re-run our program and check to ensure that our wave type switch code is working correctly. You should also see the same address value is now printed in both callbacks (again your exact address will be different to those shown bellow).

```cpp
Address of variable wave (mod): 0x7fff5fbff7bc
Address of variable wave (note): 0x7fff5fbff7bc
```

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/sharedvariables.png" height=300/>


Note that in both functions they are now sharing the same single variable wave.

## Exercise 4: Fix noteoff

For a number of weeks, you should have encountered a bug with the monophonic synths that we have been building. If you press and hold a note with your left hand and then a second note with your right hand, you will notice that the oscillator is stolen by the most recently pressed note - the right hand note. If you now release the left hand note the oscillator should stop, even though the right hand note is still pressed. 

Extend the previous program such that the oscillator is only switched off when the note number of the ‘note off’ message matches the note being played by the oscillator. 

The steps to complete this are as follows: 

1. Create a new shared variable in the IAP.h file called currentNote and set its initial value to be -1
2. When the oscillator is switched on (inside the callback) set currentNote to be equal to the note number.
3. When Note Off messages are received you can compare the Note Off number with the currentNote variable and if it matches you switch the oscillator off and set the currentNote back to -1, otherwise you leave it on. You will need to modify the *else* statement in the callback to use an *else if*

## Debug Exercise

For each of these functions give a single reason for why each one is incorrect. If you are unsure have a look back at examples from last weeks practical. 

**You can assume that the functions have been declared correctly inside IAP.h**

### 1:
```cpp
void IAP::getFrequencyValue ()
{
    float freq;
    std::cout << "Please enter a frequency";
    std::cin >> freq;
    return freq;
}
```

### 2:
```cpp
void IAP::calculateSum (int a, int b);
{
    int result = a+b + a*b;
    std::cout << "Result: " << result << "\n";
}
```

### 3:
```cpp
void IAP::playNote (float frequency, float amplitude)
{
    aserveOscillator(0, frequency, amp, 0);
}
```

### 4:
```cpp
float IAP::tuneNote (float frequency)

    frequency = frequency * 1.5123;
    return frequency;
}
```
*The most common programming mistakes, are: missing brackets, missing braces, spelling errors, and semi-colons where they are not supposed to be.*

## Challenge Exercise: Pitch bend

Using what we have learned so far, you need to add the following code to your project. Think carefully about where each piece of code needs to be placed. You are adding a pitch bend feature that will control the frequency of the oscillator in real time.

```cpp
1.	void callbackPitchbendWheelMoved (int value);
2.	void IAP::callbackPitchbendWheelMoved (int value)
	{
    
	}
3.	int pbValue = 0;
4.	pbValue = (value / 16383.0) * 24 - 12.0;
5.	float frequency = mtof(note + pbValue);
6.	float frequency = mtof(currentNote + pbValue);
7.	aserveOscillator(0, frequency, 1.0, wave);

```

You may notice that the pitchbend function steps, rather than glides smoothly, have a look through the code and see at what point integer arithmetic is being used, when floating point arithmetic should be used instead.

## Important Material

Understanding of the following will be assumed in next weeks practical: 

1. When to place variables inside the IAP.h file
2. How to share data between functions
3. Variable scope




