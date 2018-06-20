//
// Created by jal on 2018/6/20 0020.
//

#include<bits/stdc++.h>

using namespace std;

struct BigInteger {
    vector<int> digits;
    int len;

    friend istream &operator>>(istream &is, BigInteger &b) {
        string buff;
        is >> buff;
        b.len = buff.length();
        for (auto i = buff.rbegin(); i != buff.rend(); ++i) {
            b.digits.push_back(*i - '0');
        }
        b.rationalize();
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
        for(int i = 0; i < digits.size(); i++){
            int sc = 0;
            for(int j = 0; j < that.digits.size(); j++){
                int temp = c.digits[i+j] + sc + digits[i] * that.digits[j];
                c.digits[i+j] =temp % 10;
                sc = temp / 10;
            }
            if (sc){
                c.digits[i + that.digits.size()] = sc;
            }
        }
        c.rationalize();
        return c;
    }
};

int main() {
    BigInteger a, b;
    cin>>a>>b;
    cout << a + b << endl;
    return EXIT_SUCCESS;
}