# Practical 14 – Files & String manipulation

In this practical you will learn how data can be written to, and read from files. This enables text, variable values and other program data to be saved into an external file on the computer’s file system between program runs. 

On successful completion of this practical you will understand: 

1. How to create, open, and close files. 
2. How to write data to a file
3. How to read data from a file 
4. How to manipulate std::string

## Files

Files are blocks of data that are saved on the file system of a computer’s storage devices. Files may contain text, music, images or any other type of data that can be stored on a computer system. Data which is internal to a computer program (variables) disappear when a program exits, so files are useful for storing data between independent runs of a program. The standard C++ library **fstream** provides a selection of basic file manipulation functions. 

## fstreams

We have previously used C++ standard input/output stream to read text input from the user, or display text to the user in the console window. Similarly, C++ provides us with a set of file input/output streams, and these can be defined as follows:

```cpp
  std::ofstream fileOutput;
```

std::ofstream is used for representing the outward file stream and is used to write data to files.

```cpp
  std::ifstream fileInput;
```

std::ifstream is used for representing the input file stream and is used to read data from the file system.
