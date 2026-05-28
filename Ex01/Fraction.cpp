#include "Fraction.hpp"

// ─── Helper: greatest common divisor ────────────────────────────────────────
static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

// ─── Input / Output ──────────────────────────────────────────────────────────
void Fraction::input(istream& inDev) {
    int n, d;
    inDev >> n >> d;
    set(n, d);
}

void Fraction::output(ostream& outDev) const {
    outDev << numerator << "/" << denominator;
}

// ─── Get / Set ───────────────────────────────────────────────────────────────
void Fraction::get(int& n, int& d) const {
    n = numerator;
    d = denominator;
}

void Fraction::set(int n, int d) {
    if (d == 0) return;         // guard: reject zero denominator
    if (d < 0) { n = -n; d = -d; }  // keep sign in numerator
    numerator   = n;
    denominator = d;
}

// ─── Inversion ───────────────────────────────────────────────────────────────
Fraction Fraction::invert() const {
    Fraction result;
    result.set(denominator, numerator);
    return result;
}

// ─── Reduction ───────────────────────────────────────────────────────────────
Fraction Fraction::reduce() const {
    Fraction result;
    int g = gcd(numerator, denominator);
    result.numerator   = numerator   / g;
    result.denominator = denominator / g;
    return result;
}

// ─── Arithmetic ──────────────────────────────────────────────────────────────
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
    // Divide by other == multiply by inverted other
    return multiply(other.invert());
}

// ─── Stream operators ────────────────────────────────────────────────────────
istream& operator>>(istream& inDev, Fraction& f) {
    f.input(inDev);
    return inDev;
}

ostream& operator<<(ostream& outDev, const Fraction& f) {
    f.output(outDev);
    return outDev;
}