# C++ Quick Reference

Use this document to see short examples of the various C++ topics we have coverd. This guide is intended as a *reference*, and does not replace the need to complete each tutorial.


# Variables

### declaring and setting variables

```cpp
    int age = 25;
    std::string name = "Sam";
    float height = 1.7;
```

### declaring shared variables

```cpp
class IAP : public AserveComs  {
public:
    
    //---------------------------------------------------------------------------------
    // SHARED VARIABLES
    int lastNote;
```

<hr>

# Printing

### printing basic text

```cpp
  std::cout << "Some basic text with a new line \n";
```

### printing variables

```cpp    
  std::cout << "The value of a variable " << number << "\n";
```

<hr>

# Text Input

### setting a variable
```cpp
  int age;
  std::cin >> age;
    
  std::string name;
  std::cin >> name;
```

<hr>

# Operators

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

# Logical Operators

```cpp
    bool lessThan =         5 < 2;
    bool lessThanEqual =    5 <= 5;
    bool greaterThan =      5 > 2;
    bool greaterThanEqual = 2 >= 2;
    bool isEqual =          5 == 5;
    bool isNotEqual =       5 != 4;
```

<hr>

# Conditional statements

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

# Switch

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

# Loops

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



  
