#include<bits/stdc++.h>

using namespace std;

struct BigInteger : vector<int> {

    BigInteger(int n = 0) {
        push_back(n);
        check();
    }

    BigInteger &check() {
        while (!empty() && !back())pop_back();
        if (empty())return *this;
        for (int i = 1; i < size(); ++i) {
            (*this)[i] += (*this)[i - 1] / 10;
            (*this)[i - 1] %= 10;
        }
        while (back() >= 10) {
            push_back(back() / 10);
            (*this)[size() - 2] %= 10;
        }
        return *this;
    }
};

istream &operator>>(istream &is, BigInteger &n) {
    string s;
    is >> s;
    n.clear();
    for (int i = s.size() - 1; i >= 0; --i)n.push_back(s[i] - '0');
    return is;
}

ostream &operator<<(ostream &os, const BigInteger &n) {
    if (n.empty())os << 0;
    for (int i = n.size() - 1; i >= 0; --i)os << n[i];
    return os;
}

bool operator!=(const BigInteger &a, const BigInteger &b) {
    if (a.size() != b.size())return 1;
    for (int i = a.size() - 1; i >= 0; --i)
        if (a[i] != b[i])return 1;
    return 0;
}

bool operator==(const BigInteger &a, const BigInteger &b) {
    return !(a != b);
}

bool operator<(const BigInteger &a, const BigInteger &b) {
    if (a.size() != b.size())return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; --i)
        if (a[i] != b[i])return a[i] < b[i];
    return 0;
}

bool operator>(const BigInteger &a, const BigInteger &b) {
    return b < a;
}

bool operator<=(const BigInteger &a, const BigInteger &b) {
    return !(a > b);
}

bool operator>=(const BigInteger &a, const BigInteger &b) {
    return !(a < b);
}


BigInteger &operator+=(BigInteger &a, const BigInteger &b) {
    if (a.size() < b.size())a.resize(b.size());
    for (int i = 0; i != b.size(); ++i)a[i] += b[i];
    return a.check();
}

BigInteger operator+(BigInteger a, const BigInteger &b) {
    return a += b;
}

BigInteger &operator-=(BigInteger &a, BigInteger b) {
    if (a < b)swap(a, b);
    for (int i = 0; i != b.size(); a[i] -= b[i], ++i)
        if (a[i] < b[i]) {
            int j = i + 1;
            while (!a[j])++j;
            while (j > i) {
                --a[j];
                a[--j] += 10;
            }
        }
    return a.check();
}

BigInteger operator-(BigInteger a, const BigInteger &b) {
    return a -= b;
}


BigInteger operator*(const BigInteger &a, const BigInteger &b) {
    BigInteger n;
    n.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i != a.size(); ++i)
        for (int j = 0; j != b.size(); ++j)
            n[i + j] += a[i] * b[j];
    return n.check();
}

BigInteger &operator*=(BigInteger &a, const BigInteger &b) {
    return a = a * b;
}


BigInteger divmod(BigInteger &a, const BigInteger &b) {
    BigInteger ans;
    for (int t = a.size() - b.size(); a >= b; --t) {
        BigInteger d;
        d.assign(t + 1, 0);
        d.back() = 1;
        BigInteger c = b * d;
        while (a >= c) {
            a -= c;
            ans += d;
        }
    }
    return ans;
}

BigInteger operator/(BigInteger a, const BigInteger &b) {
    return divmod(a, b);
}

BigInteger &operator/=(BigInteger &a, const BigInteger &b) {
    return a = a / b;
}

BigInteger &operator%=(BigInteger &a, const BigInteger &b) {
    divmod(a, b);
    return a;
}

BigInteger operator%(BigInteger a, const BigInteger &b) {
    return a %= b;
}

BigInteger pw(const BigInteger &n, int k) {
    if (k == 0)return 1;
    if (k == 2)return n * n;
    if (k % 2)return n * pw(n, k - 1);
    return pw(pw(n, k / 2), 2);
}


BigInteger gcd(BigInteger n, BigInteger m) {
    BigInteger rem = n % m;
    if (rem == 0)
        return m;
    else
        return gcd(m, rem);
}

const int maxn = 1001;
vector<bool> prime(maxn, true);
vector<int> primes(1, 2);

void init() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
        if (prime[i])
            for (int j = i * i; j < maxn; j += i)prime[j] = false;
    for (int i = 3; i < maxn; i += 2)if (prime[i])primes.push_back(i);
}


int main() {
    init();
    map<int, int> idx;
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << 0 << endl;
            cout << 1 << endl;
            return 0;
        }

        for (auto p:primes)while (t > 1 && t % p == 0)idx[p]++, t /= p;

    }
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        for (auto p:primes)while (t > 1 && t % p == 0)idx[p]--, t /= p;

    }

    BigInteger UP = 1, DOWN = 1;
    for (int p:primes) {
        if (idx[p] > 0) {
            BigInteger b(p);
            UP *= pw(b, idx[p]);
        } else if (idx[p] < 0) {
            BigInteger b(p);
            DOWN *= pw(b, -idx[p]);
        }
    }
    cout << UP << endl;
    cout << DOWN << endl;

    return 0;
}