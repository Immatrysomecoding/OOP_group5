#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

#include <iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

public:

    void input(istream& inDev);
    void output(ostream& outDev) const;

    void get(int& n, int& d) const;

    void set(int n, int d);

    Fraction invert() const;
    Fraction reduce() const;

    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
};

istream& operator>>(istream& inDev, Fraction& f);
ostream& operator<<(ostream& outDev, const Fraction& f);

#endif