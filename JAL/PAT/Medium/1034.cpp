#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Fraction {
    LL up, down;

    void rationalize() {
        if (down == 0) {
            down = 0, up = 1;
            return;
        }
        if (up == 0) {
            up = 0, down = 1;
            return;
        }
        if (up * down < 0) {
            up = -abs(up), down = abs(down);
        } else {
            up = abs(up), down = abs(down);
        }
        LL g = __gcd(abs(up), abs(down));
        up /= g, down /= g;
    }

    Fraction(LL up = 0, LL down = 1) : up(up), down(down) { rationalize(); }

    friend ostream &operator<<(ostream &os, const Fraction &f) {
        if (f.down == 0) {
            os << "Inf";
        } else if (f.up == 0) {
            os << 0;
        } else if (f.up > 0) {
            if (f.up >= f.down) {
                os << f.up / f.down;
                if (f.up % f.down) os << " " << f.up % f.down << "/" << f.down;
            } else {
                os << f.up % f.down << "/" << f.down;
            }
        } else {
            if (-f.up >= f.down) {
                os << "(-" << -f.up / f.down;
                if (f.up % f.down) os << " " << -f.up % f.down << "/" << f.down;
                os << ")";
            } else {
                os << "(" << f.up << "/" << f.down << ")";
            }
        }
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &f) {
        string t;
        is >> t;
        transform(t.begin(), t.end(), t.begin(),
                  [](char c) -> char { return c == '/' ? ' ' : c; });
        istringstream iss(t);
        iss >> f.up >> f.down;
        f.rationalize();
        return is;
    }

    Fraction operator+(const Fraction &that) {
        LL up = this->up * that.down + down * that.up;
        LL down = this->down * that.down;
        return Fraction(up, down);
    }

    Fraction operator-(const Fraction &that) {
        LL up = this->up * that.down - down * that.up;
        LL down = this->down * that.down;
        return Fraction(up, down);
    }

    Fraction operator*(const Fraction &that) {
        LL up = this->up * that.up;
        LL down = this->down * that.down;
        return Fraction(up, down);
    }

    Fraction operator/(const Fraction &that) {
        LL up = this->up * that.down;
        LL down = this->down * that.up;
        return Fraction(up, down);
    }
};

int main() {
    Fraction a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}