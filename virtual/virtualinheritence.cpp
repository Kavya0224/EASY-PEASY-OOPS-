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