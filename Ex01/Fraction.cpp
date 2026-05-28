#include "Fraction.hpp"

static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

void Fraction::input(istream& inDev) {
    int n, d;
    inDev >> n >> d;
    set(n, d);
}

void Fraction::output(ostream& outDev) const {
    outDev << numerator << "/" << denominator;
}

void Fraction::get(int& n, int& d) const {
    n = numerator;
    d = denominator;
}

void Fraction::set(int n, int d) {
    if (d == 0) return;       
    if (d < 0) { n = -n; d = -d; }
    numerator   = n;
    denominator = d;
}

Fraction Fraction::invert() const {
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
    return multiply(other.invert());
}

istream& operator>>(istream& inDev, Fraction& f) {
    f.input(inDev);
    return inDev;
}

ostream& operator<<(ostream& outDev, const Fraction& f) {
    f.output(outDev);
    return outDev;
}