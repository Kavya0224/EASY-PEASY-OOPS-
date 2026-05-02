#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    int area() { return length * breadth; }
};

int main() {
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    unique_ptr<Rectangle> P2;
    P2 = move(P1);  // ownership transfer
     cout << P2->area();

    //cout<<P1->area();       //👉 is dereferencing a null pointer
                             //👉 leads to crash / undefined behavior
   
    return 0;
}


// Output-----------------
// 50
// 50
// -----------------------

// Key Points:--------------------------------------------------
// ->Only one unique_ptr can own an object at a time.
// ->Lightweight and efficient.
// ->Ideal for single ownership scenarios.
// -------------------------------------------------------------