# C++ Quick Reference

Use this document to see short examples of the various C++ topics we have coverd. This guide is intended as a *reference*, and does not replace the need to complete each tutorial.

Topics Covered: 



1. [Variables and constants](#variables)
2. [Text Output](#tin)
3. [Text Input](#tout)
4. [Operators](#ops)
5. [Logical Comparison](#logic)
6. [If statments](#if)
7. [Switch case](#switch)
8. [Loops](#loop)
9. [Functions](#func)
10. [&& and ||](#aor)
11. [Class](#class)
12. [Array](#array)
13. [Vector](#vector)
14. [Files](#file)
15. [String manipulation](#strmanip)

*use Cmd/Ctr + f to find a topic :D*

# Variables

### Declaring and setting variables  <a name="variables"></a>

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

<hr>

# Text Input <a name="tin"></a>

### Setting a variable
```cpp
  int age;
  std::cin >> age;
    
  std::string name;
  std::cin >> name;
```

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
            std::cout << "Friday \n";
            break;
        default:
            // error handling for values that don't match
            break;
    }
```

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
        return num; //return num
    }
```

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
 

  
