
#include <bits/stdc++.h>
using namespace std;

// ================= BURGERS =================

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic burger\n";
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard burger\n";
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium burger\n";
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic wheat burger\n";
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard wheat burger\n";
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium wheat burger\n";
    }
};

// ================= GARLIC BREADS =================

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() = default;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Garlic Bread\n";
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Cheese Garlic Bread\n";
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Garlic Bread\n";
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Cheese Wheat Garlic Bread\n";
    }
};

// ================= ABSTRACT FACTORY =================

class MealFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;

    virtual ~MealFactory() = default;
};

// ================= CONCRETE FACTORIES =================

class SinghBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic")
            return new BasicBurger();
        else if (type == "standard")
            return new StandardBurger();
        else if (type == "premium")
            return new PremiumBurger();

        cout << "Invalid burger type!\n";
        return nullptr;
    }

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic")
            return new BasicGarlicBread();
        else if (type == "cheese")
            return new CheeseGarlicBread();

        cout << "Invalid garlic bread type!\n";
        return nullptr;
    }
};

class KingBurger : public MealFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic")
            return new BasicWheatBurger();
        else if (type == "standard")
            return new StandardWheatBurger();
        else if (type == "premium")
            return new PremiumWheatBurger();

        cout << "Invalid burger type!\n";
        return nullptr;
    }

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic")
            return new BasicWheatGarlicBread();
        else if (type == "cheese")
            return new CheeseWheatGarlicBread();

        cout << "Invalid garlic bread type!\n";
        return nullptr;
    }
};

// ================= MAIN =================

int main() {
    string burgerType = "basic";
    string breadType = "cheese";

    MealFactory* myFactory = new KingBurger();

    Burger* burger = myFactory->createBurger(burgerType);
    GarlicBread* bread = myFactory->createGarlicBread(breadType);

    if (burger)
        burger->prepare();

    if (bread)
        bread->prepare();

    delete burger;
    delete bread;
    delete myFactory;

    return 0;
}
