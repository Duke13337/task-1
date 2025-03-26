#include "Customer.h"

Customer::Customer(const string& name, double balance) : name(name), balance(balance) {}

void Customer::addBalance(double amount) { balance += amount; }

bool Customer::buyProduct(Product& product, int quantity) {
    double total = product.getPrice() * quantity;
    if (balance >= total && product.getQuantity() >= quantity) {
        balance -= total;
        product.reduceQuantity(quantity);
        return true;
    }
    return false;
}

string Customer::getName() const { return name; }

double Customer::getBalance() const { return balance; }
