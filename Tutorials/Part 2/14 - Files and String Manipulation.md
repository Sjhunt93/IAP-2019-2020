# Tutorial 14 – Files & String manipulation

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

## Opening a file

To use a file stream we first declare the type of stream we want to open, either in an input or output. As the streams are data types we also have to give them a name.

To actually open a file we need to use the member function open(), which will associate a file stream variable with a file stored on our computer’s hard drive. The syntax for the open() function is as follows:

```cpp
  fileVariable.open("path", options);
```

## Path 

The first argument of the open function is the files path, this is either the location of the file on your computer’s hard drive, or the location where you wish to create a new file. Folder paths a separated with the / symbol (use \\ on windows). For example, an **absolute** file path may look like this:

"/Users/sj4-hunt/Documents/IAP-2018-2019/sounds/bd.wav"

## Options

The second argument allows us to supply a number of options to the **open** function. The most common ones that we will use are the **std::fstream::in** and **std::fstream::out** constants. We will explore these as we go through the practical.

Once a file is opened we can then call the fstream member function **is_open()** to check if the file is actually open before trying to go any further.

```cpp
  if (fileInputStream.is_open()) {
    //file is open
```

Once we are done with the file we need to close it. We simply call the member function close (). 

```cpp
  fileInputStream.close();
```

## Exercise 1: Reading from a file

Please download <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Code%20Exercises/Tutorial%2014/exercise1.txt">exercise1.txt</a> and place the file in the following location:

```cpp
“Your iap project folder”/iapProj/Builds/MacOSX/build/Debug/
```

*Please note you will need to run your project first to create the folder as the folder is created as part of xcode's compilation process.*

To complete this exercise, re-arrange the following blocks of code. The program should open a file and read each line. The code is supplied in blocks to make this exercise easier. 

```cpp

1.
if (fileInputStream.is_open()) {
	
}
else {
    std::cout << "error opening file\n";
}

2.

fileInputStream.close();

3.
std::ifstream fileInputStream;
fileInputStream.open("exercise1.txt", std::fstream::in);

4.
std::getline(fileInputStream, line);
std::cout << line << "\n";

5.
std::string line;
while ( ! fileInputStream.eof()) {

}

6.
#include <fstream>

```

Most of the code from the exercise has been explained in the first part of this practical. However, there are 3 new lines of code we have not encountered before.

