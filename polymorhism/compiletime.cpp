// Function Overloading ----------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Geeks {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }
};

int main() {
    Geeks gfg;
    
    // add() called with int values
    gfg.add(10, 2);

    // add() called with double value
    gfg.add(5.3, 6.2);

    return 0;
}

======================================================================================================
// Operator Overloading -----------------------------------------------
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) :
    real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real,
        imag + obj.imag);
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    
    // Adding c1 and c2 using + operator
    Complex c3 = c1 + c2;   // Its like Complex c3 = c1.operator+(c2);
    cout << c3.real << " + i" << c3.imag;
    return 0;
}
--------------------------------------------------------------------------
🔥 Think of Operator Overloading as Function Call Replacement

When you write:
Complex c3 = c1 + c2;
👉 It does NOT directly add objects
👉 It gets converted into a function call
 --------------------------------
| Complex c3 = c1.operator+(c2); |
 --------------------------------
So basically:
c1 → the object calling the function (this)
c2 → passed as parameter
operator+ → just a function name
---------------------------------------------------------------------------
// More simpler example of Operator overloading
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    // Constructor
    Box(int l) {
        length = l;
    }

    // Overload + operator
    Box operator + (Box b) {
        return Box(length + b.length);
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(10);
    Box b2(20);

    Box b3 = b1 + b2;  // operator+ gets called

    b3.display();
}