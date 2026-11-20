#include<bits/stdc++.h>
using namespace std;

class Singleton {
private:
    // normally each object has its own variables, but, static means,  Only one shared pointer exists for the entire class.
    // It is not created every time getInstance() is called.
    static Singleton* instance; // This variable will store one and only instance of the class.
// Actually not instance, but the memory address of the object.
// Making the constructor private prevents the external code from creating objects.
    Singleton() {
        cout << "Singleton constructor called" << endl;
    }
    // normally to call a function, we need to create an object, but by using static, we can call a function directly from the class.
    // No object needed to call the function.
public:
    static Singleton* getInstance() { // we will call this fucntion directly from the class.
        if(instance == nullptr){// In case of multithreading, if multiple threads execute this at the same time, then multiple instances might be created.
            instance = new Singleton() ;
        }
        return instance;
    }
    
};
Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}