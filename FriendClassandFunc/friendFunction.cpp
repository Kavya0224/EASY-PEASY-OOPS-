// Global Function as Friend Function ------------------------------------------------------
#include <iostream>
using namespace std;

class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }
    
    // Friend function declaration
    friend void friendFunction(base& obj);
};


// friend function definition
void friendFunction(base& obj) {
    cout << "Private Variable: " 
         << obj.private_variable << endl;
    cout << "Protected Variable: " 
         << obj.protected_variable;
}

int main() {
    base object1;
    friendFunction(object1);
    return 0;
}

Output ---------------------------
Private Variable: 10
Protected Variable: 99

==========================================================================================================

// Member Function of Another Class as Friend Function ------------------------------

#include <iostream>
using namespace std;

// Forward Declaration needed
class base;

// Another class in which function is declared
class GFG {
public:
    void GFG_Function(base& obj);  // declaration should be done before class and defination will done after 
};

// Base class declare a frined
// function of another class
class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }

    // Friend function declaration
    friend void GFG::GFG_Function(base&);
};

// Friend function definition
void GFG::GFG_Function(base& obj) {
    cout << "Private Variable: " << 
             obj.private_variable
         << endl;
    cout << "Protected Variable: " << 
             obj.protected_variable;
}

int main() {
    base object1;
    GFG object2;
    object2.GFG_Function(object1);

    return 0;
}

Output -------------------------
Private Variable: 10
Protected Variable: 99