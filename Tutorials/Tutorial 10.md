# Practical 10 – Arrays


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
