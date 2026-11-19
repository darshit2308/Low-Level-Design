#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing Basic burger " << endl;
    }
};

class StandardBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing Standard burger " << endl;
    }
};

class PremiumBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing PRemium burger " << endl;
    }
};

class BasicWheatBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing Basic wheat burger " << endl;
    }
};

class StandardWheatBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing Standard wheat burger " << endl;
    }
};

class PremiumWheatBurger : public Burger
{
    void prepare() override
    {
        cout << "Preparing PRemium Wheat burger " << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(string &type) = 0; // return type of this function is another Burger
    virtual ~BurgerFactory() {}
};

class SinghBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "basic";

    BurgerFactory *myFactory = new KingBurger();

    Burger *burger = myFactory->createBurger(type);

    burger->prepare();

    return 0;
}