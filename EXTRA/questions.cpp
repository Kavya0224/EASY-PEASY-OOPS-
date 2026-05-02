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