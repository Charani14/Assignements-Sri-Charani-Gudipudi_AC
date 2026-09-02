#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails() {

    // Product ID
    while (true) {
        cout << "Enter Product ID: ";
        cin >> productId;

        if (!cin.fail()) {
            break;
        }

        cout << "Invalid Product ID! Please enter a number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }


    // Product Name
    cout << "Enter Product Name: ";
    cin >> name;


    // Price
    while (true) {
        cout << "Enter Price: ";
        cin >> price;

        if (!cin.fail() && price >= 0) {
            break;
        }

        cout << "Invalid price! Please enter a valid number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }


    // Quantity
    while (true) {
        cout << "Enter Quantity: ";
        cin >> quantity;

        if (!cin.fail() && quantity >= 0) {
            break;
        }

        cout << "Invalid quantity! Please enter a non-negative integer.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

    void displayDetails() const {
        cout << left << setw(10) << productId
             << setw(15) << name
             << right << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();

        if (isLowStock(10)) {
            cout << "  <- LOW STOCK";
        }

        cout << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const {
        return name;
    }
};

// Function Overloading
double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100.0);
}

// Default Argument
double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * discountPercent / 100.0);
}

int main() {
    Product products[5];

    cout << " ENTER PRODUCT DETAILS \n";

    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====\n";

    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << right << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    cout << string(70, '-') << endl;

    for (int i = 0; i < 5; i++) {
        products[i].displayDetails();
    }

    // Find product with highest total value
    int highestIndex = 0;

    for (int i = 1; i < 5; i++) {
        if (products[i].totalValue() >
            products[highestIndex].totalValue()) {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product : "
         << products[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << products[highestIndex].totalValue()
         << ")\n";

    // Low stock products
    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "Low Stock (threshold: " << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++) {
        if (products[i].isLowStock(threshold)) {
            if (found) {
                cout << ", ";
            }

            cout << products[i].getName();
            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }

    cout << endl;

    // Function overloading demonstrations
    cout << "\n===== REORDER COST =====\n";

    cout << "Integer quantity cost : "
         << reorderCost(10, 50.0) << endl;

    cout << "Fractional quantity cost : "
         << reorderCost(5.5, 50.0) << endl;

    cout << "Cost with tax : "
         << reorderCost(10, 50.0, 18.0) << endl;

    // Default argument
    cout << "\n===== DISCOUNT =====\n";

    cout << "Price after default 10% discount : "
         << applyDiscount(1000) << endl;

    cout << "Price after 20% discount : "
         << applyDiscount(1000, 20.0) << endl;

    return 0;
}