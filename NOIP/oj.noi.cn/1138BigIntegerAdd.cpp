#include <bits/stdc++.h>

using namespace std;

struct BigInteger {
    vector<int> D;
    int len;

    friend istream &operator>>(istream &is, BigInteger &b) {
        string buf;
        is >> buf;
        b.len = buf.length();
        for (auto i = buf.rbegin(); i != buf.rend(); ++i)
            b.D.push_back(int(*i - '0'));
        return is;
    }

    friend ostream &operator<<(ostream &os, const BigInteger &b) {
        copy(b.D.rbegin(), b.D.rend(), ostream_iterator<int>(os, ""));
        return os;
    }

    int getDigitAt(int pos) const {
        if (pos >= len)
            return 0;
        return D[pos];
    }

    BigInteger operator+(const BigInteger &b) {
        BigInteger c;
        c.len = max(len, b.len);
        int sc = 0;
        for (int i = 0; i < c.len; i++) {
            int temp = sc + getDigitAt(i) + b.getDigitAt(i);
            sc = temp / 10;
            c.D.push_back(temp % 10);

        }
        if (sc) {
            c.D.push_back(sc);
        }
        return c;
    }
};


int main() {
    BigInteger a, b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;

}


