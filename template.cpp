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