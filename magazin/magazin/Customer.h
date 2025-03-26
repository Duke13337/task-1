#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Product.h"
using namespace std;

class Customer {
private:
    string name;
    double balance;

public:
    Customer(const string& name, double balance);
    void addBalance(double amount);
    bool buyProduct(Product& product, int quantity);
    string getName() const;
    double getBalance() const;
};

#endif
