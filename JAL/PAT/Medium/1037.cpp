#include<bits/stdc++.h>

using namespace std;

struct Money {
    int g, s, k;

    inline int safe_mod(int x, int y) {
        int t = x % y;
        if (t < 0)return t + y;
        else return t;
    }

    inline int hash() {
        return g * 17 * 29 + s * 29 + k;
    }

    void rationalize() {
        int sc = hash();
        k = sc;
        sc = k / 29;
        k %= 29;
        s = sc;
        sc = s / 17;
        s %= 17;
        g = sc;

    }

    Money(int g = 0, int s = 0, int k = 0) : g(g), s(s), k(k) { rationalize(); }

    Money operator-(const Money &that) {
        return Money(g - that.g, s - that.s, k - that.k);
    }


    friend ostream &operator<<(ostream &os, const Money &m) {
        os << m.g << "." << m.s << "." << m.k;
        return os;
    }

    friend istream &operator>>(istream &is, Money &m) {
        string str;
        is >> str;
        transform(str.begin(), str.end(), str.begin(), [](char c) -> char { return c == '.' ? ' ' : c; });
        istringstream iss(str);
        iss >> m.g >> m.s >> m.k;
        return is;
    }

};

int main() {
    Money p, a;
    cin >> p >> a;
    if (p.hash() <= a.hash())
        cout << Money(0, 0, a.hash() - p.hash()) << endl;
    else cout << "-" << Money(0, 0, p.hash() - a.hash()) << endl;
    return 0;
}