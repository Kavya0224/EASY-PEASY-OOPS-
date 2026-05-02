#include <iostream>
using namespace std;

class A {
public:
    void print() { cout << "A" << endl; }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D d;
    d.B::print();
    d.C::print();
    return 0;
}

Output
A
A

Explanation
'A' defines the function "print()".
'B' and 'C' inherit "print()" from 'A'.
'D' inherits from both 'B' and 'C', causing ambiguity.
The ambiguity is resolved using scope resolution "(d.B::print() and d.C::print())".

=======================================================================================================
// Scope Resolution ----------------------------------
#include <iostream>
using namespace std;

int x = 100;   // global

int main() {
    int x = 50; // local

    cout << x << endl;    // 50 (local)
    cout << ::x << endl;   // 100 (global)
}