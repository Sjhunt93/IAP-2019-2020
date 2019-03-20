# Tutorial 9 – Classes

In this practical you will learn how to make use of classes. On successful completion of this practical you will have an understanding of: 

1. The basics of defining a class
2. Class member variables
3. Class methods (functions)


## Class

In the real world we are used to seeing, discussing, and using objects. For example, your mobile phone is one of many mobile phones in the world. However, it shares a number of characteristics and features with all other phones. We can think of a generic mobile phone as the **class or data type** and your specific phone as the **instance or variable name.** 

Using object oriented terminology, we can say that a very primitive mobile phone **class** has some **data**, for example contacts and some **methods** for acting on those contact, i.e. call a contact, add contact, delete contact.

## Person

Person

To illustrate further let’s think about a generic person. A generic person has a number of features that describe that person (you can think of these as variables). To use this in a C++ context we must also specify the data type. A table of features has been partially pre-populated below, **please add 3 more features.**

| **Feature** |	**C++ data type** |
| --- | --- |
| Height | float |
| Age |	int |
| Name | std::string |


## Exercise 1: Person Class

To help conceptualize the topics we have discussed so far you will now create your own **person** class. Firstly, navigate to your IAP.h file and add the following:

```cpp
//---------------------------------------------------------------------------------
// USER CREATED CLASS
-> new class starts here

class Person {
public:
    
};

-> new class ends here
class IAP : public AserveComs  {
public:

```

## Syntax

The **class** keyword in C++ is used when we want to define a class, following from this keyword is the name (**Person**) of the class. By convention class names should always start with a capital letter.

The **Public** keyword is used to define parts of our class that are visible to other parts of the program. For now, we will just leave this in place, and this will be discussed again at the end of this practical. For more information on the public keyword and its alternatives see the lecture slides.

A **brace** should always follow the class name, and the class definition ends with a closing **brace and semicolon**.

## Member variables

Now that we have our class definition we want to add some **member variables** to it. Member variables are like normal variables except that they define some **property** about our **class**. For this exercise choose at least 3 of the features from the previous page and add them as member variables. A single example is given bellow.


```cpp
  class Person {
  public:
      std::string name; //member variable
  };
```

## Instance

To create an instance of our person add the following line of code to our shared variables label in our IAP class. *note that shared variables are actually member variables of our IAP class.

```cpp
  //---------------------------------------------------------------------------------
  // SHARED VARIABLES (IAP member variables) 14
  Person 
```

Finally lets set some of the **student’s** member variables.





