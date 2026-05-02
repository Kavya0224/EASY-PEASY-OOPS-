// CPP program without virtual destructor 
// causing undefined behavior
#include <iostream>

using namespace std;

class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    ~base()
    { cout<< "Destructing base\n"; }     
};

class derived: public base {
  public:
    derived()     
     { cout << "Constructing derived\n"; }
    ~derived()
       { cout << "Destructing derived\n"; }
};

int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
}

Output -------------------------------------
Constructing base
Constructing derived
Destructing base
=========================================================================
Making base class destructor virtual guarantees that the object of derived class is destructed properly,
i.e., both base class and derived class destructors are called. For example,
=========================================================================
// A program with virtual destructor
#include <iostream>

using namespace std;

class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }     
};

class derived : public base {
  public:
    derived()     
    { cout << "Constructing derived\n"; }
    ~derived()
    { cout << "Destructing derived\n"; }
};

int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
} 

Output -----------------------------------------------
Constructing base
Constructing derived
Destructing derived
Destructing base
=================================================================================================
“A virtual destructor ensures that when a base class pointer points to a derived object,
deleting it calls the derived class destructor first, followed by the base class destructor.
This prevents resource leaks and ensures proper cleanup.”
=================================================================================================