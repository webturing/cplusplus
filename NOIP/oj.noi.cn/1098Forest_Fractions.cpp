#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct Fraction {
    Fraction(LL up = 0, LL down = 1) : up(up), down(down) { rationalize(); }

    static LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

    void rationalize() {
        if (up * down < 0) up = -abs(up), down = abs(down);
        else up = abs(up), down = abs(down);
        LL g = gcd(abs(up), abs(down));
        up /= g, down /= g;
    }

    LL up, down;

    Fraction add(const Fraction &that) {
        LL up = this->up * that.down + down * that.up;
        LL down = this->down * that.down;
        return *new Fraction(up, down);
    }

    Fraction sub(const Fraction &that) {
        LL up = this->up * that.down - this->down * that.up;
        LL down = this->down * that.down;
        return *new Fraction(up, down);
    }

    Fraction mul(const Fraction &that) {
        LL up = this->up * that.up;
        LL down = this->down * that.down;
        return *new Fraction(up, down);
    }

    Fraction div(const Fraction &that) {
        LL up = this->up * that.down;
        LL down = this->down * that.up;
        return *new Fraction(up, down);
    }

    friend ostream &operator<<(ostream &os, const Fraction &f) {
        if (f.up == 0)
            os << 0;
        else
            os << f.up << "/" << f.down;
        return os;
    }
};

int main() {
    int n;
    cin >> n;
    while (n--) {
        string exp;
        cin >> exp;
        string ops = exp;
        string nums = exp;
        for_each(ops.begin(), ops.end(), [](char &c) -> void { if (strchr("0123456789", c)) c = ' '; });
        for_each(nums.begin(), nums.end(), [](char &c) -> void { if (strchr("+-*/", c)) c = ' '; });
        istringstream opin(ops), numin(nums);
        LL t;
        numin >> t;
        Fraction res(t);
        string op;
        while (opin >> op) {
            LL b;
            numin >> b;
            Fraction cur(b);
            if (op == "+")res = res.add(cur);
            else if (op == "-")res = res.sub(cur);
            else if (op == "*")res = res.mul(cur);
            else if (op == "/")res = res.div(cur);

        }
        cout << res << endl;

    }

    return 0;
}
