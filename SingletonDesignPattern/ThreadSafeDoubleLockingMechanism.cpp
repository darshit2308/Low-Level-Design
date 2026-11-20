#include<bits/stdc++.h>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
/*
Concept: 
Suppose 2 threads enter line-23, when no instance was declared, so, they both enter line 24, locks are initialised
and only 1 thread gets past line 26, now, after instance creation, the 2nd thread waiting on lock, is released, and
reaches line 28, and is rejected by 2nd if condition, that is why, 2 nested if conditions are present

*/ 
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx); // Lock for thread safety
            if(instance == nullptr){
                instance = new Singleton();
            }
        }
         return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}