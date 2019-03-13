
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




