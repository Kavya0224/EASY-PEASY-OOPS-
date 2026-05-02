# 📘 Object-Oriented Programming in C++ — Complete Notes

---

## 📌 Table of Contents

- [OOP Overview](#oop-overview)
- [Access Modifiers](#access-modifiers)
- [Constructors & Destructors](#constructors--destructors)
- [this Pointer](#this-pointer)
- [Static Members](#static-members)
- [Four Pillars of OOP](#four-pillars-of-oop)
  - [Encapsulation](#1-encapsulation)
  - [Abstraction](#2-abstraction)
  - [Inheritance](#3-inheritance)
  - [Polymorphism](#4-polymorphism)
- [Virtual Functions](#virtual-functions)
- [Friend Class and Function](#friend-class-and-function)
- [Copy Constructor & Assignment Operator](#copy-constructor--assignment-operator)
- [Shallow Copy vs Deep Copy](#shallow-copy-vs-deep-copy)
- [Memory Management](#memory-management)
- [Rule of 3 / 5 / 0](#rule-of-3--5--0)
- [Smart Pointers](#smart-pointers)
- [Move Semantics](#move-semantics)
- [Templates](#templates-generic-programming)
- [Exception Handling](#exception-handling)

---

## OOP Overview

> **OOP (Object-Oriented Programming)** is a programming paradigm that revolves around the concept of **"OBJECTS"**.

### Why OOP?

- Helps users understand software without knowing actual implementation
- Increases **readability**, **understandability**, and **maintainability**
- Even very large software can be written and managed easily

### OOP vs POP

| Aspect | POP (Procedure-Oriented) | OOP (Object-Oriented) |
|--------|--------------------------|------------------------|
| Focus  | Functions/Procedures     | Objects (data + behavior) |
| Core Question | "How to do?" | "Who does it?" |

### Advantages of OOP over POP

- Reusable components via objects and classes → less duplication
- Clear and logical structure → easier to understand, maintain, and debug

---

### Class

> A **class** is a user-defined blueprint from which objects are created. It represents the set of properties or methods common to all objects of one type.

### Object

> **Objects** are real-world instances of a class, containing the characteristics and behaviors specified in the class template.

---

## Access Modifiers

> Access modifiers are special keywords in C++ that control the **visibility** of class members (data and functions).

### `public`
- Accessible from **anywhere** in the program
- ✅ Used to define the **interface** of a class; functions users should call

### `private`
- Accessible **only within the same class**
- ✅ Used for **data hiding (encapsulation)**, protecting sensitive data, preventing invalid modifications

### `protected`
- Accessible within the **same class** and **derived (child) classes**
- ❌ Not accessible outside the class
- ✅ Used in **inheritance** — allows child classes to reuse and modify data safely
- Example: a manager can set the salary of an employee

---

## Constructors & Destructors

### Constructor

> A **constructor** is a special member function that is automatically called when an object is created, used to initialize data members.

**Key Properties:**
- Same name as the class
- No return type
- Called automatically

#### Types of Constructors

| Type | Description | Example |
|------|-------------|---------|
| Default Constructor | Takes no arguments | `Student()` |
| Parameterized Constructor | Accepts arguments to initialize values | `Student(int a)` |

**Constructor Overloading:**
- Multiple constructors in the same class with different parameters
- Example of **compile-time polymorphism**

---

### Destructor

> A **destructor** is a special member function that is automatically called when an object is destroyed, used to free resources / clean up.

**Key Properties:**
- Same name as the class, prefixed with `~`
- No return type and no parameters
- Called automatically when object is destroyed

> ⚠️ An **empty destructor** = same as no destructor or default destructor.
> C++ does **not** automatically delete heap memory (`new`) like it does for stack objects.

#### When is the Destructor Called?

**1. Stack Allocation (Recommended ✅) — when object goes out of scope:**
```cpp
void func() {
    Student s;  // constructor called
}               // destructor called here
```

**2. Heap Allocation — when `delete` is used:**
```cpp
Student* s = new Student();
delete s;  // destructor called here
```

> 💡 If you create objects with `new`, you **must** `delete` them to free memory and run cleanup code. Otherwise you risk **memory leaks** and unfinished resource handling.

---

## `this` Pointer

> `this` is a pointer that points to the **current object** of the class.

```cpp
this->x = x;
// this->x  → refers to class member
// x        → refers to parameter
```

---

## Static Members

> **Static members** belong to the **class itself**, not to individual objects.
> `"static"` means **shared across all objects** of a class.

### Static Variables
- Shared by **all objects**
- Only **one copy** in memory
- Belongs to the class, not individual objects

### Static Functions
- Belongs to the **class**, not objects
- Can be called **without creating an object**
- Can access **only static members**

---

### Scope Resolution Operator `::`

> Used to tell the compiler **which scope** (class, function, global, namespace) you are referring to.

```
Think of it as: "Go inside this scope and pick that specific thing."
```

---

## Four Pillars of OOP

---

### 1. Encapsulation

> **Encapsulation** is the process of wrapping data members and member functions into a single unit (class) and restricting direct access to some of its components. It acts as a **protective shield** for the data.

#### Implementation in C++

| Step | Description |
|------|-------------|
| Declare variables as `private` | Keep data members private so they cannot be accessed directly from outside |
| Use getters and setters | Provide `public` functions to access and modify private variables safely |
| Apply proper access specifiers | `private` for data members, `public` for controlled access functions |

#### Advantages
- Data Hiding
- Improved Maintainability
- Enhanced Security
- Code Reusability
- Better Modularity

---

### 2. Abstraction

> **Abstraction** is the process of **hiding implementation details** and showing only the essential features to the user. Focus on *what* an object does rather than *how* it does it.

#### Abstract Class
- **Cannot be instantiated** (no objects can be created directly)
- Contains **at least one pure virtual function**

#### Full Abstraction — Interfaces
- A class acting as an **interface** contains **only pure virtual functions** and no data members or implemented methods
- Enforces that all derived classes must implement every function

> 📝 **Note:** "A class with only virtual functions *can* be instantiated, but if it contains at least one **pure virtual function**, it becomes an abstract class and **cannot** be instantiated."

#### Abstraction vs Encapsulation

| Concept | Definition |
|---------|------------|
| **Encapsulation** | Wrapping data and methods together and restricting direct access using access modifiers |
| **Abstraction** | Hiding implementation details and showing only essential features to the user |

---

### 3. Inheritance

> **Inheritance** is a mechanism where a derived class acquires the properties and behaviors of a base class, forming an **"is-a"** relationship. Enables **code reusability**.

#### Types of Inheritance

| Type | Description |
|------|-------------|
| **Single** | A sub-class is derived from only one super class |
| **Multiple** | One class inherits from more than one super class |
| **Multilevel** | A class is derived from another derived class, forming a chain |
| **Hierarchical** | More than one subclass is derived from a single base class |
| **Hybrid** | Combination of two or more types of inheritance |

> 📝 **Note (Multilevel):** When a derived class object is created, only one object is formed, but it contains base class subobjects. Constructors of base classes are called to initialize those parts, not to create separate objects.

---

#### Diamond Problem

> Hybrid inheritance can lead to the **diamond problem** — when a class inherits from two classes that both share the same base class, resulting in **multiple copies** of the base class members and **ambiguity**.

```
        Base
        /   \
     Par1   Par2
        \   /
        Child
```

**Without virtual inheritance** — multiple copies of base class:
```
D object
 ├── B part
 │     └── A (copy 1)
 ├── C part
       └── A (copy 2)
```

**With virtual inheritance** — single shared base class:
```
D object
 ├── B part
 ├── C part
 └── ONE shared A (virtual base)
```

> ✅ **Solution:** Use **virtual inheritance** — a C++ technique to avoid multiple copies of the base class into children/derived classes. Ensures only one shared instance of the base class exists, regardless of how many times it is inherited.

#### Ambiguity in Inheritance
> Occurs when the compiler **cannot determine** which base class member to access.

---

#### Advantages & Disadvantages of Inheritance

| Advantages | Disadvantages |
|------------|---------------|
| Code Reusability | Tight Coupling |
| Abstraction | Reduced Flexibility |
| Class Hierarchy | Increased Complexity |
| Polymorphism | Diamond Problem |
| — | Overhead of Virtual Functions |

---

#### Function Hiding

> When a derived class defines a function with the **same name** as in the base class, the base class function gets **hidden**, even if signatures are different.

---

### 4. Polymorphism

> **Polymorphism** means having many forms. A single function name or operator can work differently in different situations.

```
                           Polymorphism
                                |
                 --------------------------------
                 |                              |
           Compile-Time                     Runtime
           /          \                        |
 Func Overloading   Operator Overloading   Func Overriding
```

---

#### Compile-Time Polymorphism
> Also known as **early binding** and **static polymorphism**. The compiler determines how a function or operator will work depending on the context.

**Function Overloading:**
- Two or more functions can have the **same name** but behave differently for different parameters

**Operator Overloading:**
- Provides operators with a special meaning for a particular data type
- Example: we can use `+` for strings to concatenate and for integers to add
- `<<` and `>>` are binary shift operators but also work with input/output streams — possible due to operator overloading

---

#### Runtime Polymorphism
> Also known as **late binding** and **dynamic polymorphism**. The function call is resolved at **runtime**.
> Implemented using **function overriding** with **virtual functions**.

**Function Overriding:**
- A derived class defines a member function that exists in the base class
- The base class function must be declared as `virtual` for runtime polymorphism

---

#### How C++ Resolves Functions at Runtime (Important ⭐)

> "In runtime polymorphism, C++ uses virtual functions to decide which function to call at runtime. Internally, the compiler creates a **vtable** (virtual table) for each class containing virtual functions. Each object has a hidden pointer called **vptr** (virtual pointer) that points to the vtable of its actual class. When we call a function using a base class pointer, the program looks at the object's `vptr` at runtime, finds the correct function in the vtable, and calls it. So even if the pointer is of type base class, the function of the actual object type is executed."

| Concept | Description |
|---------|-------------|
| `vtable` | A table of function pointers, maintained **per class** |
| `vptr` | A pointer to vtable, maintained **per object instance** |

> 📝 **Note:** A derived class pointer **cannot** point to a base object because the base object doesn't contain the derived part — this would lead to unsafe memory access.

---

## Virtual Functions

### Virtual Function
> A member function declared with the `virtual` keyword in a base class and re-defined (overridden) in the derived class. Enables **runtime polymorphism** via a base class pointer or reference.

### Virtual Destructor
> Deleting a derived class object using a **base class pointer** with a **non-virtual destructor** results in undefined behavior.

```cpp
// Fix: declare base class destructor as virtual
virtual ~BaseClass();
```

> 📝 A virtual destructor does **NOT** call the derived constructor — it ensures the **derived destructor is called** when deleting through a base pointer.

### Pure Virtual Function
> A function in a base class with `= 0` and no body, which **must** be overridden in derived classes. A class with such a function is called **abstract** and cannot be instantiated.

---

### Binding

> **Binding** decides which function gets executed based on context (type of object or function signature).

| Type | When | Speed |
|------|------|-------|
| **Early Binding** | Resolved at **compile time** | Faster |
| **Late Binding** | Resolved at **runtime** via virtual functions | Slower |

### Limitations of Virtual Functions
- Slower execution
- Difficult to debug

---

## Friend Class and Function

> `friend` allows certain functions or classes to access the **private and protected members** of another class.

> ⚠️ **Friendship is not mutual.** If class A is a friend of B, then B doesn't automatically become a friend of A.

### Friend Class
```cpp
class B {
    friend class A;  // A can access B's private members
};
```

### Friend Function
- Not a member function of the class
- Can access and manipulate private and protected members
- `friend` keyword placed **only in the declaration**, not in the definition or call

#### Types

**1. Global Function as Friend Function:**
```cpp
class MyClass {
    friend void display(MyClass obj);  // declaration only
};
```

**2. Member Function of Another Class as Friend:**
- We can declare a member function of another class as a friend function in C++
- **Forward declaration** of the class is needed if we want to make a member function of another class a friend inside that class

---

### Friend — Advantages vs Disadvantages

| Advantages | Disadvantages |
|------------|---------------|
| Access private/protected members without inheritance | Violates data hiding by exposing private members |
| Can be declared in any access section | Breaks encapsulation when overused |
| Useful for operator overloading | Does not support runtime polymorphism |
| — | Friendship is not inherited by derived classes |

---

## Copy Constructor & Assignment Operator

### Copy Constructor
> A special constructor used to create a **new object** using an existing object of the same class.

#### Default Copy Constructor
- Created by compiler if no user-defined constructor exists
- Performs **shallow copy**
- Works well for basic types, but **not for dynamically allocated memory**
- Can lead to **dangling pointer** problems

#### User-Defined Copy Constructor
- Needed when a class has pointers or runtime resources (dynamic memory)
- Performs **deep copy**

```cpp
// Without a custom copy constructor, shallow copy can lead to
// dangling pointers or resource conflicts
```

#### Need for User-Defined Copy Constructor
- Default → shallow copy → copies pointer values, not actual resources
- Without custom copy constructor → deletion of one object might cause deletion of another object's members

---

### Copy Assignment Operator
> Used to **assign one existing object to another**.

```cpp
ClassName& operator=(const ClassName& other);
```

```cpp
A obj1(10);
A obj2(20);
obj2 = obj1;   // assignment operator called
```

**Example:**
```cpp
class A {
public:
    int x;

    A(int val) { x = val; }

    A& operator=(const A& other) {
        x = other.x;
        return *this;  // this  → pointer to the current object
                       // *this → dereferencing the pointer → gives the actual object itself
    }
};
```

---

### Copy Constructor vs Assignment Operator

| Aspect | Copy Constructor | Assignment Operator |
|--------|-----------------|---------------------|
| Purpose | Creates a **new object** | Reuses an **existing object** |
| Memory | Allocates new memory | May reuse or reallocate memory |

---

### Copy Elision
> Also known as **copy omission** — a compiler optimization that **prevents objects from being duplicated or copied**.
>
> The compiler prevents extra copies using:
> - **RVO** (Return Value Optimization)
> - **NRVO** (Named Return Value Optimization)
>
> Results in saving space and better program complexity (both time and space) — making the code more optimized.

---

## Shallow Copy vs Deep Copy

### Shallow Copy
- All variable values are copied, but **dynamically allocated memory addresses are shared**
- Both objects point to the **same heap memory**
- Changes through one object **affect the other**

### Deep Copy
- A **new object** is created with **separate memory allocation**
- Original and copied objects store data in **different memory locations**
- Changes to one object do **not affect** the other
- Requires a **custom copy constructor**

---

### Dangling Pointer
> A pointer pointing to a **memory location that has been deleted (or freed)** is called a dangling pointer. Leads to unexpected behavior.

---

## Memory Management

### 1. Stack vs Heap

| Feature | Stack | Heap |
|---------|-------|------|
| Management | Automatic | Manual |
| Speed | Fast | Slower |
| Size | Limited | Large |
| Lifetime | Ends when function ends | Until you `delete` it |
| Stores | Local variables, function calls | Dynamic allocations |

```cpp
// Stack
void func() {
    int x = 10;  // stored in stack, destroyed automatically
}

// Heap
int* p = new int(10);  // stored in heap, stays until deleted
```

---

### 2. `new` and `delete`

**`new`** — Allocates memory on heap, returns pointer:
```cpp
int* p = new int(5);
```

**`delete`** — Frees heap memory:
```cpp
delete p;
```

**Arrays:**
```cpp
int* arr = new int[5];
delete[] arr;  // IMPORTANT: use delete[] for arrays
```

> ⚠️ Using `delete` instead of `delete[]` for arrays = **undefined behavior**

---

### 3. Memory Leak

> **Memory leak** = used memory that is **never freed**.
> Memory allocated but never released, even after it's no longer needed.

```cpp
void func() {
    int* p = new int(10);
    // forgot delete → memory stays occupied even after function ends
}
```

**Why dangerous?**
- Wastes memory
- Can crash long-running programs
- Common in large systems

```cpp
// Fix
delete p;
```

> 💡 **Interview Tip:** Mention "Use smart pointers like `unique_ptr` to avoid leaks"

---

### 4. Dangling Pointer

```cpp
// ❌ Example 1 — accessing freed memory
int* p = new int(10);
delete p;
cout << *p;  // dangling pointer

// ❌ Example 2 — returning stack address
int* func() {
    int x = 10;
    return &x;  // pointing to stack memory, not heap
}

// ✅ Fix
delete p;
p = nullptr;  // safe
```

**Why dangerous?**
- Undefined behavior
- Random crashes
- Hard to debug

---

## Rule of 3 / 5 / 0

### Rule of 3 (Classic C++)

> If your class manages **dynamic memory (heap)**, you must define these **3**:

1. **Destructor**
2. **Copy Constructor**
3. **Copy Assignment Operator**

**Why?** Default versions do shallow copy, causing:
- ❌ Double delete
- ❌ Dangling pointers
- ❌ Memory leaks

---

### Rule of 5 (Modern C++)

> C++11 added **move semantics**, so now we have **5** functions:

1. Destructor
2. Copy Constructor
3. Copy Assignment
4. **Move Constructor**
5. **Move Assignment**

> 💡 Move semantics avoid unnecessary copying and improve performance — "steal" the resource instead of duplicating it.

---

### Rule of 0 (Advanced)

> **Avoid manual memory management entirely.** Use:
> - `std::vector`
> - `std::string`
> - Smart pointers
>
> Then you don't need Rule of 3 or 5 at all.

> ⭐ **Interview Insight:** If you define **any one** of these → you likely need all others. But in modern C++: **Prefer Rule of 0**.

---

## Smart Pointers

> A **smart pointer** is a class that wraps a raw pointer and **automatically manages the lifetime** of dynamically allocated memory.

- Prevents **memory leaks** and **dangling pointers**
- Defined in `<memory>` header: `#include <memory>`

### Types

#### 1. `auto_ptr` *(Deprecated — removed in C++17)*
- Early smart pointer that auto-deleted the managed object when out of scope

#### 2. `unique_ptr`
- Stores **one pointer only** at a time
- **Cannot be copied** — only ownership can be transferred using `move()`

#### 3. `shared_ptr`
- Allows **multiple pointers** to share ownership of the same object
- Uses **reference counting** to manage memory
- Maintains reference counting ownership in cooperation with all copies of the `shared_ptr`
- Object is destroyed **only when all copies** of the `shared_ptr` are destroyed

#### 4. `weak_ptr`
- **Non-owning** smart pointer used with `shared_ptr` to prevent circular dependencies
- Does **not** increase reference count
- Must be converted using `lock()` before use

---

### Problems with Normal Pointers

| Problem | Description |
|---------|-------------|
| **Memory Leaks** | Memory repeatedly allocated but never freed → excessive memory consumption → system crash |
| **Wild Pointers** | A pointer never initialized with a valid object or address |
| **Dangling Pointers** | A pointer referring to memory that was deallocated earlier |

---

### Pointers vs Smart Pointers

| Pointer | Smart Pointer |
|---------|---------------|
| A variable that maintains a memory address and data type info | A class that wraps a pointer (scoped pointer) |
| Not destroyed when it goes out of scope | Destroys itself when it goes out of scope |

---

## Move Semantics

### Why Move Semantics?

| Era | Behavior |
|-----|----------|
| Before C++11 | Objects were copied — copying large objects = slow + extra memory |
| After C++11 | Resources can be **moved** instead of copied — transfer ownership |

> 🔥 **Analogy:**
> - **Copy** → photocopy a book 📚 (expensive)
> - **Move** → hand over the book (cheap)

### Move Concept (Simple Idea)
> Instead of copying memory → **"Steal" the resource**

---

### lvalue vs rvalue

| Type | Description | Example |
|------|-------------|---------|
| **lvalue** | Has a name, exists in memory | `int x = 10;` — `x` is lvalue |
| **rvalue** | Temporary value, no name | `10 + 20` is rvalue |

---

### rvalue Reference (`&&`)

```cpp
int &x = 10;    // ❌ ERROR
int &&r = 10;   // ✅ rvalue reference
```

> 👉 It can bind to **temporary objects (rvalues)**

| Reference | Binds to |
|-----------|----------|
| `int&` | lvalues only |
| `int&&` | rvalues only |

**Real Use Case:**
```cpp
void process(int &&x) {
    cout << "rvalue received\n";
}

process(10);  // calls this (rvalue)
```

**Compare with lvalue version:**
```cpp
void process(int &x) {
    cout << "lvalue received\n";
}

int a = 5;
process(a);  // lvalue version
```

---

### Why Move is Needed

```cpp
// Without move — full duplication (expensive)
vector<int> v1 = {1,2,3,4,5};
vector<int> v2 = v1;  // COPY

// With move — internal data transferred (cheap)
vector<int> v2 = move(v1);  // MOVE
```

---

### `std::move`

> `std::move(x)` converts an **lvalue into rvalue**.

> ⚠️ **Important:** It does **NOT** move anything by itself — it just **enables** the move.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = std::move(v1);
    cout << v1.size();  // usually 0 (moved-from state)
}
```

---

### Move Constructor

```cpp
class Demo {
    int* data;

public:
    Demo(int val) {
        data = new int(val);
    }

    // Move Constructor
    Demo(Demo&& other) {
        data = other.data;      // transfer pointer
        other.data = nullptr;   // avoid double delete
    }

    ~Demo() {
        delete data;
    }
};
```

> Ownership of memory is **transferred** — old object becomes **empty / safe state**.

---

### Move Assignment Operator

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

### When Move Happens Automatically

- Returning objects from functions
- Using `std::move`
- Temporary objects

```cpp
Demo create() {
    Demo d(10);
    return d;  // move happens
}
```

---

## Templates (Generic Programming)

> **Generic programming** is a way of writing code that works with **any data type**, instead of being limited to one specific type.

### Problem Without Templates

```cpp
int add(int a, int b);
double add(double a, double b);
// Repetition ❌
```

### Template Solution

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Usage
cout << add(2, 3);       // int
cout << add(2.5, 3.1);   // double
```

> 💡 **Key Idea:** Write code **once**, use with **any data type**.

---

## Exception Handling

### Why Needed?
- To handle **runtime errors** safely
- Without it → program **crashes** ❌

### Basic Keywords

| Keyword | Purpose |
|---------|---------|
| `try` | Code that may cause an error |
| `throw` | Raise the error |
| `catch` | Handle the error |

### Basic Example

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

**Flow:**
1. `try` block runs
2. Error occurs → `throw`
3. Control jumps to `catch`

---

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

---

*End of Notes*