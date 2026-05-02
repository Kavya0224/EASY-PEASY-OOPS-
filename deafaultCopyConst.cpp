#include <iostream>
using namespace std;

// Create a demo class
class A
{
  public:
    int x;
};

int main()
{

    // Creating an a1 object
    A a1;
    a1.x = 10;
    cout << "a1's x = " << a1.x << endl;

    // Creating another object using a1
    A a2(a1);
    cout << "a2's x = " << a2.x;

    return 0;
}

Output--------------------------------
a1's x = 10
a2's x = 10