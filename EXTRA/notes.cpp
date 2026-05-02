===================================================================================================================================
// When to use new and when to not use new

// 1. ClassName a; → Stack Allocation
class A {
public:
    int x;
};

int main() {
    A a;   // object on stack
}

✔ What happens:
    Object is created automatically on stack
    Constructor is called
    Destructor is automatically called when it goes out of scope

✅ Use this when:
    You don’t need the object beyond the current scope
    No need for manual memory control
    This is the preferred/default way

----------------------------------------------------------------------------------

// 2. new ClassName() → Heap Allocation

int main() {
    A* a = new A();  // object on heap
}

✔ What happens:
    Object is created on heap (dynamic memory)
    You get a pointer
    Destructor is NOT called automatically

👉 You must do:
        delete a;

------------------------------------------------------------------------------------------------------------------------------

⚠️ When should you use new?
->Use heap allocation only when you really need it:

✔ Common cases:
    Object size is large
    Lifetime should extend beyond scope
    Dynamic data structures (linked list, tree, graph)
    Polymorphism (runtime behavior)

Example:
A* a = new A();

-----------------------------------------------------------

❌ When NOT to use new
    Simple objects like your example
    Short-lived variables
    When you don’t want memory leaks

----------------------------------------------------------
🔥 Modern C++ Advice (IMPORTANT)

Avoid raw new → use smart pointers instead:
#include <memory>
unique_ptr<A> a = make_unique<A>();

✔ Automatically deletes memory
✔ No memory leaks
===============================================================================================================================