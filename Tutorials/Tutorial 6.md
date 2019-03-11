
# Practical 6 Functions II

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


