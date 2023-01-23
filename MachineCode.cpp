#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, double> items = {
    {"Chips", 1.50},
    {"Candy", 0.75},
    {"Soda", 1.25},
    {"Water", 1.00}
};

double balance = 0;

void displayItems() {
    cout << "Vending Machine Items:" << endl;
    for (auto item : items) {
        cout << item.first << " - $" << item.second << endl;
    }
}

bool purchaseItem(string itemName) {
    double itemPrice = items[itemName];
    if (balance >= itemPrice) {
        balance -= itemPrice;
        cout << "Purchasing " << itemName << " for $" << itemPrice << endl;
        cout << "Your remaining balance is $" << balance << endl;
        return true;
    } else {
        cout << "Not enough funds to purchase " << itemName << endl;
        return false;
    }
}

void addMoney(double amount) {
    balance += amount;
    cout << "Added $" << amount << " to balance. Your new balance is $" << balance << endl;
}

int main() {
    displayItems();

    while (true) {
        string itemName;
        cout << "Enter the name of the item you would like to purchase or type 'exit' to quit: ";
        cin >> itemName;

        if (itemName == "exit") {
            break;
        }

        if (items.count(itemName) == 0) {
            cout << "Invalid item name" << endl;
            continue;
        }

        if (!purchaseItem(itemName)) {
            double amount;
            cout << "Enter the amount you would like to add to your balance: ";
            cin >> amount;
            addMoney(amount);
        }
    }
    return 0;
}
