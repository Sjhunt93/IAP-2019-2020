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
### incrementing & decrementing (single values only)

```cpp
  number++; //same as number += 1
  number--; //same as number -= 1
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

  

  
