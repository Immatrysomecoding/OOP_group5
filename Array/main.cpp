#include "Array.hpp"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printMenu(const Array& a) {
    cout << "========== Array Tester ==========\n";
    cout << "Current array: ";
    a.output();
    cout << "\n----------------------------------\n";
    cout << "1.  input\n";
    cout << "2.  output\n";
    cout << "3.  getSize\n";
    cout << "4.  getItem (by index)\n";
    cout << "5.  find (by value)\n";
    cout << "6.  sort increasingly\n";
    cout << "7.  sort decreasingly\n";
    cout << "0.  exit\n";
    cout << "==================================\n";
    cout << "Choose: ";
}

int main() {
    Array a;

    int choice;
    do {
        clearScreen();
        printMenu(a);
        cin >> choice;
        clearScreen();

        switch (choice) {
            case 1:
                a.input();
                cout << "Stored: ";
                a.output();
                cout << "\n";
                break;

            case 2:
                cout << "Current: ";
                a.output();
                cout << "\n";
                break;

            case 3:
                cout << "Size = " << a.getSize() << "\n";
                break;

            case 4: {
                int idx;
                cout << "Enter index: ";
                cin >> idx;
                int val = a.getItem(idx);
                if (idx >= 0 && idx < a.getSize())
                    cout << "Item at [" << idx << "] = " << val << "\n";
                break;
            }

            case 5: {
                int val;
                cout << "Enter value to find: ";
                cin >> val;
                int idx = a.find(val);
                if (idx == -1)
                    cout << val << " not found in array.\n";
                else
                    cout << val << " found at index " << idx << ".\n";
                break;
            }

            case 6:
                a.sortIncreasing();
                cout << "Sorted (increasing): ";
                a.output();
                cout << "\n";
                break;

            case 7:
                a.sortDecreasing();
                cout << "Sorted (decreasing): ";
                a.output();
                cout << "\n";
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}