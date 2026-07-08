# OOP C++ Notes

## 📑 Index

- [What is Function Hiding?](#what-is-function-hiding)
- [OOP over Procedure-Oriented Programming Language](#oop-over-procedure-oriented-programming-language)
  - [OOP vs POP (Core Idea)](#oop-vs-pop-core-idea)
  - [Advantages](#advantages)
- [OOPS](#oops)
  - [What is the need for OOPs?](#what-is-the-need-for-oops)
  - [Class](#class)
  - [Objects](#objects)
- [Access Modifiers](#access-modifiers)
  - [1. `public`](#1-public)
  - [2. `private`](#2-private)
  - [3. `protected`](#3-protected)
- [Constructors in OOP](#constructors-in-oop)
  - [1. Default Constructor](#1-default-constructor)
  - [2. Parameterized Constructor](#2-parameterized-constructor)
  - [Constructor Overloading](#constructor-overloading)
- [Destructor](#destructor)
  - [When is Destructor Called?](#when-is-destructor-called)
- [`this` Pointer](#this-pointer)
- [Static Members](#static-members)
  - [Static Variables](#static-variables)
  - [Static Functions](#static-functions)
- [Scope Resolution Operator `::`](#scope-resolution-operator)
- [Four Pillars of OOP in C++](#four-pillars-of-oop-in-c)
  - [1. Encapsulation](#1-encapsulation)
  - [2. Abstraction](#2-abstraction)
  - [3. Inheritance](#3-inheritance)
  - [4. Polymorphism](#4-polymorphism)
- [Virtual Function](#virtual-function)
- [Virtual Destructor](#virtual-destructor)
- [Pure Virtual Function](#pure-virtual-function)
- [Binding](#binding)
  - [How does the compiler perform runtime resolution?](#how-does-the-compiler-perform-runtime-resolution)
  - [Limitations of Virtual Functions](#limitations-of-virtual-functions)
- [Friend Class and Function](#friend-class-and-function)
  - [Friend Class](#friend-class)
  - [Friend Function](#friend-function)
  - [Advantages vs Disadvantages](#advantages-vs-disadvantages)
- [Copy Assignment Operator](#copy-assignment-operator)
- [Shallow Copy](#shallow-copy)
- [Deep Copy](#deep-copy)
- [Copy Constructor](#copy-constructor)
  - [Default Copy Constructor](#default-copy-constructor)
  - [User Defined Copy Constructor](#user-defined-copy-constructor)
  - [Need of User Defined Copy Constructor](#need-of-user-defined-copy-constructor)
  - [Dangling Pointer](#dangling-pointer)
  - [Copy Elision](#copy-elision)
  - [Copy Constructor vs Assignment Operator](#copy-constructor-vs-assignment-operator)
- [Memory Management](#memory-management)
  - [1. Stack vs Heap](#1-stack-vs-heap)
  - [2. `new` and `delete`](#2-new-and-delete)
  - [3. Memory Leak](#3-memory-leak)
  - [4. Dangling Pointer](#4-dangling-pointer)
- [Rule of 3 / 5](#rule-of-3-5)
  - [Rule of 3 (Classic C++)](#rule-of-3-classic-c)
  - [Rule of 5 (Modern C++)](#rule-of-5-modern-c)
  - [Interview Insight ⭐ (Very Important)](#interview-insight-very-important)
  - [Rule of 0 (Advanced Insight)](#rule-of-0-advanced-insight)
- [Smart Pointers](#smart-pointers)
  - [Types of Smart Pointers](#types-of-smart-pointers)
  - [Problems with Normal Pointers](#problems-with-normal-pointers)
  - [Pointers vs Smart Pointers](#pointers-vs-smart-pointers)
- [Move Semantics](#move-semantics)
  - [1. What is Move Semantics (Idea)](#1-what-is-move-semantics-idea)
  - [2. lvalue vs rvalue (Very Important)](#2-lvalue-vs-rvalue-very-important)
  - [3. rvalue Reference `(&&)`](#3-rvalue-reference)
  - [4. Why Move is Needed](#4-why-move-is-needed)
  - [5. `std::move`](#5-stdmove)
  - [6. Move Constructor](#6-move-constructor)
  - [7. Move Assignment Operator](#7-move-assignment-operator)
  - [8. When Move Happens Automatically](#8-when-move-happens-automatically)
- [Templates (Generic Programming)](#templates-generic-programming)
  - [🔹 What problem do templates solve?](#what-problem-do-templates-solve)
  - [🔹 Template Solution](#template-solution)
  - [🔹 Key Idea](#key-idea)
- [Exception Handling](#exception-handling)
  - [🔹 Why needed?](#why-needed)
  - [🔹 Basic Keywords](#basic-keywords)
  - [Custom Exception (OOP + Exception)](#custom-exception-oop-exception)
- [Method Chaining (via `this`)](#method-chaining-via-this)
- [Extra Notes & Practice Questions](#extra-notes-practice-questions)
  - [When to use `new` and when not to](#when-to-use-new-and-when-not-to)
  - [Abstract Class Practice Question](#abstract-class-practice-question)

---


> if you create objects with `new`, you must delete them (using `delete` or calling destructor) to free memory and run cleanup code. Otherwise you risk memory leaks and unfinished resource handling.

> A memory leak happens when a program allocates memory but never releases it, even after it's no longer needed. **Memory leak = used memory that is never freed**

> an empty destructor = same as no destructor or default destructor. C++ not automatically delete heap memory (`new`) like it does for stack objects. (for heap we use `delete`)

---

### What is Function Hiding?

👉 When a derived class defines a function with the same name as in the base class.  
👉 the base class function gets hidden, even if signatures are different.

---

## OOP over Procedure-Oriented Programming Language

### OOP vs POP (Core Idea)

- **POP** (Procedure-Oriented Programming) → Focuses on functions/procedures **(POP → "How to do?")**
- **OOP** (Object-Oriented Programming) → Focuses on objects (data + behavior together) **(OOP → "Who does it?")**

### Advantages

- By using objects and classes, you can create reusable components, leading to less duplication and more efficient development.
- It provides a clear and logical structure, making the code easier to understand, maintain, and debug.

---

## OOPS

> OOPs, or Object-Oriented Programming is a programming model or paradigm which revolves around the concept of **"OBJECTS"**.

### What is the need for OOPs?

- OOPs helps users to understand the software easily, although they don't know the actual implementation.
- With OOPs, the readability, understandability, and maintainability of the code increase multifold.
- Even very big software can be easily written and managed easily using OOPs.

### Class

> A class is a user-defined blueprint from which objects are created. It represents the set of properties or methods that are common to all objects of one type.

### Objects

> Objects can be considered as real-world instances of entities like class, that contain some characteristics and behaviors specified in the class template.

---

## Access Modifiers

> Access modifiers are special keywords in C++, that control the visibility of class members (data and functions).

### 1. `public`

Members declared as public are accessible from anywhere in the program.

✅ **Use Cases**
- Used to define the interface of a class
- Functions that users should call

### 2. `private`

Members declared as private are accessible only within the same class.

✅ **Use Cases**
- Data hiding (encapsulation)
- Protect sensitive data
- Prevent invalid modifications

### 3. `protected`

Members declared as protected are accessible:
- Within the same class
- In derived (child) classes
- Not accessible outside

> Example: manager can set the salary of employee

✅ **Use Cases**
- Used in inheritance
- Allows child classes to reuse and modify data safely.

---

## Constructors in OOP

> A constructor is a special member function of a class that is:
> - Automatically called when an object is created
> - Used to initialize data members

🔑 **Key properties:**
- Same name as class
- No return type
- Called automatically

### 1. Default Constructor
A constructor that takes no arguments.
```
Ex — Student()
```

### 2. Parameterized Constructor
A constructor that accepts arguments to initialize values.
```
Ex — Student(int a)
```

### Constructor Overloading

Having multiple constructors in the same class with different parameters.

👉 It is an example of **compile-time polymorphism**

---

## Destructor

> A destructor is a special member function of a class that:
> - Has the same name as the class, prefixed with `~`
> - Has no return type and no parameters
> - Is automatically called when an object is destroyed
> - Used to free resources / clean up

### When is Destructor Called?

**1. When object goes out of scope** (Stack Allocation ✅ Recommended)

```cpp
void func() {
    Student s;  // constructor called
}               // destructor called here
```

**2. For dynamically allocated objects** (Recommended for Heap Allocation `new`/`delete`)

```cpp
Student* s = new Student();
delete s;  // destructor called here
```

---

## `this` Pointer

> `this` is a pointer that points to the current object of the class.

```cpp
this->x = x;
```

👉 `this->x` refers to class member  
👉 `x` refers to parameter

---

## Static Members

> Static members are class members (variables or functions) that belong to the class itself, not to individual objects.

→ `"static"` means **shared across all objects** of a class

### Static Variables

A static variable is a class variable that:
- Is shared by all objects
- Has only one copy in memory
- Belongs to the class, not individual objects

### Static Functions

A static function:
- Belongs to the class, not objects
- Can be called without creating object
- Can access only static members

#### 📄 Code Example — `staticMember.cpp`

```cpp
🔍 Key Points:
    Same variable used by all objects
    Access using:
    👉 ClassName::variable

// static variable
#include <iostream>
using namespace std;

class Demo {
public:
    static int count;

    Demo() {
        count++;
    }
};

int Demo::count = 0;   // definition outside class

int main() {
    Demo d1, d2, d3;
    cout << Demo::count;  // Output: 3
}

=====================================================================================================
}
🔍 Key Points
        Cannot use this pointer ❌
        Cannot access non-static members directly ❌
        Called using class name ✔

// static function
#include <iostream>
using namespace std;

class Demo {
public:
    static int count;

    static void show() {
        cout << count;
    }
};

int Demo::count = 10;

int main() {
    Demo::show();   // no object needed
}

========================================================================================================

A static function cannot access a non-static variable directly.
class Demo {
public:
    int x = 10;

    static void show() {
        cout << x;   // ❌ ERROR
    }
};

✅ How to Fix It

class Demo {
public:
    int x = 10;

    ✔️ Option 1: Pass object
    static void show(Demo d) {
        cout << d.x;   // ✔ works
    }
    
    ✔️ Option 2: Use pointer/reference
    static void show(Demo* d) {
        cout << d->x;
    }
};


int main() {
    Demo obj;
    Demo::show(obj);   // pass object
    Demo::show(&obj);   // pass address
}
```

---

## Scope Resolution Operator `::`

> The scope resolution operator `(::)` is used to tell the compiler which scope (class, function, global, namespace) you are referring to.

Think of it as:
> **"Go inside this scope and pick that specific thing."**

---

## Four Pillars of OOP in C++

---

### 1. Encapsulation

> Encapsulation is the process of wrapping up of data member and member functions into a single unit (class) and restricting direct access to some of its components. It acts as a **protective shield** for the data.

#### Implementation of Encapsulation in C++

| Step | What to do | Why |
|------|-----------|-----|
| Declare variables as `private` | Keep the class data members private so that they cannot be accessed directly from outside the class. | This ensures data hiding. |
| Use getters and setters | Provide public functions (getters and setters) to access and modify private variables safely. | These methods can also include validation to ensure only valid data is assigned. |
| Apply proper access specifiers | Use `private` for data members to hide information and `public` for member functions | Provides controlled access to the data. |

#### Advantages of Encapsulation

- Data Hiding
- Improved Maintainability
- Enhanced Security
- Code Reusability
- Better Modularity

#### 📄 Code Example — `encapusaltion.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person{
private:
    string name;
public:
    void setName(string name){
        this->name=name;
    }
    void getName(){
        cout<<name<<endl;
    }
};

int main(){
    Person p;
    p.setName("xyz");
    p.getName();
}
```

---

### 2. Abstraction

> Abstraction in C++ is the process of hiding the implementation details and only showing the essential details or features to the user. It allows to focus on **what** an object does rather than **how** it does it.

Abstraction is mainly achieved using **abstract classes** and **pure virtual functions**. These define a common interface for derived classes while leaving the actual implementation to them.

#### Abstract Class

An abstract class is a class that:
- Cannot be instantiated (no objects can be created)
- Contains at least one pure virtual function

#### 📄 Code Example — `abstraction/abstraction.cpp`

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
This draw() is public, but it has no implementation
It only tells: "Every shape must have a draw function"
It does not reveal how drawing happens

👉 That’s abstraction:

Interface (what) → visible (draw())
Implementation (how) → hidden in derived classes 
*/

// Abstract class
class Shape {
public:
    // Pure virtual function (no implementation)
    virtual void draw() = 0;

    // Concrete function
    void info() {
        cout << "This is a shape" << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

// Another derived class
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->info();
    s1->draw(); /* Here:
                You only know draw() exists
                You don’t know whether it prints, uses graphics, or anything else
                Even though draw() is public:
                   Its implementation is hidden behind the base class pointer 
            */

    s2->info();
    s2->draw();

    delete s1;
    delete s2;

    return 0;
}

=====================================================================================================

#include <iostream>
#include <string>
using namespace std;

// Abstract base class as there is a
// pure virtual method
class Shape{
protected:
    string color;

public:
    Shape(string color) : color(color){}

    // Abstract or Pure virtual method
    virtual double area() = 0;

    // Concrete method
    string getColor(){
        return color;
    }

    virtual ~Shape() {}
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double length, width;

public:
    /* 
        Rectangle(string color, double l, double w) {
            Shape(color);      ❌ temporary object
        }
        This creates a temporary object of type Shape/
        It is NOT connected to your Rectangle object
        It exists only for that line
        Then it is immediately destroyed
     */  
    Rectangle(string color, double length, double width) : Shape(color) { // right way
                                                
        this->length = length;
        this->width = width;
    }
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* s = new Rectangle("Yellow", 2, 4);

    cout<<"Rectangle color is "<<s->getColor()<<" and area is : "<<s->area()<<endl;
    return 0;
}

============================================================================================================

// Abstraction using access modifier

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    double balance;  // hidden data

    // hidden internal logic
    void updateBalance(double amount) {
        balance += amount;
    }

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // exposed interface
    void deposit(double amount) {
        updateBalance(amount);  // user doesn't know how it's done
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            updateBalance(-amount);
        } else {
            cout << "Insufficient balance\n";
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);

    acc.deposit(500);
    acc.withdraw(200);

    cout << "Balance: " << acc.getBalance() << endl;

    return 0;
}
```

#### Full Abstraction — Interfaces

In C++, a class can act as an interface if it contains **only pure virtual functions** and no data members or implemented methods. This enforces that all derived classes must implement every function, achieving full control abstraction.

> 📝 **NOTE** → "A class with only virtual functions can be instantiated, but if it contains at least one pure virtual function, it becomes an abstract class and **cannot** be instantiated."

#### 📄 Code Example — `abstraction/fullAbstraction.cpp`

```cpp
#include <iostream>
using namespace std;

// Pure Abstract Class acting as an Interface
class Printable {
public:
    virtual void print() = 0;  // pure virtual function
    virtual void scan() = 0;   // pure virtual function

    // Virtual destructor is a good practice for base classes
    virtual ~Printable() {}
};

// Derived class must implement all functions
class Document : public Printable {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
    void scan() override {
        cout << "Scanning document..." << endl;
    }
};

// Another derived class implementing the same interface
class Photo : public Printable {
public:
    void print() override {
        cout << "Printing photo..." << endl;
    }
    void scan() override {
        cout << "Scanning photo..." << endl;
    }
};

int main() {
    // Base class pointer pointing to derived objects
    Printable* p1 = new Document();
    Printable* p2 = new Photo();

    // Call interface functions - runtime polymorphism
    p1->print();
    p1->scan();

    p2->print();
    p2->scan();

    // Free memory
    delete p1;
    delete p2;

    return 0;
}
```

#### Abstraction vs Encapsulation

| Concept | Definition |
|---------|-----------|
| **Encapsulation** | The process of wrapping data and methods together and restricting direct access to data using access modifiers. |
| **Abstraction** | The process of hiding implementation details and showing only essential features to the user. |

---

### 3. Inheritance

> Inheritance is a mechanism in C++ where a class (derived) acquires the properties and behaviors of another class (base), forming an **"is-a"** relationship.  
> Enables code reusability by inheriting data members and methods from the base class.

#### Types of Inheritance

| Type | Description |
|------|-------------|
| **Single Inheritance** | A sub-class is derived from only one super class. |
| **Multiple Inheritance** | One class can have more than one superclass and inherit features from all parent classes. |
| **Multilevel Inheritance** | A class is derived from another derived class, forming a chain of inheritance. |
| **Hierarchical Inheritance** | More than one subclass is inherited from a single base class. i.e. more than one derived class is created from a single base class. |
| **Hybrid Inheritance** | When two or more types of inheritance are combined in one program. For example, a class might use multiple inheritance and also be part of a multilevel inheritance chain. |

> 📝 **Note (Multilevel):** "When a derived class object is created, only one object is formed, but it contains base class subobjects. The constructors of base classes are called to initialize those parts, not to create separate objects."

#### 📄 Code Example — `inheritence.cpp`

```cpp
#include <iostream>
using namespace std;

class Animal
{
  public:
    void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

// “In private inheritance, all public and protected members of the base class become private in the derived class, so they cannot be accessed from outside the derived class.”
/* 

class Animal {
public:
    void sound() {
        cout << "Animal sound";
    }
};

class Dog : private Animal {    NOTE => ( but if we define sound here then it will work fine like we have done below )
};                                      ( same holds in case of virtual func case )

int main() {
    Dog d;
    d.sound();   // ❌ ERROR
}

*/
class Dog : public Animal
{
  public:
    void sound()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
  public:
    void sound()
    {
        cout << "Cat meows" << endl;
    }
};

class Cow : public Animal
{
  public:
    void sound()
    {
        cout << "Cow moos" << endl;
    }
};

int main()
{
    Animal a;
    a.sound();
    
    Dog d;
    d.sound();

    Cat c;
    c.sound();

    Cow cow;
    cow.sound();

    return 0;
}

===========================================================================================================
// Single inheritence ----------------------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "This is a Vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "This Vehicle is Car" << endl;
    }
};

int main() {
   
    Car obj;
    return 0;
}
Output
This is a Vehicle
This Vehicle is Car

==============================================================================================================
//Multiple Inheritence -----------------------------------------------------------------
#include <iostream>
using namespace std;

class LandVehicle
{
  public:
    void landInfo()
    {
        cout << "This is a LandVehicle" << endl;
    }
};

class WaterVehicle
{
  public:
    void waterInfo()
    {
        cout << "This is a WaterVehicle" << endl;
    }
};

// Derived class inheriting from both base classes
class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
  public:
    AmphibiousVehicle()
    {
        cout << "This is an AmphibiousVehicle" << endl;
    }
};

int main()
{
    AmphibiousVehicle obj;

    obj.waterInfo();
    obj.landInfo();

    return 0;
}
Output
This is an AmphibiousVehicle
This is a WaterVehicle
This is a LandVehicle

============================================================================================================
//MultiLevel Inheritence ----------------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle
{
  public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// Derived class from Vehicle
class FourWheeler : public Vehicle
{
  public:
    FourWheeler()
    {
        cout << "4 Wheeler Vehicles" << endl;
    }
};

// Derived class from FourWheeler
class Car : public FourWheeler
{
  public:
    Car()
    {
        cout << "This 4 Wheeler Vehicle is a Car" << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}
Output
This is a Vehicle
4 Wheeler Vehicles
This 4 Wheeler Vehicle is a Car

// Another example using parameterized constructor ---------------------------------------
#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;

public:
    // parameterized constructor
    Vehicle(int s) {
        speed = s;
        cout << "Vehicle constructor called\n";
    }
};

class FourWheeler : public Vehicle {
protected:
    int wheels;

public:
    // passes value to Vehicle constructor
    FourWheeler(int s, int w) : Vehicle(s) {
        wheels = w;
        cout << "FourWheeler constructor called\n";
    }
};

class Car : public FourWheeler {
public:
    // passes values to FourWheeler constructor
    Car(int s, int w) : FourWheeler(s, w) {
        cout << "Car constructor called\n";
    }

    void show() {
        cout << "Speed: " << speed << ", Wheels: " << wheels << endl;
    }
};

int main() {
    Car c(120, 4);
    c.show();
}

============================================================================================================
//Hybrid Inheritence -------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle
{
  public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

class Fare
{
  public:
    Fare()
    {
        cout << "Fare of Vehicle" << endl;
    }
};

class Car : public Vehicle
{
  public:
    Car()
    {
        cout << "This Vehical is a Car" << endl;
    }
};

class Bus : public Vehicle, public Fare
{
  public:
    Bus()
    {
        cout << "This Vehicle is a Bus with Fare";
    }
};

int main()
{
    Bus obj2;
    return 0;
}
Output
This is a Vehicle
Fare of Vehicle
This Vehicle is a Bus with Fare
```

---

#### Diamond Problem

> Hybrid Inheritance can lead to the **diamond problem** in C++. This happens when a class inherits from two classes that both share the same base class. As a result the derived class gets multiple copies of the base class members, which creates ambiguity about which one to use.

```
                Base
                /   \
             par1   par2
                \   /
                child
```

#### Solution to Diamond Problem

C++ resolves the Diamond Problem using **virtual inheritance**. Virtual inheritance ensures that only one shared instance of the base class exists, regardless of how many times it is inherited.

> **virtual inheritance** → C++ technique to avoid multiple copies of the base class into children/derived class.

**Without virtual inheritance** — each inheritance path creates its own copy of base class:

```
D object
 ├── B part
 │     └── A (copy 1)
 ├── C part
       └── A (copy 2)
```

**With virtual inheritance** — all paths SHARE a single base class object:

```
D object
 ├── B part
 ├── C part
 └── ONE shared A (virtual base)
```

#### 📄 Code Example — `virtual/virtualinheritence.cpp`

```cpp
Without Virtual Inheritance (Problem)

#include <iostream>
using namespace std;

class A {
public:
    int x;
    A() { x = 10; }
};

class B : public A {};
class C : public A {};

class D : public B, public C {};
--------------------------------------
🧠 What memory looks like:
D object
 ├── B part
 │     └── A (copy 1)
 ├── C part
       └── A (copy 2)

So D contains:
A inside B
A inside C

👉 So actually: 2 separate A objects exist inside D
---------------------------------------
❌ Problem(Gives Error)
// Without virtual, C++ usually gives a compile-time ambiguity error
D obj;
obj.x = 5;   // ERROR: ambiguous
--------------------------------------
Why?
Because compiler doesn’t know:
Should I access A from B or A from C?

=======================================================================================================




#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor\n"; }
};

class B : virtual public A {
public:
    B() { cout << "B constructor\n"; }
};

class C : virtual public A {
public:
    C() { cout << "C constructor\n"; }
};

class D : public B, public C {
public:
    D() { cout << "D constructor\n"; }
};

Output:
A constructor
B constructor
C constructor
D constructor
Key observation:

👉 A is constructed ONLY ONCE
👉 And it happens at the TOP level (D)

🧠 Why does this happen?
Because virtual base class (A) is shared, so:
B and C do NOT construct it separately
D is responsible for constructing the single shared A

✅ What it actually means: 
The base class subobject is created only once inside the final derived object (not multiple copies via different paths).
```

#### Ambiguity in Inheritance

> Ambiguity occurs when the compiler cannot determine which base class member to access.

#### 📄 Code Example — `Ambiguity.cpp`

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void print() { cout << "A" << endl; }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D d;
    d.B::print();
    d.C::print();
    return 0;
}

Output
A
A

Explanation
'A' defines the function "print()".
'B' and 'C' inherit "print()" from 'A'.
'D' inherits from both 'B' and 'C', causing ambiguity.
The ambiguity is resolved using scope resolution "(d.B::print() and d.C::print())".

=======================================================================================================
// Scope Resolution ----------------------------------
#include <iostream>
using namespace std;

int x = 100;   // global

int main() {
    int x = 50; // local

    cout << x << endl;    // 50 (local)
    cout << ::x << endl;   // 100 (global)
}
```

---

#### Advantages of Inheritance in C++

- Code Reusability
- Abstraction
- Class Hierarchy
- Polymorphism

#### Disadvantages of Inheritance in C++

- Tight Coupling
- Reduced Flexibility
- Increased Complexity
- Diamond Problem
- Overhead of Virtual Functions

---

### 4. Polymorphism

> The word polymorphism means having many forms. In C++, polymorphism concept can be applied to functions and operators. A single function name can work differently in different situations. Similarly, an operator works different when used in different context.

```
                       Polymorphism
                            |
             -------------------------------
             |                             |
         compile time                   runtime
         /          \                      |
func overloading  operator overloading  func overriding
```

---

#### 1. Compile-Time Polymorphism

> In compile-time polymorphism, the compiler determines how the function or operator will work depending on the context. This type of polymorphism is achieved by function overloading or operator overloading.  
> Also known as **early binding** and **static polymorphism**.

**Function Overloading**
> Function overloading is a feature of object-oriented programming where two or more functions can have the same name but behave differently for different parameters.

**Operator Overloading**
> C++ has the ability to provide the operators with a special meaning for particular data type, this ability is known as operator overloading.

For example, we can make use of the addition operator `(+)` for string to concatenate two strings and for integer to add two integers. The `<<` and `>>` operator are binary shift operators but are also used with input and output streams. This is possible due to operator overloading.

#### 📄 Code Example — `polymorhism/compiletime.cpp`

```cpp
// Function Overloading ----------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Geeks {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }
};

int main() {
    Geeks gfg;
    
    // add() called with int values
    gfg.add(10, 2);

    // add() called with double value
    gfg.add(5.3, 6.2);

    return 0;
}

======================================================================================================
// Operator Overloading -----------------------------------------------
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) :
    real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real,
        imag + obj.imag);
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    
    // Adding c1 and c2 using + operator
    Complex c3 = c1 + c2;   // Its like Complex c3 = c1.operator+(c2);
    cout << c3.real << " + i" << c3.imag;
    return 0;
}
--------------------------------------------------------------------------
🔥 Think of Operator Overloading as Function Call Replacement

When you write:
Complex c3 = c1 + c2;
👉 It does NOT directly add objects
👉 It gets converted into a function call
 --------------------------------
| Complex c3 = c1.operator+(c2); |
 --------------------------------
So basically:
c1 → the object calling the function (this)
c2 → passed as parameter
operator+ → just a function name
---------------------------------------------------------------------------
// More simpler example of Operator overloading
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    // Constructor
    Box(int l) {
        length = l;
    }

    // Overload + operator
    Box operator + (Box b) {
        return Box(length + b.length);
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(10);
    Box b2(20);

    Box b3 = b1 + b2;  // operator+ gets called

    b3.display();
}
```

---

#### 2. Runtime Polymorphism

> The function call in runtime polymorphism is resolved at runtime in contrast with compile time polymorphism, where the compiler determines which function call to bind at compilation (compile time).  
> Also known as **late binding** and **dynamic polymorphism**.  
> Runtime polymorphism is implemented using **function overriding** with **virtual functions**.

**Function Overriding**
> Function Overriding occurs when a derived class defines one or more member functions of the base class. That base function is said to be overridden. The base class function must be declared as virtual function for runtime polymorphism to happen.

#### 📄 Code Example — `polymorhism/runtime.cpp`

```cpp
// Function overriding --------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Base {
public:

    // Virtual function
    virtual void display() {
        cout << "Base class function";
    }
};

class Derived : public Base {
public:

    // Overriding the base class function
    void display() override {
        cout << "Derived class function";
    }
    /*
    WHY OVERRIDE keyword ?
    “The override keyword is not mandatory, but it is recommended because it 
    ensures that the function is actually overriding a virtual function from the base class. 
    It helps catch errors at compile time if the function signature does not match.” 
    */
};

int main() {
    
    // Creating a pointer of type Base
    Base* basePtr;
    
    // Creating an object of Derived class
    Derived derivedObj;

    // Pointing base class pointer to 
    // derived class object
    basePtr = &derivedObj;
    
    // Calling the display function 
    // using base class pointer
    basePtr->display();
    return 0;
}
===================================================================================================
How C++ actually knows which function to call at runtime. ---------------------------------------

🔥 Short Answer
👉 C++ uses something called a vtable (virtual table) and a vptr (virtual pointer).

🧠 What are these?
1. vtable (Virtual Table)
    A table created by the compiler
    Stores addresses of virtual functions

2. vptr (Virtual Pointer)
    A hidden pointer inside every object of a class with virtual functions
    Points to that class’s vtable

🔍 Let’s Apply to Your Example

🧱 Step 1: Compiler Creates Tables
Base vtable:
display → Base::display
Derived vtable:
display → Derived::display

🧱 Step 2: Object Creation
Derived derivedObj;
👉 Inside this object:
derivedObj:
[ vptr → Derived vtable ]

🧱 Step 3: Pointer Assignment
Base* basePtr = &derivedObj;

👉 Important:
Pointer type = Base*
Object type = Derived

🧱 Step 4: Function Call
basePtr->display();

⚡ What happens internally?
Step-by-step:
1. Go to object (derivedObj)
2. Access its vptr
3. vptr points to Derived's vtable
4. Look for display() in that table
5. Call Derived::display()

🎯 Why NOT Base::display()?
Because:
Decision is based on OBJECT TYPE (Derived), not pointer type
🆚 Without virtual

If virtual is removed:
No vtable, no vptr
→ Compiler directly calls Base::display()
→ Based only on pointer type

-------------------------------------------------------------------------------------------------
                    Base vtable
              +-----------------------+
              | display → Base::display |
              +-----------------------+


                    Derived vtable
              +---------------------------+
              | display → Derived::display |
              +---------------------------+


Base* ptr
   │
   ▼
+--------------------------------------------------+
|            Derived Object (obj)                  |
|--------------------------------------------------|
| vptr -----------------------------------------+  |
|                                               |  |
| Base class part                               |  |
| (Base members, if any)                        |  |
|                                               |  |
| Derived class part                            |  |
| (Derived members, if any)                     |  |
+--------------------------------------------------+
vptr → points to Derived vtable

------------------------------------------------------------------------------------------------

Super Simple Analogy
    Think of it like:
   -> Object carries a "function menu" (vtable)
   -> Pointer asks: "hey object, which display should I call?"
   -> Object says: "use THIS one (Derived)"

What happens internally?
1. basePtr → goes to derivedObj
2. find vptr inside object
3. vptr → Derived vtable
4. lookup "display"
5. found → Derived::display
6. call it
```

---

#### How C++ actually knows which function to call at runtime? `[IMP]`

> "In runtime polymorphism, C++ uses virtual functions to decide which function to call at runtime.  
> Internally, the compiler creates a **vtable** (virtual table) for each class containing virtual functions.  
> Each object has a hidden pointer called **vptr** (virtual Pointer) that points to the vtable of its actual class.  
> When we call a function using a base class pointer, the program looks at the object's vptr at runtime, finds the correct function in the vtable, and calls it.  
> So even if the pointer is of type base class, the function of the actual object type is executed."

> 📝 **NOTE** → "A derived class pointer cannot point to a base object because the base object doesn't contain the derived part. This would lead to unsafe memory access."

---

## Virtual Function

> A virtual function is a member function that is declared within a base class using the keyword `virtual` and is re-defined (Overridden) in the derived class. Virtual functions enable runtime polymorphism, calling the correct function via a base class pointer or reference.

## Virtual Destructor

> Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.

👉 A virtual destructor does **NOT** call the derived destructor.  
It ensures the derived destructor is called when deleting through a base pointer.

#### 📄 Code Example — `virtual/virtualDestructor.cpp`

```cpp
// CPP program without virtual destructor 
// causing undefined behavior
#include <iostream>

using namespace std;

class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    ~base()
    { cout<< "Destructing base\n"; }     
};

class derived: public base {
  public:
    derived()     
     { cout << "Constructing derived\n"; }
    ~derived()
       { cout << "Destructing derived\n"; }
};

int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
}

Output -------------------------------------
Constructing base
Constructing derived
Destructing base
=========================================================================
Making base class destructor virtual guarantees that the object of derived class is destructed properly,
i.e., both base class and derived class destructors are called. For example,
=========================================================================
// A program with virtual destructor
#include <iostream>

using namespace std;

class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }     
};

class derived : public base {
  public:
    derived()     
    { cout << "Constructing derived\n"; }
    ~derived()
    { cout << "Destructing derived\n"; }
};

int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
} 

Output -----------------------------------------------
Constructing base
Constructing derived
Destructing derived
Destructing base
=================================================================================================
“A virtual destructor ensures that when a base class pointer points to a derived object,
deleting it calls the derived class destructor first, followed by the base class destructor.
This prevents resource leaks and ensures proper cleanup.”
=================================================================================================
```

## Pure Virtual Function

> A pure virtual function is a function in a base class with `= 0` and no body, which must be overridden in derived classes. A class with such a function is called **abstract** and cannot be instantiated.

---

## Binding

> When a function is called in the code, binding decides which function gets executed based on the context such as the type of object or the function signature. Binding happens at two levels:

- **Early Binding:** It happens when a function call is resolved during the program's compilation. This makes it faster because everything is decided early.
- **Late Binding:** It happens with virtual functions where the exact function to call is decided at runtime, depending on the actual object type. This is slower because the program has to figure it out while running.

### How does the compiler perform runtime resolution?

The compiler maintains two things to serve this purpose:

| | Description |
|--|-------------|
| **vtable** | A table of function pointers, maintained per class. |
| **vptr** | A pointer to vtable, maintained per object instance. |

### Limitations of Virtual Functions

- Slower
- Difficult to Debug

#### 📄 Code Example — `binding.cpp`

```cpp
#include <iostream>
using namespace std;

class base
{
  public:
    virtual void print()
    {
        cout << "print base "
                "class\n";
    }

    void show()
    {
        cout << "show base class\n";
    }
};

class derived : public base
{
  public:
    void print()
    {
        cout << "print derived class\n";
    }

    void show()
    {
        cout << "show derived class\n";
    }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;

    // Virtual function,binded at runtime
    bptr->print();

    // Non-virtual function,binded at compile time
    bptr->show();
    return 0;
}

Output -----------------------------------------------------
print derived class
show base class

Explanation: In the above code, the print() function is declared with the virtual keyword 
so it will be bound at runtime and show() is non-virtual so it will be bound during compile time.
```

---

## Friend Class and Function

> In C++, friend functions and friend classes are concepts that allow certain functions or classes to access the private and protected members of another class.

### Friend Class

> A friend class can access private and protected members of other classes in which it is declared as a friend.

- Remember one thing, **friendship is not mutual**. If class A is a friend of B, then B doesn't become a friend of A automatically.
- We can declare a friend class in C++ by using the `friend` keyword.

#### 📄 Code Example — `FriendClassandFunc/friendClass.cpp`

```cpp
#include <iostream>
using namespace std;

class Geeks {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Geeks() {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class GFG;
};

// class GFG is declared as a friend
// inside class Geeks, therefore
// Class GFG can access private members
// of class Geeks.
class GFG {
public:
    void display(Geeks t) {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable;
    }
};

int main() {
    Geeks g;
    GFG fri;
    fri.display(g);
    return 0;
}

Output --------------------------------------------------
The value of Private Variable = 10
The value of Protected Variable = 99

Note: We can declare friend class or function anywhere in the base class body whether
its private, protected or public block. It works all the same.
```

### Friend Function

> Like friend classes, a friend function can be granted special access to private and protected members of a class in C++. They are not the member functions of the class but can access and manipulate the private and protected members of that class for they are declared as friends.

#### 1. Global Function as Friend Function

> We can declare any global function as a friend function. The keyword `"friend"` is placed only in the function declaration of the friend function and not in the function definition or call.

#### 2. Member Function of Another Class as Friend Function

> We can also declare a member function of another class as a friend function in C++. Forward declaration (friend class should declare before using it as a friend) of the class is needed if we want to make a member function of another class a friend inside that class.

#### 📄 Code Example — `FriendClassandFunc/friendFunction.cpp`

```cpp
// Global Function as Friend Function ------------------------------------------------------
#include <iostream>
using namespace std;

class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }
    
    // Friend function declaration
    friend void friendFunction(base& obj);
};


// friend function definition
void friendFunction(base& obj) {
    cout << "Private Variable: " 
         << obj.private_variable << endl;
    cout << "Protected Variable: " 
         << obj.protected_variable;
}

int main() {
    base object1;
    friendFunction(object1);
    return 0;
}

Output ---------------------------
Private Variable: 10
Protected Variable: 99

==========================================================================================================

// Member Function of Another Class as Friend Function ------------------------------

#include <iostream>
using namespace std;

// Forward Declaration needed
class base;

// Another class in which function is declared
class GFG {
public:
    void GFG_Function(base& obj);  // declaration should be done before class and defination will done after 
};

// Base class declare a frined
// function of another class
class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }

    // Friend function declaration
    friend void GFG::GFG_Function(base&);
};

// Friend function definition
void GFG::GFG_Function(base& obj) {
    cout << "Private Variable: " << 
             obj.private_variable
         << endl;
    cout << "Protected Variable: " << 
             obj.protected_variable;
}

int main() {
    base object1;
    GFG object2;
    object2.GFG_Function(object1);

    return 0;
}

Output -------------------------
Private Variable: 10
Protected Variable: 99
```

### Advantages vs Disadvantages

| Advantages | Disadvantages |
|-----------|---------------|
| Access private and protected members without inheritance | Violates data hiding by exposing private members |
| Can be declared in any access section of a class | Breaks encapsulation when overused |
| Useful for operator overloading flexibility | Do not support runtime polymorphism |
| | Friendship is not inherited by derived classes |

---

## Copy Assignment Operator

> Used to assign one existing object to another

```cpp
ClassName& operator=(const ClassName& other);
```

✔ **When it is called:**

```cpp
A obj1(10);
A obj2(20);

obj2 = obj1;   // assignment operator
```

**Example:**

```cpp
class A {
public:
    int x;

    A(int val) { x = val; }

    A& operator=(const A& other) {
        x = other.x;
        return *this;             // this is a pointer to the current object
                                  // Dereferencing the pointer
                                  // Gives the actual object itself
    }
};
```

#### 📄 Code Example — `copy/copyConstVSassignmentOp.cpp`

```cpp
====================================================================================================================
// Example WITHOUT deep copy (problem case)
#include <iostream>
using namespace std;

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }
};

int main() {
    Demo obj1(10);

    Demo obj2 = obj1;   // Copy constructor
    Demo obj3(20);
    obj3 = obj1;        // Assignment operator

    cout << obj1.data << endl;
    cout << obj2.data << endl;
    cout << obj3.data << endl;
}
--------------------------------------------------------------------------------------
🔹 What happens
1. Copy Constructor
    Demo obj2 = obj1;
    New object obj2 created
    But pointer copied → same memory
    ❌ No new memory for data

2. Assignment Operator
    obj3 = obj1;
    obj3 already exists
    Its pointer gets overwritten
    ❌ Old memory leaked
    ❌ Now also shallow copy

====================================================================================================================

// Correct Version (Deep Copy)
#include <iostream>
using namespace std;

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    // Copy Constructor
    Demo(const Demo& other) {
        cout << "Copy Constructor\n";
        data = new int(*other.data);   // new memory
    }

    // Assignment Operator
    Demo& operator=(const Demo& other) {
        cout << "Assignment Operator\n";
        if (this != &other) {
            delete data;                      // free old memory
            data = new int(*other.data);     // new memory
        }
        return *this;
    }

    ~Demo() {
        delete data;
    }
};

int main() {
    Demo obj1(10);

    Demo obj2 = obj1;   // Copy constructor
    Demo obj3(20);
    obj3 = obj1;        // Assignment operator

    cout << obj1.data << endl;
    cout << obj2.data << endl;
    cout << obj3.data << endl;
}

---------------------------------------------------------------------------
🔹 Now what happens
    Copy Constructor:
    Demo obj2 = obj1;

    ✔ Creates new object
    ✔ Allocates new memory

Assignment Operator:
    obj3 = obj1;
    ✔ Object already exists
    ✔ Deletes old memory
    ✔ Allocates new memory again

------------------------------------------------------------------------------

Important:------------------------------------------------
"Assignment operator does not make new memory"
👉 ❌ Not always true
👉 ✔ Correct version => Assignment operator may allocate new memory, but only after cleaning old memory.

============================================================================================================================
```

---

## Shallow Copy

> In shallow copy, all variable values are copied, but **dynamically allocated memory addresses are shared** between objects.  
> Both objects point to the same heap memory, so changes made through one object affect the other.

#### 📄 Code Example — `copy/ShallowCopy.cpp`

```cpp
#include <iostream>
using namespace std;

class Sample {
public:
    int *x;

    Sample(int val) {
        x = new int;
        *x = val;
    }
};

int main() {
    Sample obj1(10);     // Original object
    Sample obj2 = obj1; // Shallow copy

    *obj2.x = 50;       // Modify copied object

    cout << "obj1.x = " << *obj1.x << endl;
    cout << "obj2.x = " << *obj2.x << endl;

    return 0;
}

Output ----------------------------
obj1.x = 50
obj2.x = 50


Explanation:--------------------------------------------------------------------
"obj1" is created and memory is allocated for variable x.
"obj2" = "obj1" copies only the memory address of x, not the actual data.
Both objects now point to the same heap memory.
Changing obj2.x also changes obj1.x.
```

## Deep Copy

> In deep copy, a new object is created by copying all variable values and allocating **separate memory** for dynamically allocated variables.  
> Both the original and copied objects store their data in different memory locations.  
> Changes made to one object do not affect the other because a custom copy constructor is used.

#### 📄 Code Example — `copy/DeepCopy.cpp`

```cpp
#include <iostream>
using namespace std;

class Sample {
public:
    int *x;
    Sample(int val) {
        x = new int;
        *x = val;
    }
    // Deep Copy Constructor
    Sample(const Sample &obj) {
        x = new int;           // uninitialized
                               // x = new int();    // value-initialized (set to 0)
        *x = *(obj.x);        // Dereference both pointers and assign the value from obj to current object
    }
};

int main() {
    Sample obj1(10);      // Original object
    Sample obj2(obj1);   // Deep copy

    *obj2.x = 50;        // Modify copied object

    cout << "obj1.x = " << *obj1.x << endl;
    cout << "obj2.x = " << *obj2.x << endl;

    return 0;
}


Output-------------------------------------------------
obj1.x = 10
obj2.x = 50

Explanation:--------------------------------------------
"obj1" allocates memory and stores value 10.
custom copy constructor creates new memory for obj2.
"obj2" gets its own separate memory with the same value.
Changing obj2.x does not affect obj1.x.

======================================================================================================
// EXTRA
Between these two:

x = new int;     // uninitialized
x = new int();   // initialized to 0

✅ Prefer this: x = new int();

🔹 Why?
1. Safety
new int → gives garbage value (undefined behavior if used)
new int() → guaranteed 0

👉 Uninitialized memory is a very common source of bugs.

2. Predictability
int* x = new int;
cout << *x;  // ❌ unpredictable
int* x = new int();
cout << *x;  // ✅ always 0
```

---

## Copy Constructor

> A copy constructor is a special type of constructor used to create a new object using an existing object of the same class.

### Default Copy Constructor

> Compiler creates a default copy constructor if there is no user defined constructor. This compiler created constructor does a **shallow copy** and works well for basic types, but does not work for dynamic allocated memory.

→ Default copy constructor (shallow copy) can lead to **dangling pointer** problems, especially when your class owns dynamic memory.

#### 📄 Code Example — `copy/deafaultCopyConst.cpp`

```cpp
#include <iostream>
using namespace std;

// Create a demo class
class A
{
  public:
    int x;
};

int main()
{

    // Creating an a1 object
    A a1;
    a1.x = 10;
    cout << "a1's x = " << a1.x << endl;

    // Creating another object using a1
    A a2(a1);
    cout << "a2's x = " << a2.x;

    return 0;
}

Output--------------------------------
a1's x = 10
a2's x = 10
```

### User Defined Copy Constructor

> C++ also allows programmers to create their own version of copy constructor known as **user defined** or **explicit copy constructor**.

→ If a class has pointers or runtime resources (like dynamic memory), a custom copy constructor is needed. Otherwise, deletion of one object might cause deletion of an unrelated object members.

#### 📄 Code Example — `copy/USerDefinedCopyConst.cpp`

```cpp
#include <iostream>
using namespace std;

class A
{
  public:
    int x;
    A(){};

    // Copy Constructor definition
    A(A &obj)
    {
        x = obj.x;
        cout << "Copy constructor "
                "called"
             << endl;
    }
};

int main()
{

    // Creating an object of class A
    A obj1;
    obj1.x = 10;
    cout << "obj1's x = " << obj1.x << endl;

    // Creating another object by copying already created object
    A obj2(obj1);
    
    cout << "obj2's x = " << obj2.x;
    return 0;
}

Output-----------------------------------------
obj1's x = 10
Copy constructor called
obj2's x = 10
```

### Need of User Defined Copy Constructor

- If no copy constructor is defined, C++ provides a default copy constructor.
- The default copy constructor performs a shallow copy — shallow copy copies pointer values, not the actual resources they point to.
- Without a custom copy constructor, shallow copy can lead to dangling pointers or resource conflicts.

### Dangling Pointer

> A pointer pointing to a memory location that has been deleted (or freed) is called a **dangling pointer**. Such a situation can lead to unexpected behavior in the program.

### Copy Elision

> Copy elision (also known as **copy omission**) is a compiler optimization method that prevents objects from being duplicated or copied.

→ In copy elision, the compiler prevents the making of extra copies by making the use to techniques such as **NRVO** (Named Return Value Optimization) and **RVO** (Return Value Optimization) which results in saving space and better the program complexity (both time and space); Hence making the code more optimized.

### Copy Constructor vs Assignment Operator

> **Key Idea:**

- ✔ Copy constructor → creates **new object** (new memory)
- ✔ Assignment operator → reuses **existing object** (may reuse or reallocate memory depending on implementation)

---

## Memory Management

---

### 1. Stack vs Heap

#### 🧠 Stack Memory

- Automatically managed
- Stores:
  - Local variables
  - Function calls
- Fast access
- Limited size
- Lifetime: ends when function ends

```cpp
void func() {
    int x = 10; // stored in stack
}
```

👉 `x` is destroyed automatically after `func()` ends.

---

#### 🧠 Heap Memory

- Manually managed
- Used for dynamic allocation
- Slower than stack
- Large memory available
- Lifetime: until you delete it

```cpp
int* p = new int(10);  // stored in heap
```

👉 Memory stays even after function ends unless deleted.

---

### 2. `new` and `delete`

#### 🧠 `new`
- Allocates memory on heap
- Returns pointer

```cpp
int* p = new int(5);
```

#### 🧠 `delete`
- Frees heap memory

```cpp
delete p;
```

⚠️ **Arrays case:**

```cpp
int* arr = new int[5];
delete[] arr; // IMPORTANT
```

👉 Using `delete` instead of `delete[]` = **undefined behavior**

---

### 3. Memory Leak

#### 🧠 Definition
Memory that is allocated but never freed.

```cpp
void func() {
    int* p = new int(10);
    // forgot delete
}
```

👉 Memory stays occupied even after function ends.

**Why dangerous?**
- Wastes memory
- Can crash long-running programs
- Common in large systems

✅ **Fix:**
```cpp
delete p;
```

> 💡 **Interview Tip:**  
> Mention: *"Use smart pointers like `unique_ptr` to avoid leaks"*

---

### 4. Dangling Pointer

#### 🧠 Definition
Pointer pointing to freed or invalid memory.

❌ **Example:**

```cpp
int* p = new int(10);
delete p;
cout << *p; // ❌ dangling pointer
```

❌ **Another Example:**

```cpp
int* func() {
    int x = 10;
    return &x;   // ❌ stack memory returned — pointing to stack memory not heap memory
}
```

✅ **Fix:**

```cpp
delete p;
p = nullptr; // safe
```

**Why dangerous?**
- Undefined behavior
- Random crashes
- Hard to debug

---

## Rule of 3 / 5

---

### Rule of 3 (Classic C++)

#### 🧠 Idea

If your class manages dynamic memory (heap), you must define these **3**:
- Destructor
- Copy Constructor
- Copy Assignment Operator

**Why?**  
Because the default versions do shallow copy, which causes:
- ❌ Double delete
- ❌ Dangling pointers
- ❌ Memory leaks

#### 📄 Code Example — `Rule035/rule3.cpp`

```cpp
// Problem Example (Shallow Copy Issue)
class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    ~Demo() {
        delete data;
    }
};
Demo d1(10);
Demo d2 = d1; // shallow copy

//  Now both d1.data and d2.data point to SAME memory
//  Destructor runs twice → crash (double delete)

=========================================================================================================

// Fix (Rule of 3 Applied)
class Demo {
public:
    int* data;

    // Constructor
    Demo(int val) {
        data = new int(val);
    }

    // Copy Constructor
    Demo(const Demo& other) {
        data = new int(*other.data); // deep copy
    }

    // Copy Assignment Operator
    // this → address of current object (d1) (i.e. d1=d2)
    // &other → address of RHS object (d2)
    Demo& operator=(const Demo& other) {
        if (this != &other) {                   //  Checks self-assignmen i.e. d1 = d1;
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Destructor
    ~Demo() {
        delete data;
    }
};
```

---

### Rule of 5 (Modern C++)

#### 🧠 Idea

C++11 added move semantics, so now we have **5** functions:
- Destructor
- Copy Constructor
- Copy Assignment
- Move Constructor
- Move Assignment

**Why Move?**  
To avoid unnecessary copying and improve performance.

**Move Concept (Simple Idea):**  
Instead of copying memory:  
👉 **"Steal" the resource**

#### 📄 Code Example — `Rule035/rule5.cpp`

```cpp
class Demo {
public:
    int* data;

    // Constructor
    Demo(int val) {
        data = new int(val);
    }

    // Copy Constructor
    Demo(const Demo& other) {
        data = new int(*other.data);
    }

    // Copy Assignment
    Demo& operator=(const Demo& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    /*
    Move Constructor:
   🧠 Idea:
    Instead of copying data, it transfers ownership (steals memory)
    */
    Demo(Demo&& other) {
        data = other.data;
        other.data = nullptr;
    }
    ---------------------------------------------------------------
    // how it is called ?
    // Demo d1(10);
    // Demo d2 = std::move(d1); // move constructor 

    // What happens?
    //   Before move:
    //   d1.data → [10]
      
    //   After move:
    //   d2.data → [10]
    //   d1.data → nullptr
    // 👉 No copy, just transfer → FAST
    ---------------------------------------------------------------
    
    // Move Assignment       // d2 = std::move(d1);
    Demo& operator=(Demo&& other) {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Demo() {
        delete data;
    }
};
------------------------------------------------------
// Why Move is Needed?
// ❌ Without move:
// Copy constructor → deep copy → slow
// ✅ With move:
// No new allocation
// No copying
// Just pointer transfer → very fast
-----------------------------------------------------

EXTRA: ----------------------------------------------
1. What is an lvalue?
🧠 Definition:
An lvalue is something that:
Has a name
Has a memory address
Can appear on the left side of =

✅ Examples:
int x = 10;  // x is lvalue
x = 20;      // valid
int y = x;   // x is lvalue

👉 x has identity (you can take its address: &x)
----------------------------------------------------
🔹 2. What is an rvalue?
🧠 Definition:
An rvalue is:
A temporary value
Has no persistent memory location
Cannot appear on left side of assignment

✅ Examples:
int x = 10;     // 10 is rvalue
int y = x + 5;  // (x + 5) is rvalue
x + 5 = 20; // ❌ invalid
--------------------------------------------------
```

---

### Interview Insight ⭐ (Very Important)

👉 If you define any one of these → you likely need all others  
👉 But in modern C++: **Prefer Rule of 0**

---

### Rule of 0 (Advanced Insight)

#### 🧠 Idea

Avoid manual memory management entirely.

Use:
- `std::vector`
- `std::string`
- Smart pointers

👉 Then you don't need Rule of 3 or 5 at all.

---

## Smart Pointers

> A smart pointer is a class that wraps a raw pointer and automatically manages the lifetime of dynamically allocated memory.

- It ensures proper resource deallocation by automatically releasing the memory when the pointer goes out of scope, thus preventing memory leaks and dangling pointers.
- Smart pointers are defined in the `<memory>` header i.e. `#include<memory>`

### Types of Smart Pointers

---

#### 1. `auto_ptr` *(Deprecated — removed after C++17)*

`auto_ptr` was an early smart pointer that automatically deleted the managed object when it went out of scope.

#### 📄 Code Example — `SmartPointers/autoPTR.cpp`

```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto_ptr<int> ptr1(new int(10));
    cout << *ptr1 << endl;

    auto_ptr<int> ptr2 = ptr1;  // ownership transfer
    cout << *ptr2;
    return 0;
}



Output
10
10

Key Points:---------------------------------------------------------------------------
Ownership is transferred, leaving the original pointer null (empty).
Copy semantics are unsafe and error-prone.

Note: auto_ptr is deprecated after C++11 and it remove after C++ version 17.
--------------------------------------------------------------------------------------
```

---

#### 2. `unique_ptr`

`unique_ptr` stores one pointer only at a time. We cannot copy `unique_ptr`, only transfer ownership of the object to another `unique_ptr` using the `move()` method.

#### 📄 Code Example — `SmartPointers/uniquePTR.cpp`

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    int area() { return length * breadth; }
};

int main() {
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    unique_ptr<Rectangle> P2;
    P2 = move(P1);  // ownership transfer
     cout << P2->area();

    //cout<<P1->area();       //👉 is dereferencing a null pointer
                             //👉 leads to crash / undefined behavior
   
    return 0;
}


// Output-----------------
// 50
// 50
// -----------------------

// Key Points:--------------------------------------------------
// ->Only one unique_ptr can own an object at a time.
// ->Lightweight and efficient.
// ->Ideal for single ownership scenarios.
// -------------------------------------------------------------
```

---

#### 3. `shared_ptr`

`shared_ptr` allows multiple pointers to share ownership of the same object. It uses **reference counting** to manage memory.

- It maintains reference counting ownership of its contained pointer in cooperation with all copies of the `shared_ptr`.
- An object referenced by the contained raw pointer will be destroyed when and only when **all copies** of the `shared_ptr` have been destroyed.

#### 📄 Code Example — `SmartPointers/sharedPTR.cpp`

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    int area() { return length * breadth; }
};

int main() {
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    shared_ptr<Rectangle> P2 = P1;                        // shallow copy 

    cout << P1->area() << endl;
    cout << P2->area() << endl;
    cout << P1.use_count();
    return 0;
}


Output ------------
50
50
2
-------------------
```

---

#### 4. `weak_ptr`

`weak_ptr` is a non-owning smart pointer used with `shared_ptr` to prevent circular dependencies.

**Key Characteristics:**
- Does not increase reference count
- Prevents circular dependency
- Must be converted using `lock()` before use

#### 📄 Code Example — `SmartPointers/weakPTR.cpp`

```cpp
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    int area() { return length * breadth; }
};

int main() {
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    weak_ptr<Rectangle> P2(P1);

    cout << P1->area() << endl;
    cout << P2.use_count();
    return 0;
}


Output ----------
50
1
-----------------
```

#### Common Smart Pointer Methods

#### 📄 Code Example — `SmartPointers/Methods.cpp`

```cpp
====================================================================================================================
1. Common Smart Pointer Methods:
These are used across unique_ptr and shared_ptr:

✅ get() --------------------------------------------------------------------

👉 Returns raw pointer (does NOT transfer ownership)
auto p = make_unique<int>(10);
int* raw = p.get();

------------------------------------------------------------------------------

✅ reset()
👉 Deletes current object and optionally assigns new one
p.reset();              // deletes object
p.reset(new int(20));   // replace with new object

------------------------------------------------------------------------------

✅ release() (ONLY for unique_ptr)
👉 Releases ownership and returns raw pointer
auto p = make_unique<int>(10);
int* raw = p.release(); // now YOU must delete raw
⚠️ After this → p becomes nullptr

------------------------------------------------------------------------------

✅ move()
👉 Transfers ownership (used with unique_ptr)
auto p2 = move(p1);

------------------------------------------------------------------------------

✅ swap()
👉 Swap ownership between two pointers
p1.swap(p2);

====================================================================================================================

🔹 2. Methods specific to shared_ptr
✅ use_count()
👉 Number of shared owners
shared_ptr<int> p1 = make_shared<int>(10);
shared_ptr<int> p2 = p1;
cout << p1.use_count(); // 2

------------------------------------------------------------------------------

✅ unique()
👉 Check if only one owner exists
if (p1.unique()) {
    cout << "Only one owner";
}

====================================================================================================================

🔹 3. Accessing object
✅ -> operator
p->area();

------------------------------------------------------------------------------

✅ * operator
cout << *p;

====================================================================================================================

🔥 Important Summary Table ----------------------------------------------------------------------------------------

Method            	unique_ptr	                 shared_ptr                           	Use
get()                 	✅	                       ✅                        	Access raw pointer
reset()	                ✅                          ✅	                        Delete / replace
release()           	✅                          ❌                          	Give up ownership
move()	                ✅	                       ❌ (not needed)	            Transfer ownership
use_count()         	❌	                       ✅	                        Count owners
unique()            	❌                          ✅                          	Check single owner
swap()              	✅	                       ✅                           	Swap pointers

-------------------------------------------------------------------------------------------------------------------
====================================================================================================================
```

---

### Problems with Normal Pointers

- **Memory Leaks:** This occurs when memory is repeatedly allocated by a program but never freed. This leads to excessive memory consumption and eventually leads to a system crash.
- **Wild Pointers:** A pointer that never be initialize with valid object or address called wild pointer.
- **Dangling Pointers:** Assume there is a pointer that refers to memory which was deallocated earlier in the program, that pointer is called a dangling pointer.

---

### Pointers vs Smart Pointers

| Pointer | Smart Pointer |
|---------|---------------|
| A pointer is a variable that maintains a memory address as well as data type information about that memory location. | Smart pointers, in simple words, are classes that wrap a pointer, or scoped pointers. |
| A pointer is a variable that points to something in memory. | |
| It is not destroyed in any form when it goes out of its scope | It destroys itself when it goes out of its scope |

---

## Move Semantics

---

### 1. What is Move Semantics (Idea)

**Before C++11:**
- Objects were copied
- Copying large objects = slow + extra memory

**After C++11:**
- We can move resources instead of copying
- That means: 👉 Transfer ownership instead of duplicating data

🔥 **Real-life analogy**

- Copy → photocopy a book 📚 (expensive)
- Move → hand over the book (cheap)

---

### 2. lvalue vs rvalue (Very Important)

✅ **lvalue**
- Has a name
- Exists in memory

```cpp
int x = 10; // x is lvalue
```

✅ **rvalue**
- Temporary value
- No name

```cpp
int x = 10 + 20; // (10+20) is rvalue
```

---

### 3. rvalue Reference `(&&)`

> This is the **backbone** of move semantics.

```cpp
int &x = 10;   // ❌ ERROR
int &&r = 10;  // rvalue reference
```

👉 It can bind to temporary objects (rvalues)

❗ **Key Rule**

| Type | Binds to |
|------|---------|
| `int&` | lvalues only |
| `int&&` | rvalues only |

**Real Use Case:**

```cpp
void process(int &&x) {
    cout << "rvalue received\n";
}

process(10); // calls this (rvalue)
```

**Compare with:**

```cpp
void process(int &x) {
    cout << "lvalue received\n";
}

int a = 5;
process(a); // lvalue version
```

---

### 4. Why Move is Needed

**Example without move:**

```cpp
vector<int> v1 = {1,2,3,4,5};
vector<int> v2 = v1; // COPY (expensive)
```

👉 Full duplication happens

**With move:**

```cpp
vector<int> v2 = move(v1); // MOVE
```

👉 Internal data (heap memory) is transferred, not copied

---

### 5. `std::move`

```cpp
std::move(x)
```

👉 Converts an lvalue into rvalue

⚠️ **Important:**
- It does NOT move anything by itself
- It just enables move

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = std::move(v1);
    cout << v1.size(); // usually 0 (moved-from state)
}
```

---

### 6. Move Constructor

> Without move constructor → copy happens  
> With move constructor → efficient transfer

**Example:**

```cpp
class Demo {
    int* data;

public:
    Demo(int val) {
        data = new int(val);
    }

    // Move Constructor
    Demo(Demo&& other) {
        data = other.data;    // transfer pointer
        other.data = nullptr; // avoid double delete
    }

    ~Demo() {
        delete data;
    }
};
```

🔥 **What happens here:**
- Ownership of memory is transferred
- Old object becomes empty / safe state

---

### 7. Move Assignment Operator

```cpp
Demo& operator=(Demo&& other) {
    if (this != &other) {
        delete data;

        data = other.data;
        other.data = nullptr;
    }
    return *this;
}
```

---

### 8. When Move Happens Automatically

Move is used when:
- Returning objects from functions
- Using `std::move`
- Temporary objects

**Example:**

```cpp
Demo create() {
    Demo d(10);
    return d; // move happens
}
```

---

## Templates (Generic Programming)

> Generic programming is a way of writing code so it works with any data type, instead of being limited to one specific type.

### 🔹 What problem do templates solve?

Without templates, you'd write the same logic again and again:

```cpp
int add(int a, int b);
double add(double a, double b);
```

👉 Repetition ❌

### 🔹 Template Solution

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

**Usage:**

```cpp
cout << add(2, 3);       // int
cout << add(2.5, 3.1);   // double
```

### 🔹 Key Idea

👉 Write code once, use with any data type

#### 📄 Code Example — `template.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Box {
    T value;

public:
    Box(T v) : value(v) {}

    void show() {
        cout << value << endl;
    }
};

int main(){
    Box<int> b1(10);
    Box<string> b2("Hello");

    b1.show();   // prints 10
    b2.show();   // prints Hello

    return 0;
}


// Interview Insight :
// Templates = compile-time polymorphism
```

---

## Exception Handling

### 🔹 Why needed?

- To handle runtime errors safely
- Without it → program crashes ❌

### 🔹 Basic Keywords

| Keyword | Purpose |
|---------|---------|
| `try` | code that may cause error |
| `throw` | raise error |
| `catch` | handle error |

**Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10, b = 0;

        if (b == 0)
            throw "Division by zero error";

        cout << a / b;
    }
    catch (const char* msg) {
        cout << msg;
    }
}
```

**How it works:**
- `try` block runs
- Error occurs → `throw`
- Control jumps to `catch`

### Custom Exception (OOP + Exception)

```cpp
class MyException {
public:
    void message() {
        cout << "Custom Exception!";
    }
};

try {
    throw MyException();
}
catch (MyException e) {
    e.message();
}
```

#### 📄 Code Example — `tryCatch.cpp`

```cpp
// Custom Exception
#include <iostream>
#include <exception>
using namespace std;

// Custom Exception
class InsufficientBalanceException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient balance!";
    }
};

// Bank Account class (OOP)
class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientBalanceException(); // 🚨 throw
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000);

    try {
        acc.withdraw(6000); // ❌ will throw exception
    }
    catch (const InsufficientBalanceException& e) { // ✅ catch
        cout << e.what() << endl;
    }

    return 0;
}

===================================================================================================================
// Basic Exception 

#include <iostream>
#include <stdexcept>  // for standard exceptions
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Error: Insufficient balance!"); // built-in exception
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000);

    try {
        acc.withdraw(6000); // ❌ will throw
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
```


---

## Method Chaining (via `this`)

> `this` is a pointer used to access the current object, resolve naming ambiguity between a parameter and a member, and return the current object — the last of these enables **method chaining**.

#### 📄 Code Example — `methodChaining.cpp`

```cpp
Returning Object using this => To return current object
this keyword is used for method chaining

this is a pointer Used to:
        Access current object
        Resolve ambiguity
        Return current object

💡 Example (Method Chaining)
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }

    Demo* setX(int x) {
        this->x = x;
        return this;   // return current object
    }

    void show() {
        cout << x << endl;
    }
};

int main() {
    Demo d(10);
    d.setX(20)->show();  // chaining
}

=======================================================================================================

🔥 Better Version (Returning Reference)
class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }

    Demo& setX(int x) {
        this->x = x;
        return *this;   // return object
    }
};

👉 Now you can do:

d.setX(10).setX(20);
```

---

## Extra Notes & Practice Questions

### When to use `new` and when not to

#### 📄 Code Example — `EXTRA/notes.cpp`

```cpp
===================================================================================================================================
// When to use new and when to not use new

// 1. ClassName a; → Stack Allocation
class A {
public:
    int x;
};

int main() {
    A a;   // object on stack
}

✔ What happens:
    Object is created automatically on stack
    Constructor is called
    Destructor is automatically called when it goes out of scope

✅ Use this when:
    You don’t need the object beyond the current scope
    No need for manual memory control
    This is the preferred/default way

----------------------------------------------------------------------------------

// 2. new ClassName() → Heap Allocation

int main() {
    A* a = new A();  // object on heap
}

✔ What happens:
    Object is created on heap (dynamic memory)
    You get a pointer
    Destructor is NOT called automatically

👉 You must do:
        delete a;

------------------------------------------------------------------------------------------------------------------------------

⚠️ When should you use new?
->Use heap allocation only when you really need it:

✔ Common cases:
    Object size is large
    Lifetime should extend beyond scope
    Dynamic data structures (linked list, tree, graph)
    Polymorphism (runtime behavior)

Example:
A* a = new A();

-----------------------------------------------------------

❌ When NOT to use new
    Simple objects like your example
    Short-lived variables
    When you don’t want memory leaks

----------------------------------------------------------
🔥 Modern C++ Advice (IMPORTANT)

Avoid raw new → use smart pointers instead:
#include <memory>
unique_ptr<A> a = make_unique<A>();

✔ Automatically deletes memory
✔ No memory leaks
===============================================================================================================================
```

### Abstract Class Practice Question

#### 📄 Code Example — `EXTRA/questions.cpp`

```cpp
Case: ------------------------------------------------------------
    Interface (base class) has pure virtual function
    Child1 does NOT implement it
    Child2 implements it

#include <iostream>
using namespace std;

class Interface {
public:
    virtual void show() = 0;   // pure virtual
};

// Child1 does NOT implement show()
class Child1 : public Interface {
    // still abstract
};

// Child2 implements show()
class Child2 : public Interface {
public:
    void show() override {
        cout << "Child2 implementation" << endl;
    }
};

What happens?
1. Child1
Child1 obj;   // ❌ ERROR

Error:
cannot declare variable ‘obj’ to be of abstract type ‘Child1’

👉 Because:
Child1 did NOT implement show()
So it is still abstract

2. Child2
Child2 obj;   // ✅ OK

===========================================================================================================
```
