#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    float price;
    int quantity;

    Product() {
        name = "";
        price = 0;
        quantity = 0;
    }

    Product(string n, float p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    float getTotalPrice() {
        return price * quantity;
    }

    void display() {
        cout << "Product: " << name
             << " | Price: " << price
             << " | Quantity: " << quantity
             << " | Total: " << getTotalPrice()
             << endl;
    }
};

class Cart {
private:
    Product products[100];
    int count;

public:
    Cart() {
        count = 0;
    }

    void addProduct(Product p) {
        products[count] = p;
        count++;
        cout << p.name << " added to cart.\n";
    }

    void removeProduct(string productName) {
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (products[i].name == productName) {
                found = true;

                for (int j = i; j < count - 1; j++) {
                    products[j] = products[j + 1];
                }

                count--;
                cout << productName << " removed from cart.\n";
                break;
            }
        }

        if (!found) {
            cout << "Product not found.\n";
        }
    }

    float calculateBill() {
        float total = 0;

        for (int i = 0; i < count; i++) {
            total += products[i].getTotalPrice();
        }

        // Apply 10% discount if total > 1000
        if (total > 1000) {
            cout << "10% Discount Applied!\n";
            total = total - (total * 0.10);
        }

        return total;
    }

    void displayCart() {
        if (count == 0) {
            cout << "Cart is empty.\n";
            return;
        }

        cout << "\n===== CART ITEMS =====\n";

        for (int i = 0; i < count; i++) {
            products[i].display();
        }

        cout << "======================\n";
        cout << "Final Bill: " << calculateBill() << endl;
    }
};

int main() {
    Cart cart;

    int choice;

    do {
        cout << "\n===== MINI SHOPPING CART =====\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Display Cart\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            float price;
            int quantity;

            cout << "Enter Product Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            Product p(name, price, quantity);
            cart.addProduct(p);

            break;
        }

        case 2: {
            string name;

            cout << "Enter product name to remove: ";
            cin >> name;

            cart.removeProduct(name);

            break;
        }

        case 3:
            cart.displayCart();
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}