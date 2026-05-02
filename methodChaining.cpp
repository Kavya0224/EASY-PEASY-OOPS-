Returning Object using this => To return current object
this keyword is used for method chaining

this is a pointer Used to:
        Access current object
        Resolve ambiguity
        Return current object

💡 Example (Method Chaining)
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }

    Demo* setX(int x) {
        this->x = x;
        return this;   // return current object
    }

    void show() {
        cout << x << endl;
    }
};

int main() {
    Demo d(10);
    d.setX(20)->show();  // chaining
}

=======================================================================================================

🔥 Better Version (Returning Reference)
class Demo {
    int x;
public:
    Demo(int x) {
        this->x = x;
    }

    Demo& setX(int x) {
        this->x = x;
        return *this;   // return object
    }
};

👉 Now you can do:

d.setX(10).setX(20);