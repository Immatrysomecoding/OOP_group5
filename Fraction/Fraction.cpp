#include "Fraction.hpp"

static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

void Fraction::input() {
    int n, d;
    while (true) {
        cin >> n >> d;
        if (d == 0) {
            cout << "  Error: denominator cannot be 0. Try again: ";
            continue;
        }
        break;
    }
    numerator   = n;
    denominator = d;
}

void Fraction::output() const {
    cout << numerator << "/" << denominator;
}

void Fraction::get(int& n, int& d) const {
    n = numerator;
    d = denominator;
}

void Fraction::set(int n, int d) {
    if (d == 0) {
        cout << "  Error: denominator cannot be 0. Value unchanged.\n";
        return;
    }
    if (d < 0) { n = -n; d = -d; }
    numerator   = n;
    denominator = d;
}

Fraction Fraction::invert() const {
    if (numerator == 0) {
        cout << "  Error: cannot invert a fraction with numerator 0. Value unchanged.\n";
        return *this;
    }
    Fraction result;
    result.set(denominator, numerator);
    return result;
}

Fraction Fraction::reduce() const {
    Fraction result;
    int g = gcd(numerator, denominator);
    result.numerator   = numerator   / g;
    result.denominator = denominator / g;
    return result;
}

Fraction Fraction::add(const Fraction& other) const {
    Fraction result;
    result.numerator   = numerator * other.denominator
                       + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result.reduce();
}

Fraction Fraction::subtract(const Fraction& other) const {
    Fraction result;
    result.numerator   = numerator * other.denominator
                       - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result.reduce();
}

Fraction Fraction::multiply(const Fraction& other) const {
    Fraction result;
    result.numerator   = numerator   * other.numerator;
    result.denominator = denominator * other.denominator;
    return result.reduce();
}

Fraction Fraction::divide(const Fraction& other) const {
    if (other.numerator == 0) {
        cout << "  Error: cannot divide by zero fraction. Value unchanged.\n";
        return *this;
    }
    return multiply(other.invert());
}

istream& operator>>(istream& inDev, Fraction& f) {
    f.input();
    return inDev;
}

ostream& operator<<(ostream& outDev, const Fraction& f) {
    f.output();
    return outDev;
}