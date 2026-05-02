#include <iostream>
using namespace std;

class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    ~Demo() {
        delete data;
        cout << "Destructor called\n";
    }
};

int main() {
    Demo obj1(10);

    Demo obj2 = obj1;   // ❌ default copy constructor (shallow copy)

    return 0;
}