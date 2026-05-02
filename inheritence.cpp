#include <iostream>
using namespace std;

class Animal
{
  public:
    void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

// “In private inheritance, all public and protected members of the base class become private in the derived class, so they cannot be accessed from outside the derived class.”
/* 

class Animal {
public:
    void sound() {
        cout << "Animal sound";
    }
};

class Dog : private Animal {    NOTE => ( but if we define sound here then it will work fine like we have done below )
};                                      ( same holds in case of virtual func case )

int main() {
    Dog d;
    d.sound();   // ❌ ERROR
}

*/
class Dog : public Animal
{
  public:
    void sound()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
  public:
    void sound()
    {
        cout << "Cat meows" << endl;
    }
};

class Cow : public Animal
{
  public:
    void sound()
    {
        cout << "Cow moos" << endl;
    }
};

int main()
{
    Animal a;
    a.sound();
    
    Dog d;
    d.sound();

    Cat c;
    c.sound();

    Cow cow;
    cow.sound();

    return 0;
}

===========================================================================================================
// Single inheritence ----------------------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "This is a Vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "This Vehicle is Car" << endl;
    }
};

int main() {
   
    Car obj;
    return 0;
}
Output
This is a Vehicle
This Vehicle is Car

==============================================================================================================
//Multiple Inheritence -----------------------------------------------------------------
#include <iostream>
using namespace std;

class LandVehicle
{
  public:
    void landInfo()
    {
        cout << "This is a LandVehicle" << endl;
    }
};

class WaterVehicle
{
  public:
    void waterInfo()
    {
        cout << "This is a WaterVehicle" << endl;
    }
};

// Derived class inheriting from both base classes
class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
  public:
    AmphibiousVehicle()
    {
        cout << "This is an AmphibiousVehicle" << endl;
    }
};

int main()
{
    AmphibiousVehicle obj;

    obj.waterInfo();
    obj.landInfo();

    return 0;
}
Output
This is an AmphibiousVehicle
This is a WaterVehicle
This is a LandVehicle

============================================================================================================
//MultiLevel Inheritence ----------------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle
{
  public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// Derived class from Vehicle
class FourWheeler : public Vehicle
{
  public:
    FourWheeler()
    {
        cout << "4 Wheeler Vehicles" << endl;
    }
};

// Derived class from FourWheeler
class Car : public FourWheeler
{
  public:
    Car()
    {
        cout << "This 4 Wheeler Vehicle is a Car" << endl;
    }
};

int main()
{
    Car obj;
    return 0;
}
Output
This is a Vehicle
4 Wheeler Vehicles
This 4 Wheeler Vehicle is a Car

// Another example using parameterized constructor ---------------------------------------
#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;

public:
    // parameterized constructor
    Vehicle(int s) {
        speed = s;
        cout << "Vehicle constructor called\n";
    }
};

class FourWheeler : public Vehicle {
protected:
    int wheels;

public:
    // passes value to Vehicle constructor
    FourWheeler(int s, int w) : Vehicle(s) {
        wheels = w;
        cout << "FourWheeler constructor called\n";
    }
};

class Car : public FourWheeler {
public:
    // passes values to FourWheeler constructor
    Car(int s, int w) : FourWheeler(s, w) {
        cout << "Car constructor called\n";
    }

    void show() {
        cout << "Speed: " << speed << ", Wheels: " << wheels << endl;
    }
};

int main() {
    Car c(120, 4);
    c.show();
}

============================================================================================================
//Hybrid Inheritence -------------------------------------------------
#include <iostream>
using namespace std;

class Vehicle
{
  public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

class Fare
{
  public:
    Fare()
    {
        cout << "Fare of Vehicle" << endl;
    }
};

class Car : public Vehicle
{
  public:
    Car()
    {
        cout << "This Vehical is a Car" << endl;
    }
};

class Bus : public Vehicle, public Fare
{
  public:
    Bus()
    {
        cout << "This Vehicle is a Bus with Fare";
    }
};

int main()
{
    Bus obj2;
    return 0;
}
Output
This is a Vehicle
Fare of Vehicle
This Vehicle is a Bus with Fare