will put both homeworks in here.

# Constants, defines and enums: Homework exercise

So far we have either used variables or literals to represent data. However, there are many occasions where we might to define a constant value, in essence a variable whose value cannot be updated or changed. We will explore 3 topics in this exercise:

1.	Consants
2.	Defines
3.	enums

# Constants

In previous exercises we have written code that looks like the following:

```cpp
  float freq = 440.0 * pow(2.0, (note - 69.0)/ 12.0);
  aserveOscillator(0, freq, 1.0, 0);
```

In this situation the variable freq is set once and following on from this its value never gets updated. This is a perfect occasion for making the freq variable a constant.
  
```cpp
  const float freq = 440.0 * pow(2.0, (note - 69.0)/ 12.0);
```

The const keyword can be placed in front of any variable and means that after the variables value has been set it can no longer be updated, and is read only.

```cpp
  const float concertPitch = 440.0;
  concertPitch = 443.0; //will produce a compiler error!
```

Using consts can also make your program more readable. For example, when checking for CC’s we often simply state the number of the CC as a literal.

```cpp
  if (cc == 115) {
```      

Instead using constants, we get the following:

```cpp
  const int playBtn = 115;
  
  if (cc == playBtn) { //easier to read
```

Constants are often placed either at the top of our program between the includes and run function. **This is one of the few times variables should be declared here**. They are often also placed inside class's as member variables.


## Defines

Defines can also be used to define constant values. The general form of a define is:

```cpp
#define SYMBOL value
```

For example, in this instance, the symbol COLUMNS holds the value 16.

```cpp
#define COLUMNS 16
```

And can be used for doing the following (shown below) In essence a define is a find and replace, whereby the compiler will actually swap each occurrence of COLUMNS for the value 16. Like const, define is a method for making code more readable

```cpp
for (int i = 0; i < 16; i++) {

for (int i = 0; i < COLUMNS; i++) {
```

A define is generally not recommended for defining constant values, and you are encouraged to use const instead. Define can however do things that const cannot, for example:

```cpp
#define SLEEP_500 aserveSleep(500);
```

Therefore, anytime you want to sleep for 500ms you can write SLEEP_500.

```cpp
SLEEP_500
```

It is worth knowing about define for the purposes of learning the C++ language however it has limited use for this course. Define can solve some very tricky programming problems, but is also frequently abused!

## Enum

The last type of programming construct you an use for defining constants, is an enum. An enum is shorting for enumeration and allows a series of constant symbols to be defined in a series, whereby each enums value is +1 of the previous value. We could use an enum structure for defining each wave types numerical value.


```cpp
    enum eWaveTypes {
        eSine = 0,
        eSquare, //will have the value 1
        eSaw,
        eReverseSaw,
        eTri,
        eNoise //will have the value 5
    };
```

Be default the enums first entry will be given the value 0, however you should always specify a value even if it is still 0. The value of eSquare will be 1, eSaw will be 2 and so on.

Now when we wish to turn on an oscillator we can write the following:

```cpp
aserveOscillator(0, 440.0, 1.0, eSine);
```

Which is more readable than:

```cpp
aserveOscillator(0, 440.0, 1.0, 0);
```

The general form of an enum is as follows:

    enum name {
      entry0 = 0,
      entry1
    };
    
Each entry should be separated by a comma, and the statement should end with a brace and semicolon. enums should be placed in inside a class. By convention enums should start with a lowercase **e**.
 
You can also group constants in an enum that are not necessarily sequential, but you must define the value of each.
 
```cpp
    enum eControls {
        eKnob1 = 21,
        eSlider1 = 41,
        ePlayBtn = 115,
    };
```

## Enums as types

An enum can also be used as a variable data type.

```cpp
eWaveTypes waveType;
```

However, be aware than you can only assign values to waveType that were specified in the eWaveType enum.

```cpp
    waveType = eSaw; //is fine
    waveType = 2; //compiler warning
```

*Note that it is possible to assign integer values directly to an enum type (see below) but is mostly discouraged*

```cpp
  eWaveTypes waveType;
  int waveInt = 3;
    
   waveType = static_cast<eWaveTypes>(waveInt);
```

## Exercise 1: Code refactoring

Obtain a copy of the following <a href="files">files</a> copy them into your project. You will be refactoring this project to make use of the topics we discussed in this handout. 

1.	You should make any variables const that are not going to be modified after being initiliased
2.	Replace any arbitrary literals with constants
a.	Note that values within calculations are fine as they are.
3.	Make use of at least one enum
4.	Ensure you save your solution to codebook
5.	Remember to check your solution with one of the lecturers during next week’s tutorial



 
