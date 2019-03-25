# Tutorial 16 – Some more C++

In this practical we will learn about a few additional topics that you might find useful for the assignment, as well as learning more about C++.

1.	2D arrays
2.	Auto
3.	Range based for loops
4.	Ternary operator
5.  	Version control

## 2D arrays

We have looked at using single dimension arrays, however there are a number of occasions where we might want to have arrays with more than one dimension. For example, we can create a 10 x 10 array by applying the following:

```cpp
std::array< std::array<int, 10>, 10> tenByTen;
```

To access each dimension, you use another set of [] brackets.

```cpp
tenByTen[0][0] = 10;
```

The general form of a 2D array looks like:

```cpp
std::array< std::array<int, /* inner size*/>, /*outer size*/> tenByTen;

tenByTen[/*outer index*/][/*inner index*/]
```

## 2D vectors

You can also have 2D vectors, however they are a little more challenging to conceptualise as each row can have a different size.

```cpp
std::vector< std::vector<int> > _2dVector;
```

And just to make things more complicated you can also have a vector of array, or any combination of such data structures:

```cpp
std::vector<std::array<int, 10> > vectorOf10ElementArrays;
```

## Exercise 1: 

We will be remaking our scale function.

We will be using a 2D std::array with an inner size of 12 and an outer size of 8. This array will hold scale information and allow us to quickly quantize note numbers into a scale. The outer index will specify the scale number, and the inner number will specify each scale degree. We can set the values for a single scale by using the following line of code:

```cpp
  scales[0] = {0,1,0,1, 0,0,1,0, 1,0,1,0};
```
	
Note that we must supply as many arguments between the {} as there are elements in the array, as there are 12 elements for the inner size we must supply 12. Note that the above code is a shortened version of doing:

```cpp
  scales[0][0] = 0;
  scales[0][1] = 1;
  scales[0][2] = 0;
  ...
```

To get started:
1. Reload a previous synthesiser program to use for this exercise.
2. Create a shared std::array called scales as specified above.
3. Create a shared variable called chosenScale.
4. At the start of your run function setup the scale values.
5. You can use the following code snippet to quantise notes to a scale.

```cpp

int pitch = note % 12;
return note + scales[chosenScale][pitch];

```

## Auto

In C++ we have to define the type when declaring a variable. However, in other programming languages **type** is inferred by the complier. There are occasions in C++ when we can use the auto variable data type to allow the compiler to determine the data type for us.

```cpp
   auto a = "hello";
   auto b = 10;
   auto c = 0.5;
   
   std::cout << a << ", " << b << ", " << c << "\n";
```

When we run a program contain the above code and then open the debugger we can see that these variables have data types determined by the compiler.

<img src="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Tutorials/images/autotypes.png" height=200/>


If you can determine the data type yourself then you should declare it as such, however there are a number of useful occasions where we might use the auto type. We will return to this at the end of this tutorial.


## Range based for loops

We have been making frequent use of the following code snippet to iterate over the contents of arrays and vectors:

```cpp
    std::vector<int> values = {0, 1, 3, 5};
    
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << "\n";
    }
```

However, there is variant of the for loop that we can use instead:

```cpp
    for (int i : values) {
        std::cout << i << ", ";
    }
```

We are creating a temporary variable as we did before, followed by the single colon **:** operator, and then we supply the array we wish to iterate over.  

Range based for loops will iterate over each value from the starting position 0 up to the last element. Note that the value **i** will hold a copy of the value at each index. So therefore, this loop is only able to read each element. We can adapt this code by using the & operator, to take a reference to each element in the array, therefore we can both read and write data. However, you should only use the & operator if you really need to modify each element!

```cpp
    //Double each element
    for (int & i : values) {
        i *= 2;
    }
```

Note then when using range-based loops, it is very common to the replace the data type with an auto type.

```cpp
    //Double each element
    for (auto & i : values) {
        i *= 2;
    }
```

## Exercise 2: Range based for loops
Refactor a previous program that you have written to use a range based for loop. Practical 10 exercise 3 or practical 11 exercise 3 are good starting points, however you may choose a different one.

## Ternary Operator

We have previously seen and used the following code (waveType is a shared variable) 

```cpp
void IAP::callbackModWheelMoved (int value)
{
    //Switch between sine and saw
    if (value < 64) {
        waveType = 0;
    }
    else {
        waveType = 1;
    }
}
```

Instead of using an if-else statement we can use the **Ternary** operator:

```cpp
void IAP::callbackModWheelMoved (int value)
{
    //Switch between sine and saw
    waveType = value < 64 ? 0 : 1;
}
```

The general form of a Ternary operator is as follows:

```cpp
   (condition) ? true value : false value;
```

The condition is first checked, then if the condition is true the value following the ? operator is returned, otherwise the value following the : operator is returned instead. Ternary statements can be used to significantly reduce the size of code. In this example we have replace 6 lines of code with 1.

The ternary operator can also be used to call functions:

```cpp
    if (filterType == 1) {
        aserveHPF(cutoff);
    }
    else {
        aserveLPF(cutoff);
    }
```
or:

```cpp
   (filterType == 1) ? aserveHPF(cutoff) : aserveLPF(cutoff);
```

## Exercise 3:

Use the ternary operator to refactor a previous program that you have written.


## Git





