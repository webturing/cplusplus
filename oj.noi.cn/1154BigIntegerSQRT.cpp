#include <bits/stdc++.h>

using namespace std;

struct BigInteger {
    vector<int> digits;
    int len;

    BigInteger(string s = "0") {
        this->len = s.length();
        for (auto c = s.rbegin(); c != s.rend(); ++c)this->digits.push_back(*c - '0');
    }

    BigInteger(const BigInteger &that) {
        this->len = that.len;
        for (auto i:that.digits)this->digits.push_back(i);
    }

    friend istream &operator>>(istream &is, BigInteger &b) {
        string buff;
        is >> buff;
        b = *new BigInteger(buff);
        return is;
    }

    void rationalize() {
        if (count(digits.begin(), digits.end(), 0) == len) {
            len = 1;
            digits.resize(1);
            digits[0] = 0;
            return;
        }
        auto start = digits.rbegin();
        while (*start == 0)++start;
        digits.resize(digits.rend() - start);
        len = digits.size();
    }

    friend ostream &operator<<(ostream &os, const BigInteger &b) {
        copy(b.digits.rbegin(), b.digits.rend(), ostream_iterator<int>(os, ""));
        return os;
    }

    inline int getDigitAt(int pos) const {
        return pos >= len ? 0 : digits[pos];
    }

    BigInteger operator+(const BigInteger &that) const {
        BigInteger c;
        c.len = max(digits.size(), that.digits.size()) + 1;
        c.digits.resize(c.len);
        int sc = 0;
        for (int i = 0; i < c.len; i++) {
            int temp = getDigitAt(i) + that.getDigitAt(i) + sc;
            sc = temp / 10;
            c.digits[i] = temp % 10;
        }
        if (sc) {
            c.digits[c.len - 1] = sc;
        }
        c.rationalize();
        return c;
    }

    BigInteger operator*(const BigInteger &that) const {
        BigInteger c;
        c.len = digits.size() + that.digits.size();
        c.digits.resize(c.len);
        for (int i = 0; i < digits.size(); i++) {
            int sc = 0;
            for (int j = 0; j < that.digits.size(); j++) {
                int temp = c.digits[i + j] + sc + digits[i] * that.digits[j];
                c.digits[i + j] = temp % 10;
                sc = temp / 10;
            }
            if (sc) {
                c.digits[i + that.digits.size()] = sc;
            }
        }
        c.rationalize();
        return c;
    }

    BigInteger half() {
        BigInteger res(*this);
        int sc = 0;
        for (int i = len - 1; i >= 0; i--) {
            int temp = digits[i];
            res.digits[i] = sc ? temp / 2 + 5 : temp / 2;
            sc = temp % 2;
        }
        res.rationalize();
        return res;
    }

    bool operator<(const BigInteger &that) {
        if (this->len - that.len)return this->len < that.len;
        for (int i = len - 1; i >= 0; i--)
            if (this->digits[i] - that.digits[i]) {
                return this->digits[i] < that.digits[i];
            }
        return false;
    }
};

int main() {
    ifstream cin("input.txt");
    BigInteger a;
    cin >> a;
    BigInteger left, right(a), x, y;
    for (int i = 0; i < 1000; i++) {
        x = (left + right).half();
        y = x * x;
        if (y < a) {
            left = x;
        } else {
            right = x;
        }
    }
    cout << x << endl;
}