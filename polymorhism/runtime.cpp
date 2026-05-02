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