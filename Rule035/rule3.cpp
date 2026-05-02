// Problem Example (Shallow Copy Issue)
class Demo {
public:
    int* data;

    Demo(int val) {
        data = new int(val);
    }

    ~Demo() {
        delete data;
    }
};
Demo d1(10);
Demo d2 = d1; // shallow copy

//  Now both d1.data and d2.data point to SAME memory
//  Destructor runs twice → crash (double delete)

=========================================================================================================

// Fix (Rule of 3 Applied)
class Demo {
public:
    int* data;

    // Constructor
    Demo(int val) {
        data = new int(val);
    }

    // Copy Constructor
    Demo(const Demo& other) {
        data = new int(*other.data); // deep copy
    }

    // Copy Assignment Operator
    // this → address of current object (d1) (i.e. d1=d2)
    // &other → address of RHS object (d2)
    Demo& operator=(const Demo& other) {
        if (this != &other) {                   //  Checks self-assignmen i.e. d1 = d1;
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Destructor
    ~Demo() {
        delete data;
    }
};