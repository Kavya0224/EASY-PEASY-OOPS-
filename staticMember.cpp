🔍 Key Points:
    Same variable used by all objects
    Access using:
    👉 ClassName::variable

// static variable
#include <iostream>
using namespace std;

class Demo {
public:
    static int count;

    Demo() {
        count++;
    }
};

int Demo::count = 0;   // definition outside class

int main() {
    Demo d1, d2, d3;
    cout << Demo::count;  // Output: 3
}

=====================================================================================================
}
🔍 Key Points
        Cannot use this pointer ❌
        Cannot access non-static members directly ❌
        Called using class name ✔

// static function
#include <iostream>
using namespace std;

class Demo {
public:
    static int count;

    static void show() {
        cout << count;
    }
};

int Demo::count = 10;

int main() {
    Demo::show();   // no object needed
}

========================================================================================================

A static function cannot access a non-static variable directly.
class Demo {
public:
    int x = 10;

    static void show() {
        cout << x;   // ❌ ERROR
    }
};

✅ How to Fix It

class Demo {
public:
    int x = 10;

    ✔️ Option 1: Pass object
    static void show(Demo d) {
        cout << d.x;   // ✔ works
    }
    
    ✔️ Option 2: Use pointer/reference
    static void show(Demo* d) {
        cout << d->x;
    }
};


int main() {
    Demo obj;
    Demo::show(obj);   // pass object
    Demo::show(&obj);   // pass address
}