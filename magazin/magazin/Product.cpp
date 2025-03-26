#include "Product.h"

Product::Product(const string& name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

string Product::getName() const { return name; }

double Product::getPrice() const { return price; }

int Product::getQuantity() const { return quantity; }

void Product::setPrice(double price) { this->price = price; }

void Product::reduceQuantity(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
    }
}
