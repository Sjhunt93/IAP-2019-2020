# Tutorial 16 – Some more C++

In this practical we will learn about a few additional topics that you might find useful for the assignment, as well as learning more about C++.

1.	2D arrays
2.	Auto
3.	Range based for loops
4.	Ternary operator
5.  Version control

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

We will be remaking a scale function.

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



