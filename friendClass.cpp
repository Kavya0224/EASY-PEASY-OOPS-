#include <iostream>
using namespace std;

class Geeks {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Geeks() {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class GFG;
};

// class GFG is declared as a friend
// inside class Geeks, therefore
// Class GFG can access private members
// of class Geeks.
class GFG {
public:
    void display(Geeks t) {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable;
    }
};

int main() {
    Geeks g;
    GFG fri;
    fri.display(g);
    return 0;
}

Output --------------------------------------------------
The value of Private Variable = 10
The value of Protected Variable = 99

Note: We can declare friend class or function anywhere in the base class body whether
its private, protected or public block. It works all the same.