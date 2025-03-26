#include <iostream>
#include <vector>
#include "Store.h"
#include "Customer.h"
using namespace std;

vector<Store> stores;
vector<Customer> customers;

void showMenu() {
    cout << "\n--- Store Management System ---\n";
    cout << "1. Добавить магазин\n";
    cout << "2. Просмотреть магазины\n";
    cout << "3. Добавить товар в магазин\n";
    cout << "4. Просмотреть товары в магазине\n";
    cout << "5. Зарегистрировать покупателя\n";
    cout << "6. Пополнить баланс покупателя\n";
    cout << "7. Купить товар\n";
    cout << "8. Выйти\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод! Попробуйте снова.\n";
            continue;
        }

        if (choice == 8) {
            cout << "Выход из программы...\n";
            break;
        }

        switch (choice) {
        case 1: {
            string storeName;
            cout << "Введите название магазина: ";
            cin.ignore();
            getline(cin, storeName);
            stores.emplace_back(storeName);
            cout << "Магазин добавлен!\n";
            break;
        }
        case 2:
            for (const auto& store : stores) {
                cout << "Названия магазинов:" << "\n";
                cout << store.getName() << "\n";
            }
            break;

        case 3: {
            string storeName, productName;
            double price;
            int quantity;
            cout << "Введите название магазина: ";
            cin.ignore();
            getline(cin, storeName);
            Product* product = nullptr;

            // Ищем магазин по названию
            for (auto& store : stores) {
                if (store.getName() == storeName) {
                    cout << "Введите название товара: ";
                    getline(cin, productName);
                    cout << "Введите цену товара: ";
                    cin >> price;
                    cout << "Введите количество товара: ";
                    cin >> quantity;
                    product = new Product(productName, price, quantity);
                    store.addProduct(*product);
                    cout << "Товар добавлен!\n";
                    break;
                }
            }

            if (!product) {
                cout << "Магазин не найден.\n";
            }
            break;
        }

        case 4: {
            string storeName;
            cout << "Введите название магазина: ";
            cin.ignore();
            getline(cin, storeName);
            for (const auto& store : stores) {
                if (store.getName() == storeName) {
                    store.showProducts();
                }
            }
            break;
        }

        case 5: {
            string customerName;
            double balance;
            cout << "Введите имя покупателя: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Введите баланс: ";
            while (!(cin >> balance) || balance < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неверный ввод! Введите положительное число.\n";
            }
            customers.emplace_back(customerName, balance);
            cout << "Покупатель зарегистрирован!\n";
            break;
        }

        case 6: { // Пополнение баланса покупателя
            string customerName;
            double amount;
            cout << "Введите имя покупателя: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Введите сумму для пополнения: ";
            while (!(cin >> amount) || amount <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неверный ввод! Введите положительное число.\n";
            }

            // Ищем покупателя по имени
            for (auto& customer : customers) {
                if (customer.getName() == customerName) {
                    customer.addBalance(amount); // Предполагается, что у класса Customer есть метод addBalance
                    cout << "Баланс пополнен на $" << amount << ". Новый баланс: $" << customer.getBalance() << "\n";
                    break;
                }
            }
            break;
        }

        case 7: {
            string customerName, storeName, productName;
            int quantity;
            cout << "Введите имя покупателя: ";
            cin.ignore();
            getline(cin, customerName);
            cout << "Введите название магазина: ";
            getline(cin, storeName);
            cout << "Введите название товара: ";
            getline(cin, productName);
            cout << "Введите количество товара: ";
            cin >> quantity;

            Customer* customer = nullptr;
            Store* store = nullptr;
            Product* product = nullptr;

            // Ищем покупателя по имени
            for (auto& c : customers) {
                if (c.getName() == customerName) {
                    customer = &c;
                    break;
                }
            }

            // Ищем магазин по имени
            for (auto& s : stores) {
                if (s.getName() == storeName) {
                    store = &s;
                    break;
                }
            }

            // Ищем товар в магазине
            if (store) {
                product = store->findProduct(productName);
            }

            if (customer && store && product) {
                if (customer->buyProduct(*product, quantity)) {
                    cout << "Покупка успешна!\n";
                }
                else {
                    cout << "Покупка не удалась. Проверьте баланс или количество товара.\n";
                }
            }
            else {
                cout << "Ошибка! Не удалось найти покупателя, магазин или товар.\n";
            }
            break;
        }

        default:
            cout << "Неверный выбор!\n";
        }
    }
    return 0;
}