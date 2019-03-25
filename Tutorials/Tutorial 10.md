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

