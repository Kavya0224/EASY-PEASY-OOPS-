#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto_ptr<int> ptr1(new int(10));
    cout << *ptr1 << endl;

    auto_ptr<int> ptr2 = ptr1;  // ownership transfer
    cout << *ptr2;
    return 0;
}



Output
10
10

Key Points:---------------------------------------------------------------------------
Ownership is transferred, leaving the original pointer null (empty).
Copy semantics are unsafe and error-prone.

Note: auto_ptr is deprecated after C++11 and it remove after C++ version 17.
--------------------------------------------------------------------------------------