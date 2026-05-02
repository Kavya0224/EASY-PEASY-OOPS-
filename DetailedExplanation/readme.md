# OOP C++ Notes

> if you create objects with `new`, you must delete them (using `delete` or calling destructor) to free memory and run cleanup code. Otherwise you risk memory leaks and unfinished resource handling.

> A memory leak happens when a program allocates memory but never releases it, even after it's no longer needed. **Memory leak = used memory that is never freed**

> an empty destructor = same as no destructor or default destructor. C++ not automatically delete heap memory (`new`) like it does for stack objects. (for heap we use `delete`)

---

### What is Function Hiding?

👉 When a derived class defines a function with the same name as in the base class.  
👉 the base class function gets hidden, even if signatures are different.

---

## 5. OOP over Procedure-Oriented Programming Language

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

---

### 2. Abstraction

> Abstraction in C++ is the process of hiding the implementation details and only showing the essential details or features to the user. It allows to focus on **what** an object does rather than **how** it does it.

Abstraction is mainly achieved using **abstract classes** and **pure virtual functions**. These define a common interface for derived classes while leaving the actual implementation to them.

#### Abstract Class

An abstract class is a class that:
- Cannot be instantiated (no objects can be created)
- Contains at least one pure virtual function

#### Full Abstraction — Interfaces

In C++, a class can act as an interface if it contains **only pure virtual functions** and no data members or implemented methods. This enforces that all derived classes must implement every function, achieving full control abstraction.

> 📝 **NOTE** → "A class with only virtual functions can be instantiated, but if it contains at least one pure virtual function, it becomes an abstract class and **cannot** be instantiated."

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

#### Ambiguity in Inheritance

> Ambiguity occurs when the compiler cannot determine which base class member to access.

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

---

#### 2. Runtime Polymorphism

> The function call in runtime polymorphism is resolved at runtime in contrast with compile time polymorphism, where the compiler determines which function call to bind at compilation (compile time).  
> Also known as **late binding** and **dynamic polymorphism**.  
> Runtime polymorphism is implemented using **function overriding** with **virtual functions**.

**Function Overriding**
> Function Overriding occurs when a derived class defines one or more member functions of the base class. That base function is said to be overridden. The base class function must be declared as virtual function for runtime polymorphism to happen.

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

👉 A virtual destructor does **NOT** call the derived constructor.  
It ensures the derived destructor is called when deleting through a base pointer.

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

---

## Friend Class and Function

> In C++, friend functions and friend classes are concepts that allow certain functions or classes to access the private and protected members of another class.

### Friend Class

> A friend class can access private and protected members of other classes in which it is declared as a friend.

- Remember one thing, **friendship is not mutual**. If class A is a friend of B, then B doesn't become a friend of A automatically.
- We can declare a friend class in C++ by using the `friend` keyword.

### Friend Function

> Like friend classes, a friend function can be granted special access to private and protected members of a class in C++. They are not the member functions of the class but can access and manipulate the private and protected members of that class for they are declared as friends.

#### 1. Global Function as Friend Function

> We can declare any global function as a friend function. The keyword `"friend"` is placed only in the function declaration of the friend function and not in the function definition or call.

#### 2. Member Function of Another Class as Friend Function

> We can also declare a member function of another class as a friend function in C++. Forward declaration (friend class should declare before using it as a friend) of the class is needed if we want to make a member function of another class a friend inside that class.

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

---

## Shallow Copy

> In shallow copy, all variable values are copied, but **dynamically allocated memory addresses are shared** between objects.  
> Both objects point to the same heap memory, so changes made through one object affect the other.

## Deep Copy

> In deep copy, a new object is created by copying all variable values and allocating **separate memory** for dynamically allocated variables.  
> Both the original and copied objects store their data in different memory locations.  
> Changes made to one object do not affect the other because a custom copy constructor is used.

---

## Copy Constructor

> A copy constructor is a special type of constructor used to create a new object using an existing object of the same class.

### Default Copy Constructor

> Compiler creates a default copy constructor if there is no user defined constructor. This compiler created constructor does a **shallow copy** and works well for basic types, but does not work for dynamic allocated memory.

→ Default copy constructor (shallow copy) can lead to **dangling pointer** problems, especially when your class owns dynamic memory.

### User Defined Copy Constructor

> C++ also allows programmers to create their own version of copy constructor known as **user defined** or **explicit copy constructor**.

→ If a class has pointers or runtime resources (like dynamic memory), a custom copy constructor is needed. Otherwise, deletion of one object might cause deletion of an unrelated object members.

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

---

#### 2. `unique_ptr`

`unique_ptr` stores one pointer only at a time. We cannot copy `unique_ptr`, only transfer ownership of the object to another `unique_ptr` using the `move()` method.

---

#### 3. `shared_ptr`

`shared_ptr` allows multiple pointers to share ownership of the same object. It uses **reference counting** to manage memory.

- It maintains reference counting ownership of its contained pointer in cooperation with all copies of the `shared_ptr`.
- An object referenced by the contained raw pointer will be destroyed when and only when **all copies** of the `shared_ptr` have been destroyed.

---

#### 4. `weak_ptr`

`weak_ptr` is a non-owning smart pointer used with `shared_ptr` to prevent circular dependencies.

**Key Characteristics:**
- Does not increase reference count
- Prevents circular dependency
- Must be converted using `lock()` before use

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