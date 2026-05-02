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