
# Practical 15 – Bit wise manipulation

In this practical we will learn about bitwise manipulation - a powerful feature of the C ++ language that enables variables to be accessed and modified at the bit level. On successful completion of this practical you will understand: 

1.	The binary representation of integer numbers.
2.	How the bitwise operators &, |, « and » can be used to isolate bits and merge binary data. 
3.	How to communicate with Aserve’s Bit Representation component. 

## Introduction

C++ is a powerful and widely used programming language as it features the many advantages of a high-level language in addition to many useful operations which are usually associated with low-level languages. Bitwise manipulation is a low-level feature which is used in embedded systems (where a computer is an internal part of a larger system, such as an industrial process or a digital mixing console) and systems programming (where software often deals directly with the underlying hardware devices). Furthermore, raw MIDI requires bit wise operations to extract all of its contents.

## Decimal and Binary Forms

The representation of binary integers has been discussed in a previous practical. The following is a reminder of the basic ideas: 

In a decimal (base 10) number, the value of each digit is between 0 and 9. The position of each digit within a number indicates the power of 10 multiplied by that digit. That multiplier increases by a factor of 10 each time the position moves one digit to the left. For example, for a decimal number with 6 digits the multipliers are as follows: 

-> insert image 6bit

In a binary (base 2) number, the value of each digit is 0 or 1. The position of each digit within a number indicates the power of 2 multiplied by that digit. That multiplier increases by a factor of 2 each time the position moves one digit to the left. For example, for a binary number with 16 digits the multipliers are as follows: 

-> insert image 16 bit

Note that bits are numbered from 0 to 15 in a 16-bit number. The value of each multiplier is calculated by the formula 2n where n is the bit number. Some example binary to decimal conversions are as follows: 


| Binary | Decimal |
| --- | --- |
| 0000000000000111 | (4 + 2 + 1) = 7 |
| 0000000000001110 | (8 + 4 + 2) = 14 |
| 1000000000000001 | (32768 + 1) = 32769 | 
| 1111111111111111 | (32768 + 16384 + 8192 + 4096 + 2048 + 1024 + 512 + 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1) = 65535 |

Any integer in the range 0 to 65535 can be represented by a 16-bit binary number. Note that this is an **unsigned** integer so only positive values can be stored. 

## Exercise 1: Aserve Bit Representation 

Aserve contains an 16x16 grid, that serves both as an input interface and graphical visualizer. We will discuss getting input from this bit grid shortly, but first we will look at setting the grid. 

Each row of the grid is set by a single value, in this case a 16-bit number whereby each bit represents a column from right to left. The following function can be used to set the grid:

```cpp
aserveSetPixelGrid(int row, int value);
```

To visualize this set the first 6 rows to have the following values. (place all code inside the run() function)

1, 255, 256, 170, 32769, 65535


*Try also experimenting with your own choice of numbers.*

## Exercise 2: Using the pixel grid callback

When the bit grid is clicked inside Aserve it triggers a callback inside our IAP class.

```cpp
void callbackPixelGrid (int x, int y);
```

The callback provides two arguments corresponding to the x & y positions of the click. You should uncomment and implement the callback, printing the x and y values. Once you have done this write down the values of the top left and bottom right values and keep these for future reference.

You may notice that as you click the grid the callback triggers but the grid itself does not update its visual state. The interface and visualizer are intentionally decoupled from each other. We have already seen how to set the grid itself, but what we now need to do is covert the x value into a bit representation. 


## Bit shifting

We have previously seen the << and >> operators used for inserting variables into streams. However, they are also used as the bit shift operators. They left shift (<<) operator will shift all the bits inside a variable up by a given number of places. For example:

```cpp
    int a = 1;
    a = a << 1;
```

In the above code, ‘a’ is now equal to 2, as it the bit that was representing the **1**, was shifted left into the bit representing **2**. If we shift the value 13 left by 1 place, we get 26, see the below table for a visual representation of this.

```cpp
13 << 1
```

| Bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 | value |
| --- | --- | --- | --- | --- | --- | --- | --- |  --- |
| 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | --- |
| 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 13 |
| 0 | 0 | 0 | 1 | 1 | 0 | 1 | 0 | 26 |

If you use the shift left operator the upper values can get lost. For example, if our variable is an 8-bit data type, and the top bit is 1, shifting this value left by 1 will result in the loss of this top bit.

```cpp
133 << 1
```

| Bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 | value |
| --- | --- | --- | --- | --- | --- | --- | --- |  --- |
| 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | --- |
| 1 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 133 |
| 0 | 0 | 0 | 0 | 1 | 0 | 1 | 0 | 10 |

The right shift operator is same as the left shift operator but shifts the bits in the opposite direction. Bits can also be lost by shifting them too far to the right. The general form of the bit shift operator looks like the following:

```cpp
/* variable or constant to shift */ << /* number of bits to shift by*/

/* variable or constant to shift */ >> /* number of bits to shift by*/

```

To set an individual bit of a variable the following code can be applied:

```cpp
int a = 1 << 7;
```

Using what we have learnt so far, add code to your bit grid callback that updates the state of the grid when the user clicks on it, to reflect the location they have just clicked. 

Note that bits are represented from right to left whereas clicks are reported from left-right. You will need to use the following code at the top of your callback to invert x.

```cpp
x = 15 - x;
//... code for setting the grid.
```

Once you have completed this exercise you should encounter a strange bug, write a description of this somewhere safe, we will fix this later on in the practical!

## Bit wise operators

There are two more important bit wise operators that we need to know about, bit wise and (&) and bit wise or (|). These are very similar to the logical and/or operators (&&, ||) except they compute the result for each bit.

If you have not done so already download the Binary Grid application from blackboard. Using the application compute the following values and note down their value. Note that you do not need to write code for this exercise.

| Value a |	Value B | Operation | Result |
| --- | --- | --- | --- |
| 0000 1111 | 0000 0000 | or | --- |	
| 0000 1111 | 0000 0000 | & | --- |	
| 0100 0000 | 0100 0000 | or | --- |	
| 1010 1010 | 0101 0101 | or | --- |		
| 1010 1010 | 0101 0101 | & | --- |	
| 1001 0000 | 1111 0000 |& | --- |

Based on this we can update bits within a variable using the following code. 

```cpp
int a = 2;
a = a | 8;
```

## Bit wise NOT and XOR

There are two other bit wise operations worth mentioning. The first bit wise not (~) will simply invert each of the bits. For example, the binary value:

~0000 0001 	will become 	1111 1110

The Bit wise not operator is reasonably uncommon, however the bitwise XOR (^) is even more so. The output of the XOR operator is 1 if the individual bits are different. The truth table for this is given below:

| Input A | Input B | Result |
| --- | --- | --- |
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1	| 0 |


