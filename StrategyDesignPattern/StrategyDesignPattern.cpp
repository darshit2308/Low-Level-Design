#include<bits/stdc++.h>
using namespace std;

class TalkableRobot{
public:
    virtual void talk() = 0; // pure virtual function, we use a virtual function, so it can be overrided
    virtual ~TalkableRobot(){} 
    // If the base class destructor is not virtual, deleting a derived class object through a base class pointer results in undefined behaviour.
    // otherwise, if the base class destructor is virtual, C++ invokes destructors in order, firstly the derived class destructor, then base class destructor.

    // If you are unable to undesrtand above concept, rememeber just this, if the class is going to support polymorphism, we must use virtual with the destructor to support all deletions compeletely,
};

class NormalTalk : public TalkableRobot {
public:
    void talk() override{
        cout << "Talking normally" << endl;
    }
};

class noTalk : public TalkableRobot {
public:
    void talk() override{
        cout << "Cannot talk" << endl;
    }
};


class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Robot walking normally" << endl;
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Cannot walk" << endl;
    }
};


class FlyableRobot{
public: 
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Robot walking normally" << endl;
    }
};


class NoFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Cannot Fly" << endl;
    }
};


// Base class
class Robot {
protected:
    WalkableRobot *walkBehaviour;
    TalkableRobot *TalkBehaviour;
    FlyableRobot *flyBehaviour;

public: 
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f ){
        this->walkBehaviour = w;
        this->TalkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        TalkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->fly();
    }

    virtual void projection() = 0; // This is the abstract method, for the subclass.
};

// Now we will create different types of robots
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion stats" << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};



int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new noTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}