
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

    		noteVector [0] = 10; //set first element
    	int firstElement = noteVector [0]; //read first element

You can set the intial size of a vector using the class method resize and supplying a new size.

noteVector.resize(10);

However, like an array it is still possible to try and accesses out-of-bound values which results in unexpected behavior.

    noteVector.resize(10);
    noteVector[12] = 48; //ERROR out of bounds


Both of these code snippets will achieve the same result.

  
    std::vector<int> noteVector;
    
    noteVector.resize(3);
    noteVector[0] = 11;		or 	noteVector.push_back(11);
    noteVector[1] = 12;    		noteVector.push_back(12);
    noteVector[2] = 13;			noteVector.push_back(13);



Note that doing the following, will first create a vector with 3 elements, and then add 14 as the fourth element in the array. Note, the first 3 elements will be uninitialized. 

    std::vector<int> noteVector;
    noteVector.resize(3);
    noteVector.push_back(14);

