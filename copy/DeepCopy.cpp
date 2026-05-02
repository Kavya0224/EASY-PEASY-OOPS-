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