#include <iostream>
#include <string>
using namespace std;

class BakeryItem {
public:
    virtual void displayDetails() = 0; // Pure virtual function
    virtual double addDiscount() = 0;
};

class Donut : public BakeryItem {
private:
    string name;
    string flavor;
    double price;

public:
    Donut(string n, string f, double p) : name(n), flavor(f), price(p) {}

    void setName(string n) { name = n; }
    void setFlavor(string f) { flavor = f; }
    void setPrice(double p) { price = p; }


    string getName() { return name; }
    string getFlavor() { return flavor; }
    double getPrice() { return price; }

    void displayDetails() override {
        cout << "Name: " << name << ", Flavor: " << flavor << ", Price: $" << price << endl;
    }

    double addDiscount() override{

        return getPrice() * 0.8;


    }
};

class PremiumDonut : public Donut {
private:
    string topping;

public:
    PremiumDonut(string n, string f, double p, string t) : Donut(n, f, p), topping(t) {}

    string getTopping() { return topping; }
    void setTopping(string t) { topping = t; }

    void displayDetails() override {
        cout << "Name: " << getName() << ", Flavor: " << getFlavor() << ", Price: $" << getPrice() << ", Topping: " << topping << endl;
    }
        double addDiscount() override{

        return getPrice() * 0.8;


    }


};

int main() {
    Donut donut1("Glazed", "Sweet", 1.50);
    PremiumDonut donut2("Chocolate", "Sweet", 2.00, "Sprinkles");

    donut1.displayDetails();
    donut2.displayDetails();

    cout<< donut1.addDiscount();
    cout<< donut2.addDiscount();

    return 0;
}
