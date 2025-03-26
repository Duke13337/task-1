#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;

public:
    Product(const string& name, double price, int quantity);
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setPrice(double price);
    void reduceQuantity(int amount);
};

#endif
