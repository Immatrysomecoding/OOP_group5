#include "Fraction.hpp"
#include <iostream>
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void printMenu(const Fraction& f) {
    cout << "========== Fraction Tester ==========\n";
    cout << "Current fraction: " << f << "\n";
    cout << "-------------------------------------\n";
    cout << "1.  input\n";
    cout << "2.  output\n";
    cout << "3.  set\n";
    cout << "4.  get\n";
    cout << "5.  invert\n";
    cout << "6.  reduce\n";
    cout << "7.  add\n";
    cout << "8.  subtract\n";
    cout << "9.  multiply\n";
    cout << "10. divide\n";
    cout << "0.  exit\n";
    cout << "=====================================\n";
    cout << "Choose: ";
}

int main() {
    Fraction f;
    f.set(0, 1);

    int choice;
    do {
        clearScreen();
        printMenu(f);
        cin >> choice;
        clearScreen();

        switch (choice) {
            case 1:
                cout << "Enter fraction (numerator denominator): ";
                f.input();
                cout << "Stored: " << f << "\n";
                break;

            case 2:
                cout << "Current: ";
                f.output();
                cout << "\n";
                break;

            case 3: {
                int n, d;
                cout << "Enter numerator denominator: ";
                cin >> n >> d;
                f.set(n, d);
                cout << "Set to: " << f << "\n";
                break;
            }

            case 4: {
                int n, d;
                f.get(n, d);
                cout << "Numerator   = " << n << "\n";
                cout << "Denominator = " << d << "\n";
                break;
            }

            case 5:
                f = f.invert();
                cout << "Inverted: " << f << "\n";
                break;

            case 6:
                f = f.reduce();
                cout << "Reduced: " << f << "\n";
                break;

            case 7: {
                Fraction other;
                cout << "Enter other fraction (numerator denominator): ";
                other.input();
                f = f.add(other);
                cout << "Result: " << f << "\n";
                break;
            }

            case 8: {
                Fraction other;
                cout << "Enter other fraction (numerator denominator): ";
                other.input();
                f = f.subtract(other);
                cout << "Result: " << f << "\n";
                break;
            }

            case 9: {
                Fraction other;
                cout << "Enter other fraction (numerator denominator): ";
                other.input();
                f = f.multiply(other);
                cout << "Result: " << f << "\n";
                break;
            }

            case 10: {
                Fraction other;
                cout << "Enter other fraction (numerator denominator): ";
                other.input();
                f = f.divide(other);
                cout << "Result: " << f << "\n";
                break;
            }

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