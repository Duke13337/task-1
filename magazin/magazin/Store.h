#ifndef STORE_H
#define STORE_H
#include "Product.h"
#include <vector>
using namespace std;

class Store {
private:
    string name;
    vector<Product> products;

public:
    Store(const string& name);
    void addProduct(const Product& product);
    Product* findProduct(const string& productName);
    string getName() const;
    void showProducts() const;
};

#endif
