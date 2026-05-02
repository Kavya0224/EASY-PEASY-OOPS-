#include <bits/stdc++.h>
using namespace std;

/*
This draw() is public, but it has no implementation
It only tells: "Every shape must have a draw function"
It does not reveal how drawing happens

👉 That’s abstraction:

Interface (what) → visible (draw())
Implementation (how) → hidden in derived classes 
*/

// Abstract class
class Shape {
public:
    // Pure virtual function (no implementation)
    virtual void draw() = 0;

    // Concrete function
    void info() {
        cout << "This is a shape" << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

// Another derived class
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->info();
    s1->draw(); /* Here:
                You only know draw() exists
                You don’t know whether it prints, uses graphics, or anything else
                Even though draw() is public:
                   Its implementation is hidden behind the base class pointer 
            */

    s2->info();
    s2->draw();

    delete s1;
    delete s2;

    return 0;
}

=====================================================================================================

#include <iostream>
#include <string>
using namespace std;

// Abstract base class as there is a
// pure virtual method
class Shape{
protected:
    string color;

public:
    Shape(string color) : color(color){}

    // Abstract or Pure virtual method
    virtual double area() = 0;

    // Concrete method
    string getColor(){
        return color;
    }

    virtual ~Shape() {}
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double length, width;

public:
    /* 
        Rectangle(string color, double l, double w) {
            Shape(color);      ❌ temporary object
        }
        This creates a temporary object of type Shape/
        It is NOT connected to your Rectangle object
        It exists only for that line
        Then it is immediately destroyed
     */  
    Rectangle(string color, double length, double width) : Shape(color) { // right way
                                                
        this->length = length;
        this->width = width;
    }
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* s = new Rectangle("Yellow", 2, 4);

    cout<<"Rectangle color is "<<s->getColor()<<" and area is : "<<s->area()<<endl;
    return 0;
}

============================================================================================================

// Abstraction using access modifier

#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    double balance;  // hidden data

    // hidden internal logic
    void updateBalance(double amount) {
        balance += amount;
    }

public:
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // exposed interface
    void deposit(double amount) {
        updateBalance(amount);  // user doesn't know how it's done
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            updateBalance(-amount);
        } else {
            cout << "Insufficient balance\n";
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);

    acc.deposit(500);
    acc.withdraw(200);

    cout << "Balance: " << acc.getBalance() << endl;

    return 0;
}