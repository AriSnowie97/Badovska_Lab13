#include <iostream>
#include <string>
using namespace std;
class Discountable {
public:
    virtual double applyDiscount(double price) const = 0;
};

class Product : public Discountable {
protected:
    string name;
    double basePrice;

public:
    Product(const string& name, double price) : name(name), basePrice(price) {}
    string getName() const { return name; }
    double getBasePrice() const { return basePrice; }
    virtual double getFinalPrice() const {
        return applyDiscount(basePrice);
    }
};

class Book : public Product {
public:
    Book(const string& name, double price) : Product(name, price) {}
    double applyDiscount(double price) const override {
        return price * 0.9;
    }
};

class Pen : public Product {
public:
    Pen(const string& name, double price) : Product(name, price) {}
    double applyDiscount(double price) const override {
        return price > 5 ? price - 5 : price;
    }
};

int main() {
    Book book("Harry Potter", 200);
    Pen pen("Parker", 10);
    cout << "Product: " << book.getName() << ", Base price: " << book.getBasePrice()
              << ", Final price: " << book.getFinalPrice() << endl;
    cout << "Product: " << pen.getName() << ", Base price: " << pen.getBasePrice()
              << ", Final price: " << pen.getFinalPrice() << endl;
    return 0;
}