1.	! fileInputStream.eof()
2.	std::getline(fileInputStream, line);
3.  #include <fstream>
The first line of code is called within a while loop, and is simply asking the file stream if the end of the file (eof) has been reached. It will return **false** if there is still data in the file and **true** if the end has been reached. We use the ( ! ) operator to invert the result (instead of saying (is equal to false).

The second line of code is called for each iteration of the while loop and attempts to read a complete line from the file. The two supplied arguments are the file stream you wish to read from and a string variable where the contents of the line can be stored.

The third line of code is used so that code from the fstream library can be used. This library contains lots of functions for dealing with file input and output.

You may we wondering why "line" can be passed in and then subsequently updated. That is because it is being passed by reference rather than by copy. **Please refer to the lecture slides for more information on this.**


## Extracting values from Strings

All text stored in a plain text file is represent as ASCII characters, so the number 60 stored in a text file will be represented by two ASCII characters ‘6’ and ‘0’, however we often want to work with these characters as if they were actually a single integer data type. The standard C++ library provides a number of inbuilt functions for converting the contents of a string into other C++ data types (e.g. float and int). Two functions for doing this are shown below.

```cpp
  int intValue = std::stoi(str); 
  //will attempt to covert the std::string variable 'str' to int
```

```cpp
  float floatValue = std::stof(str);
  //will attempt to covert the std::string variable 'str' to float
```

Before doing this you should check the size of the str.

```cpp
if (str.size() > 0) {
		//Do coversion
}
```

If you attempt to covert a string that does not contain a valid value, then an error will be thrown.

## Exercise 2: Synthesize file contents

Adapt and modify your solution to the previous exercise so that it reads in the numbers supplied in the file, converts these to a frequency and then synthesizes the value using Aserve. 

## Writing to a file

Writing to a file is similar to reading from one. But instead we use the **ofstream** data type. Note that we must also change the **option** argument on the open() call as well.

```cpp
  std::ofstream fileOutputStream;
  fileOutputStream.open("file.txt", std::ofstream::out);
```

Once the file is open, we can simply write data to the file using the same method we use to write data to the std::out stream. 

```cpp
  fileOutputStream << 10;  //int
  fileOutputStream << "I am writing a string";
  fileOutputStream << 0.00001; //float
```

as before we can combine multiple statements with multiple << operators.

```cpp
  fileOutputStream << "Note: " << 60 << "\n";
```

## Exercise 3: Writing to our file

Continuing on from the previous exercise, adapt your solution so that you first write the contents of the **"exercise1.txt"** file before trying to read it. Some suggested steps to achieve this are as follows. *Note your solution to exercise 2 should go after the code your write specifically for this exercise.*
	
1.	Open file for writing
2.	Write a suitable number of note numbers to this file
3.	Close file
4.	Solution to exercise 2.


*Note that all code should be written inside the run() function. Specify the note value manually for this exercise.*

## Exercise 4: Full sequencer

For this exercise we will adapt our solution from the vector practical, exercise 3. **You will need to complete that exercise first if you have not done so already.**

For this exercise we will add a feature whereby if the user pushes the record button each of the values in the noteList are saved to a text file on a new line. If the user pushes the play button the current noteList is cleared and each note number in the file is loaded into the noteList vector. 

To test this program, you should play a sequence, hit record and close the program. Re-run the program and press "play", **the sequence you recorded previously should play.**

## String manipulation

Strings just like int’s and float’s can be added together, for example, we can do the following operation to add (or concatenate strings) together.

```cpp
  std::string firstName = "Dennis";
  std::string lastName = "Ritchie";
    
  std::string fullName = firstName + ", " + lastName;
```

Therefore, the contents of the fullName would now be:

```cpp
  Dennis, Ritchie
```

However, it is slightly more difficult to split the fullName string back into its parts. The ability to split strings of characters into smaller parts is however useful and necessary for many applications. We can use the **substr()** member function to return a sub-string from our original string. The substr takes 2 arguments, corresponding to the **index** of the letter you wish to start from and the **len** of the substring you wish to go up to (but not including). Doing the following would result in the string "Den" being returned.

```cpp
  std::string subStr = fullName.substr( 0, 3); //returns "den"
```

Computing the following code would output "nis,", as the substring would start at index 3 ('n') and take the next 3 chars ("is,").

```cpp
  std::string subStr = fullName.subStr(3, 4); //returns "nis,"
```

If just 1 argument is supplied, then all the characters from the supplied index up to the end of the string will be returned. In the below example subStr will be equal to **", Ritchie"**.

```cpp
  std::string subStr = fullName.substr(6);
```

However we will not often not know the exact position that we wish to split a string, however we can search for a specific sequence of characters using the **find()** string member function.

```cpp
  std::size_t pos = fullName.find(",");
```


The function will return the index of the start of the sequence supplied as an argument to the find function. In this case it will return 6. There are a couple of things to note here.


std::size_t is a special data type used for storing sizes, and should be used in this instance instead of just **int.**

2.	The find() function can be used to see if a string contains a substring.
3.	If the substring supplied to the find function is not found then pos will hold the value std::string::npos, and can be checked as follows:

```cpp
  if (pos == std::string::npos) {
    //not found
  }
```

We could now extract our first and last names from fullName using the following code.

```cpp
  std::size_t pos = fullName.find(",");
    
  std::string fName = fullName.substr(0, pos);
  std::string lName = fullName.substr(pos+1);
```

## Writing a string splitting function

To make the challenge exercise easier we will develop a function called **splitString.**

Split string will take 4 arguments and return a single **bool.** The 4 input arguments are as follows: 


- **Input:** the input string passed by copy
- **Token:** the split point of the string, passed by copy
- **Left:** the left side of the split passed by reference
- **Right:** the right side of the split passed by reference
The function should do the following:


1.	Search for the token in the input string, using find().
2.	If the value returned from find is equal to **npos** then set left and right to be equal to "" (blank string) and return false.
3.	else
    - Set left to a substring of input with range 0 up to the position
    - Set right to be a substring of input with range position + the size of the token.
4.	Return true;


To test this code, download the test code from <a href="https://github.com/Sjhunt93/IAP-2018-2019/blob/master/Code%20Exercises/Tutorial%2014/string%20split%20unit%20test.txt">here</a>. Add this code to your run() function. Read the comments carefully and check that you getting the correct values printed out.

## Challenge Exercise: Aserve file playback system

For this exercise we will be synthesizing the contents of a file produce by the MIDI to Aserve application. Firstly, download or obtain a MIDI file of a song of your choice. Drag and drop this into the MIDIToAserve.app application to produce a text file. The text file will be saved to your documents. 

To read and process each line you should follow these steps:

1.	Read the line
2.	Check to see if it is an oscillator, sleep, or sample trigger command:
3.	If it is an oscillator command
    - Extract the 4 fields
    - Update oscillator
4.	If it is a sleep command
    - Extract sleep value	
    - Sleep for specified value
5.	If it is a trigger sample
    - Extract sample to trigger
    - Trigger sample 

*You should make use of your splitString function.*






