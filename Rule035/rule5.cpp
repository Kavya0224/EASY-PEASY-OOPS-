class Demo {
public:
    int* data;

    // Constructor
    Demo(int val) {
        data = new int(val);
    }

    // Copy Constructor
    Demo(const Demo& other) {
        data = new int(*other.data);
    }

    // Copy Assignment
    Demo& operator=(const Demo& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    /*
    Move Constructor:
   🧠 Idea:
    Instead of copying data, it transfers ownership (steals memory)
    */
    Demo(Demo&& other) {
        data = other.data;
        other.data = nullptr;
    }
    ---------------------------------------------------------------
    // how it is called ?
    // Demo d1(10);
    // Demo d2 = std::move(d1); // move constructor 

    // What happens?
    //   Before move:
    //   d1.data → [10]
      
    //   After move:
    //   d2.data → [10]
    //   d1.data → nullptr
    // 👉 No copy, just transfer → FAST
    ---------------------------------------------------------------
    
    // Move Assignment       // d2 = std::move(d1);
    Demo& operator=(Demo&& other) {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Demo() {
        delete data;
    }
};
------------------------------------------------------
// Why Move is Needed?
// ❌ Without move:
// Copy constructor → deep copy → slow
// ✅ With move:
// No new allocation
// No copying
// Just pointer transfer → very fast
-----------------------------------------------------

EXTRA: ----------------------------------------------
1. What is an lvalue?
🧠 Definition:
An lvalue is something that:
Has a name
Has a memory address
Can appear on the left side of =

✅ Examples:
int x = 10;  // x is lvalue
x = 20;      // valid
int y = x;   // x is lvalue

👉 x has identity (you can take its address: &x)
----------------------------------------------------
🔹 2. What is an rvalue?
🧠 Definition:
An rvalue is:
A temporary value
Has no persistent memory location
Cannot appear on left side of assignment

✅ Examples:
int x = 10;     // 10 is rvalue
int y = x + 5;  // (x + 5) is rvalue
x + 5 = 20; // ❌ invalid
--------------------------------------------------