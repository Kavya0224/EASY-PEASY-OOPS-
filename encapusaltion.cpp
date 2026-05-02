#include<bits/stdc++.h>
using namespace std;

class Person{
private:
    string name;
public:
    void setName(string name){
        this->name=name;
    }
    void getName(){
        cout<<name<<endl;
    }
};

int main(){
    Person p;
    p.setName("xyz");
    p.getName();
}