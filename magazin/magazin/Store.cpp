#include "Store.h"
#include <iostream>
using namespace std;

Store::Store(const string& name) : name(name) {}

void Store::addProduct(const Product& product) {
    products.push_back(product);
}

Product* Store::findProduct(const string& productName) {
    for (auto& product : products) {
        if (product.getName() == productName) {
            return &product;
        }
    }
    return nullptr;
}

string Store::getName() const { return name; }

void Store::showProducts() const {
    cout << "Товары в магазине " << name << ":\n";
    for (const auto& product : products) {
        cout << "- " << product.getName() << " ($" << product.getPrice() << ") Количество: " << product.getQuantity() << "\n";
    }
}
