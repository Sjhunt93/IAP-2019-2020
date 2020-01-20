# Tutorial 9 – Classes

In this practical you will learn how to make use of classes. On successful completion of this practical you will have an understanding of: 

1. The basics of defining a class
2. Class member variables
3. Class methods (functions)


## Class

In the real world we are used to seeing, discussing, and using objects. For example, your mobile phone is one of many mobile phones in the world. However, it shares a number of characteristics and features with all other phones, for example making calls. We can think of a generic mobile phone as the **class or data type** and your specific phone as the **instance or variable name.** 

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
// new class starts here

class Person {
public:
    
};

// new class ends here
class IAP : public AserveComs  {
public:

```

## Syntax

The **class** keyword in C++ is used when we want to define a class, following from this keyword is the name (**Person**) of the class. By convention class names should always start with a capital letter.

The **Public** keyword is used to define parts of our class that are visible to other parts of the program. For now, we will just leave this in place, and this will be discussed again at the end of this practical. For more information on the public keyword and its alternatives see the lecture slides.

A **brace** should always follow the class name, and the class definition ends with a closing **brace and semicolon**.

## Member variables

Now that we have our class definition we want to add some **member variables** to it. Member variables are like normal variables except that they define some **property** about our **class**. A single example is given bellow. **For this exercise choose at least 3 of the features from the previous page and add them as member variables.**


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
  // SHARED VARIABLES (IAP member variables)
  Person student; // we have added a person type
```

Finally lets set some of the **student’s** member variables.

## The dot syntax 

To set or access a class’s member variables we simply use the dot operator. For example, in the below example we are setting the member variable called **name** inside the **instance** student to be “sam”.

```cpp
    student.name = "Sam";
    std::cout << "Person’s name is: " << student.name;
```

To complete this exercise set all of the member variables in your student instance inside the IAP::run() function. Make sure you print all of the values to ensure this has worked correctly.

## Exercise 2: Adding a second person.

Repeating the steps from the previous exercise add another **instance** of the person class, this time called **lecturer.** *You do not need to add another class definition or alter our existing Person class definition.*

1.	Remember to set all of **lecturer’s** member variables
2.	Print out all of **lecturer’s** member variables.

## Exercise 3: Class methods

You should have noticed from the previous exercise that we have some unnecessary code duplication going on (yours should look much larger than what is shown below). We currently have two blocks of code that are printing the contents of our person class. To refactor this program, we can add a **method** to our **person class** called **print.**

```cpp

void IAP::run ()
{
    student.name = "Sam";
    lecturer.name = "Phil";
    //set all other member variables
    
    std::cout << "Person's name is: " << student.name;
    std::cout << "Person's name is: " << lecturer.name;
    //print all other member variables
    
}
```

## Class methods

Class methods are functions that live inside a class definition and normally act upon the state of the class in someway. A class method has access to all of a classes member variables, without needing to use the **dot operator.** For example, you might have a method called calculateBMI which uses a person’s age, height and weight (member variables). 

To add a class method simply define a function within the class’s definition, underneath the public label, and before the ending brace. The function should be called **print** and neither takes arguments or returns one.

## What about the function declaration?

You may be wondering where we put the function declaration for our person class, for the sake of simplicity we can combine them together. Note that we do not need to supply the Person:: namespace in front of *someFunction* when combining the **definition** and **declaration**.

```cpp
class Person {
public:
    std::string name;
    
    // class method definition & declaration
    void print ()
    {

    }
};
```

You should add the relevant printing code from the previous exercise so that your person’s **print** method prints all of the person’s member variables.

To complete this exercise remove the print code from your IAP::run() function and replace it with a call to the person’s **print** method. *Note that both student and lecturer should call print.*

```cpp
    student.print();
    lecturer.print();
```

## Exercise 4. Making a Synth class

The material for starting this practical is supplied <a href="https://github.com/Sjhunt93/IAP-2018-2019/tree/master/Code%20Exercises/Tutorial%209/Exercise%204">here</a>, copy and paste the contents of both IAP.h and IAP.cpp into your project.

Our IAPSynth class looks slightly different to our previous class definition, as this class **inherits** from AserveComs. Inheritance is not something that we will cover on this course. 

```cpp
    // Normal bit  |-- ignore this --|
    class IAPSynth : public AserveComs {
```

We will now add some functionality to our IAPSynth class.

Add the following methods to our IAPSynth class.

1.	A **method** called playNote that takes two arguments, note and velocity but does not return anything.
2.	A **method** called stopNote that takes a single argument called note but does not return anything.
3.	A **method** called setWavetype that takes a single argument called waveType that does not return anything.
4.	A **method** called mtof that takes a single argument called note and returns a frequency.

Add the following member variables to our IAPSynth class.

1.	A member variable called lastNote
2.	A member variable called currentWavetype

A brief description of what each function does is given below, you should have completed code previously that you can use for the majority of this exercise.

### playNote

Should calculate the frequency and amplitude from the supplied input arguments. It should turn an oscillator on and also store the note number into lastNote member variable.

### stopNote

Stop note should check the supplied note number against the lastNote member variable, and only switch the oscillator off if it matches.

### setWavetype

This function should simply copy the input argument and set the currentWavetype member variable.

Once you have completed the above you should replace the comments inside the callback functions to call our synthesisers’s member functions. You should now have a fully functioning synthesiser class.


## Why use classes at all?

It would perhaps seem like more work to offload our code for turning oscillators on/off into a separate a class than simply doing it inside the callback functions. However, there are several good reasons for doing this. Firstly, all our relevant code for synthesis is now grouped in one place, meaning that our IAP class is less cluttered and more concise. Secondly we can add features to our synthesizer class without affecting our current code. Finally, we can now easily change the mapping between features of our synth (i.e. setting wavetype) and the control input (callbacks from Aserve).



## Public vs Private

Instead of calling setWaveType from the CC callback use the dot operator to set the synth’s member variable currentWaveType directly. Check that your program works correctly as it did before.

As your program works exactly the same without the need for the currentWaveType function you may wonder what the point of having the member function is. Firstly, add the the **private:** label to your IAPSynth class at the end of the declaration before the ending brace. Move the currentWaveType variable deceleration to be underneath the **private:** label. Once you rebuild and compile your program, you will now get an error as you cannot access the class’s **private** member variables. Instead you will now have to use the setWaveType member function again.

To finish our setWaveType function you should an if statement that will only set the currentWaveType variable if the value supplied is in range. Please refer to the lecture slides for more information on public/private.


## Challenge exercise

We can now easily add some more functionality to our synthesiser class. An example is given below, however feel free to create your own also. You may wish to use features development from the previous assignment.


### Volume Control
Create a class method called setVolume that takes the value of a control change message (0 – 127). Inside the function scale this value into the range 0 – 1.0 and set a member variable called **volume**. Before turning on the oscillator multiply **volume by amplitude.**

## Important note

We will be building upon and making use of the IAPSynth in all of the future practical’s this term. Please ensure that you complete this practical and if unsure ask one of the tutors to check your work.









