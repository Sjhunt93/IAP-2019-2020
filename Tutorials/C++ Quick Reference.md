# C++ Quick Reference

Use this document to see short examples of the various C++ topics we have coverd. This guide is intended as a *reference*, and does not replace the need to complete each tutorial.

Topics Covered: 


1. [Comments](#comments)
2. [Variables and constants](#variables)
3. [Text Output](#tin)
4. [Text Input](#tout)
5. [Operators](#ops)
6. [Logical Comparison](#logic)
7. [If statments](#if)
8. [Switch case](#switch)
9. [Loops](#loop)
10. [Functions](#func)
11. [&& and ||](#aor)
12. [Class](#class)
13. [Array](#array)
14. [Vector](#vector)
15. [Files](#file)
16. [String Manipulation](#strmanip)
17. [Bit Wise Manipulation](#bitwise)
18. [Tenary Operator](#ternary)
19. [2D data structures](#twod)
20. [Sorting, reversing, shuffling](#sort)
21. [enums](#enum)
22. [defines](#define)
23. [pointers](#pointers)

*use Cmd/Ctr + f to find a topic :D*


# Comments <a name="comments"></a>
### Single line
```cpp
// this is a single line comment 
// comments are ingnored by the compiler!
// write something usefull about your program using them
int age; // variable for storing age

```

### Multi-line comment

```cpp
/*
This is a multi-line comment

std::cout << "this line of code will never be executed \n"

*/

aserveSleep(1000 /* comment inside some code */);
```
### Video
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/eMmviPhu0Iw/0.jpg)](http://www.youtube.com/watch?v=eMmviPhu0Iw)


# Variables <a name="variables"></a>

### Declaring and setting variables 

```cpp
    int age = 25;
    std::string name = "Sam";
    float height = 1.7;
```

### Declaring shared variables

```cpp
class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES
    int lastNote;
```
### Declaring constant variables

```cpp
    const int readOnlyNumber = 10;
    const std::string readOnlyString = "Read Only";
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/UNdOMshCIlk/0.jpg)](http://www.youtube.com/watch?v=UNdOMshCIlk)

<hr>

# Text Output <a name="tout"></a>

### Printing basic text

```cpp
  std::cout << "Some basic text with a new line \n";
```

### Printing variables

```cpp    
  std::cout << "The value of a variable " << number << "\n";
```


### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/oAFGNsZ6MPc/0.jpg)](http://www.youtube.com/watch?v=oAFGNsZ6MPc)

<hr>

# Text Input <a name="tin"></a>

### Setting a variable
```cpp
  int age;
  std::cin >> age;
    
  std::string name;
  std::cin >> name;
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/c0Wo8mMCpDQ/0.jpg)](http://www.youtube.com/watch?v=c0Wo8mMCpDQ)

<hr>

# Operators <a name="ops"></a>

### Basic math

```cpp
  int number = 5 + 6;
  int number = 6 - 5;
  int number = 6 / 2;
  int number = 6 * 5;
  // Division with remainder
  int number = 6 % 2; 
  ```
  
### With variables
```cpp
  int a = 5;
  int b = 10;
  int c = ((a + b) * a) / b;
```
### Incrementing & decrementing

```cpp
  number = number + 10;
  number = number - 5;
  
  //shorthand
  number += 3;  
  number -= 11;
```
### Incrementing & decrementing (single values only)

```cpp
  number++; //same as number += 1
  number--; //same as number -= 1
```
### Powers

```cpp
    float number = pow(2, 5); // 2 to the power of 5
    
    float number = pow(16, 0.5); // calculate square root of 16, i.e. raise to the power of 0.5
```


### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/yPNMVlxy1B0/0.jpg)](http://www.youtube.com/watch?v=yPNMVlxy1B0)



<hr>

# Logical Comparisons  <a name="logic"></a>

```cpp
    bool lessThan =         5 < 2;
    bool lessThanEqual =    5 <= 5;
    bool greaterThan =      5 > 2;
    bool greaterThanEqual = 2 >= 2;
    bool isEqual =          5 == 5;
    bool isNotEqual =       5 != 4;
```

<hr>

# Conditional statements <a name="if"></a>

### if
```cpp
    int number = 5;
    
    if (number < 10) {
    // compute this code only if number is less than 10
    }
```

### if-else

```cpp
    if (number == 5) {
        // compute this code only if number equals 5
    }
    else {
        //compute this code if number is any other value
    }
```

### if-else-if
```cpp
    if (number == 5) {
        // compute this code only if number equals 5
    }
    else if (number == 10) {
        // compute this code only if number equals 10
    }
    else {
        //compute this code if number is any other value
    }
```


### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/dvdHsb7Kndk/0.jpg)](http://www.youtube.com/watch?v=dvdHsb7Kndk)


<hr>




# Switch <a name="switch"></a>

```cpp
    int day;
    switch (day) {
        case 0: // same as saying if (day == 0) 
            std::cout << "Monday \n";
            break;
        case 1: // same as saying else if (day == 1) 
            std::cout << "Tuesday \n";
            break;
        case 2:
            std::cout << "Wednesday \n";
            break;
        case 3:
            std::cout << "Thursday \n";
            break;
        case 4:
            std::cout << "Friday \n";
            break;
        case 5: // fall through case
        case 6: // same as say if (day == 5 ||| day == 6)
            std::cout << "Weekend \n";
            break;
        default:
            // error handling for values that don't match
            break;
    }
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/LV7rgMeJ0N8/0.jpg)](http://www.youtube.com/watch?v=LV7rgMeJ0N8)


<hr>

# Loops <a name="loop"></a>

### While true

```cpp
  while (true) {
    //will run forever - be carefull!
  }
```

### While loop with condition

```cpp
  int counter = 0;
  while (counter < 5) {
    //will execute 5 times
    counter++;
  }
```

### Do-while loop

```cpp
  int counter = 0;
  do {
    //will execute 5 times
    counter++;
  }
  while (counter < 5);
```

### For loop
```cpp
  for (int counter = 0; counter < 5; counter++) {
    //will execute 5 times
  }
```
### For loop reverse
```cpp
  for (int counter = 4; counter >= 0; counter--) {
    //will execute 5 times
  }
```
### Range based for loop

```cpp
    std::vector<int> values = {0, 1, 3, 5};
    for (int i : values) {
        std::cout << i << ", ";
    }
```

### Range based for loop (write access)

```cpp
    std::vector<int> values = {0, 1, 3, 5};
    for (int & i : values) {
        i *= 2;
        std::cout << i << ", ";
    }
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/QgtlLT3L-TQ/0.jpg)](http://www.youtube.com/watch?v=QgtlLT3L-TQ)


<hr>

# Functions <a name="func"></a>

### with no arguments

```cpp
    void error (); //function declaration
```

```cpp
    void IAP::error () //function definition
    {
        std::cout << "Error!;
    }
```

### with a single argument

```cpp
    void errorCode (int code); //function declaration
```

```cpp
    void IAP::errorCode (int code) //function definition
    {
        std::cout << "Error code received" << code << "!";
    }
```

### with a single argument and single return type

```cpp
    int squareNumber (int num); //function declaration
```

```cpp
    int IAP::squareNumber (int num) //function definition
    {
        int sum = num * num;
        return sum; //return sum
    }
```

### Using references to enable multiple return values

```cpp
    void IAP::swap (int & a, int & b)
    { 
        //will swap the contents of a and b
        //a and b are passed by reference so the original values passed in can be modified
        int c = a;
        a = b;
        b = c;
    }    
    
    ... some other part of our program
    
    int valueA = 10;
    int valueB = 5;
    swap(valueA, valueB);
    
    // contents of valueA and valueB have been swapped
```


### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/Cbj72bZrxaE/0.jpg)](http://www.youtube.com/watch?v=Cbj72bZrxaE)

<hr>

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/-04HOoFDZjA/0.jpg)](http://www.youtube.com/watch?v=-04HOoFDZjA)

<hr>






# && and || <a name="aor"></a>

### && (and)
```cpp
    int number = 5;
    if (number >= 0 && number <= 10) {
        // code will only execute if both conditions are true
    }
```

### || (or)

```cpp
    int number = 7;
    if (number == 7 || number == 13) {
        // code will execute if either conditions are true
    }
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/CdXYE-4pzQA/0.jpg)](http://www.youtube.com/watch?v=CdXYE-4pzQA)

<hr>



 

# Class <a name="class"></a>

### Class decleration

```cpp
class Animal {
    int numOfLegs;
    std::string type;
};
```
### Class instance

```cpp
    Animal raccoon;
```

### Setting member variables

```cpp
    raccoon.type = "mammal";
    raccoon.numOfLegs = "4";
```

### Member functions


```cpp
class Animal {
    int numOfLegs;
    std::string type;
    
    bool isDangerous ()
    {
        if (numOfLegs > 4) {
            return true;
        }
        else {
            return false;
        }
    }
};
```


### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/KAf2tA7pXzY/0.jpg)](http://www.youtube.com/watch?v=KAf2tA7pXzY)

<hr>


# Array <a name="array"></a>

### Declaration
```cpp
    std::array<int, 5> myArray; // array with 5 integer values
```

### Setting values

```cpp
    std::array<int, 5> myArray; // array with 5 integer values

    myArray[0] = 10; //setting first element to be 10
    ...
    myArray[4] = 56; //setting last element to be 56

    myArray[5] = 65; //ERROR out of bounds

    std::cout << myArray[1]; // print second element
```
### Iteration
```cpp

    std::array<int, 5> myArray; // array with 5 integer values

    //after setting some values

    for (int i = 0; i < myArray.size(); i++) {
        std::cout << myArray[i] << "\n"; //print each element of myArray in order
    }
```

### Quick Initialisation

```cpp
    std::array<int, 3> = {0,1,2}; //need as many values in braces as there are elements
```

### C style array (avoid if possible!)

```cpp
    int simpleArray[10]; //use std::array instead if possible
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/ofdW_sFv3mk/0.jpg)](http://www.youtube.com/watch?v=ofdW_sFv3mk)

<hr>

# Vector <a name="vector"></a>

### Declaration
```cpp
    std::vector<int> myVector; // declare vector of type int
```

### Resizing
```cpp
    myVector.resize(10); // vector has 10 elements
```

### Adding values
```cpp
    myVector.push_back(10); // will increase size by 1 then set last element to be 10
```

### Video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/2zB0Mg0CtMA/0.jpg)](http://www.youtube.com/watch?v=2zB0Mg0CtMA)

<hr>


# File <a name="file"></a>

### Opening a file

```cpp
    // for reading
    std::ifstream fileInputStream;
    fileInputStream.open("file.txt", std::fstream::in);
    
    // for writing
    std::ofstream stream;
    stream.open("file.txt", std::ofstream::out);
```

### Checking for errors

```cpp
    if (stream.is_open()) { 
        // file opened ok :)
    }
    else {
        //error :(
    }
```

### Closing a file

```cpp
    stream.close();
```

### Reading a single line from a file

```cpp
    std::string line;
    std::getline(stream, line);
```

### reading contents of a file line-by-line

```cpp
    std::string line;
    while (! stream.eof()) {
        std::getline(stream, line);
    }
```

### writing to a file
```cpp
    stream << "Hello file!\n";
    stream << 10;
    stream << 10.12565;
```


# String manipulation <a name="strmanip"></a>

### Appending two strings
```cpp
std::string firstName = "dennis ";
std::string lastName = "ritchie";
std::string fullName = firstName + lastName; 
```

### Substring

```cpp
    // Start from charecter 0 up to but not including 3
    std::string subStr = fullName.substr(0, 3);
    
    // start from charecter 6 up to the end of the string
    std::string subStr = fullName.substr(6);
```

### Finding Substrings

```cpp
    // find the position of ','
    std::size_t pos = fullName.find(",");
    
    if (pos == std::string::npos) {
        //not found
    }
    else {
        std::cout << "Substring starts at charecter:" << pos << "\n";
    }
```

### String to int

```cpp
    if (str.size() > 0) {
        int intValue = std::stoi(str); 
    }
```
### String to float

```cpp
    if (str.size() > 0) {
        float floatValue = std::stof(str);
    }
```

# Bitwise Manipulation <a name="bitwise"></a>

### Bit Shifting

```cpp
    int a = 1; //0000 0001
    //shift by 1 place to the right
    a = a << 1; // a is now 0000 0010
    
    // shift by 1 place to the left
    a = a >> 1; // a is now 0000 0001
```

### Bitwise OR

```cpp

    int x = 15; // 0000 1111
    int y = 240; // 1111 0000
    
    // Bitwise Or
    int z = x | y; // z is 1111 1111
```
### Bitwise AND

```cpp
    int x = 31; // 0001 1111
    int y = 248; // 1111 1000
    // Bit wise And
    int z = x & y; // z is 0001 1000
```

### Bitwise NOT

```cpp
    int x = 15; // 0000 1111
    
    // Bitwise Not
    int z = ~x; // z is 1111 0000
```

### Bitwise XOR

```cpp

    int x = 31; // 0001 1111
    int y = 248; // 1111 1000
    
    // Bitwise XOR
    int z = x ^ y; // z is 1110 0111
 
```

### Checking a bit

```cpp
    if (a & (1 << 4)) {
        //check if bit 4 is 1
    }
```
### Set a bit

```cpp
    a = a | (1 << 2); //set bit 2
```

### Clear a bit
```cpp
    a = a & (~ (1 << 5)); //clear bit 5	
```

### Toggle a bit
```cpp
    a ^= 1 << 4; //Toggle bit 4
```
  
# Tenary Operator <a name="ternary"></a>

### With variables

```cpp

errorString = (errorCode == 0) ? "No Error" : "Error";

```

### With functions

```cpp
   (filterType == 1) ? aserveHPF(cutoff) : aserveLPF(cutoff);
```

# 2D data structures <a name="twod"></a>

### 2D arrays

```cpp
    std::array< std::array<int, 10>, 10> tenByTen;
    
    tenByTen[0][0] = 10;
```

### General form

```cpp
    std::array< std::array<int, /* inner size*/>, /*outer size*/> tenByTen;

    tenByTen[/*outer index*/][/*inner index*/]
```

# Sorting, reversing and shuffling <a name="sort"></a>

### std::sort

```cpp
  std::array<int, 10> array;
    
  //... add elements to array
    
  std::sort(array.begin(), array.end());
```

### std::reverse

```cpp
  std::reverse(array.begin(), array.end());
```

### std::shuffle

```cpp
    std::random_shuffle(array.begin(), array.end());
```

# enums <a name="enum"></a>

### sequential example

```cpp
    enum eWaveTypes {
        eSine = 0,
        eSquare, //will have the value 1
        eSaw,
        eReverseSaw,
        eTri,
        eNoise //will have the value 5
    };
    
    ...
    aserveOscillator(0, 440.0, 1.0, eSine);
```

### non-sequential example

```cpp
    enum eControls {
        eKnob1 = 21,
        eSlider1 = 41,
        ePlayBtn = 115,
    };
```

### enum as a type

```cpp
    eWaveTypes waveType; //can only hold values defined in the enum
```
# Defines <a name="define"></a>

### constants

```cpp
    #define COLUMNS 16
    
    ...
    
    int howManyCols = COLUMNS; // same as saying = 16.
```

### with functions

```cpp
    #define SLEEP_500 aserveSleep(500);
    
    ...
    
    SLEEP_500 //will call aserveSleep(500); 
```



