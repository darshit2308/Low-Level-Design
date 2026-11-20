#include<iostream>
#include <mutex>

using namespace std;

class Singleton{
private:
    static Singleton* instance;

    Singleton(){
        cout << "Singleton constructor called" << endl;
    }

public:
    static Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton :: instance = new Singleton();// Here, just on start of the program, we initialised the instance with the object instead of nullptr.
// This code format is good only if object creation is not expensive, otheriwse in large codebase, since object creation is expensive, this is not good, since we dont know, if we would even use the object or not.


int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 != s2) << endl;
}