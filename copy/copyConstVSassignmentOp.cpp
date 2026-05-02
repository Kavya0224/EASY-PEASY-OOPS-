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