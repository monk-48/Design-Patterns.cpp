#include <bits/stdc++.h>
using namespace std;

class CoffeBase {
    
    public:
    virtual int Price() = 0;
    virtual string Name() = 0;
    virtual ~CoffeBase() = default; 
};

class Expresso : public CoffeBase {
    public:
    int Price () override {
        return 100;
    }
    string Name () override {
        return "Expresso";
    }
};

class Americano : public CoffeBase {
    public:
    int Price () override {
        return 120;
    }
    
    string Name () override {
        return "Americano";
    }
};

class Toppings : public CoffeBase {
    
    
    public:
    
    CoffeBase* coffeBase;
    
    Toppings (CoffeBase* coffeBase) : coffeBase (coffeBase) {}
    
    virtual ~Toppings () {
        delete coffeBase;
    }
};


class sugar : public Toppings {
    
    public:
    
    sugar (CoffeBase *coffeBase) : Toppings (coffeBase) {}
    
    string Name () override {
        return coffeBase->Name() + " + sugar";
    }
    
    int Price () override {
        return coffeBase->Price() + 5;
    }
};

class milk : public Toppings {
    
    public:
    milk(CoffeBase *coffeBase) : Toppings(coffeBase){}
    
    string Name () override {
        return coffeBase->Name() + " + Milk";
    }
    
    int Price() override {
        return coffeBase->Price() + 15;
    }
};

int main() {
    CoffeBase *coffee = new sugar ( new Expresso());
    
    cout<<coffee->Price()<<" "<<coffee->Name()<<endl;
    
    coffee = new milk (coffee);
    
    cout<<coffee->Price()<<" "<<coffee->Name()<<endl;
    
    
    delete coffee;
}

