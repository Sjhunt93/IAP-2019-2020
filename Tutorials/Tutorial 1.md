# IAP Practical 1 – Familiarisation 

This practical is designed to help familiarise you with the development tools that will be used for Introductory Audio Programming. You will be developing software in the programming language C++ using the Apple Integrated Development Environment (IDE) called Xcode. By the end of this session you should be familiar with: 

1.	The Apple workstations in the faculty labs. 
2.	The Xcode development environment.
3.	The Aserve application.
4.	The structure of a basic C++ program. 

## Getting started

Follow the getting started notes provided with this practical.

## What does this code do?

You will write code in one of two places.

-	The header (IAP.h) files 
-	and a c++ (IAP.cpp) file. 

For now, however we will only use the IAP.cpp file, single click on this file to open it now.

IAP.cpp is where you will be writing most of your C++ programs for this module. Files can be identified as C++ programs by either their, .cpp or .h extension. C++ program files are written in plain text so they may be opened using any ordinary text editor (including word, textedit, notepad, and so forth.). However, Xcode takes care of many other operations needed for creating and running a program.

The code for this file will be broken down and explained bellow.

## Comments

The first line of the program is a comment. You can write anything you like between the /* and */ and it will be ignored when the program is built. Comments may be written anywhere in your program and should be used judiciously to explain what’s going on and to make the code easier to understand and read. You will also see comments written by //. 

-	Use /* */ for writing comments across multiple lines
-	Use // for writing single line comments.


## Include files

```cpp
#include "IAP.h"
#include <iostream>
```

These two lines tell the compiler to include the information contained in the files IAP.h and iostream. 

-	Quotation marks (“ “) are used to include files that we write ourselves.
-	Triangle brackets (< >) are used to include C++ library files.

In reality C++ program include a lot of code behind the scenes. We keep this separated into different files to avoid having one massive document!

## Run loop

```cpp
void IAP::run () 
{

}
```

The run function is where our code gets executed. The opening brace of the run() function is where program execution begins and the closing brace } is where execution ends and the program stops.

**Any code that you add to this program should go after opening brace { and before the  closing brace. }**

## Exercise 1: Hello World 

Modify the run function so it matches the following:

```cpp
void IAP::run ()
{
    std::cout << "Hello World! \n";
}
```

Rebuild and run your program by pressing the ‘Run’ icon again (or cmd + r ). Should you encounter any errors, read the error message for clues as to what the problem might be and check that you have written the line exactly as shown.

When ever we want to print text we use the std::cout command

```cpp
std::cout 
```

The two triangles arranged like this are used to direct data, i.e. we are directing the text we want to print to the std::cout command.

```cpp
<<
```

Finally, we put the text we want to display inside a pair of quotation marks. 

```cpp
"Hello World! \n"
```
**Oh and one more thing… We must end our line of code with a semi-colon. Many programming mistakes are caused by forgetting to put it!**

```cpp
;
```

Other important things to note:

1.	The std::cout command can be used because the header file <iostream> was included, which is where std::cout is declared.
2.	The C++ compiler is case sensitive. That is, std::cout is valid and std::CoUt is not.
3.	C++ statements are terminated with a semi-colon (;).
4.	std::cout will be used every week.
5.	Code that is enclosed by braces { } should be indented one tab space.

Now modify your program so that it greets you by your first name. You may also wish to experiment with some other text to give your program a more colourful character. 

std::cout displays the text enclosed by quotation marks on the console; however, there are exceptions. For example, \n does not appear. Try moving \n between the words Hello and World, to establish what it does. 

\n is what’s called an escape sequence and lets us print characters that cannot be represented easily in code. \t is another useful escape sequence. Insert it in a few places to work out what it does. 

## Moving on

When you complete each practical exercise you must save copies of your solutions to help with future work and assignments. Save your solutions as follows: 

1.	In finder, navigate to your /iap/ folder and open the application codeBook.
2.	On the left hand side of the application you should headers for each week.
3.	Within the header you should see labels for each exercise.
4.	Copy and paste the contents of main.cpp and paste it into Exercise 1: Hello World. 
5.	You can now modify main.cpp without the risk of losing any work. 
6.	Ensure that you complete and then save each exercise each week in codeBook.
7.	Note that code book stores these files in a separate folder, you should not attempt to manually edit these.

## Aserve 2.0

From your Documents/iap/ folder, find and launch Aserve. You should see the following interface: 

