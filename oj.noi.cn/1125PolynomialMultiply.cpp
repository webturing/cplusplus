#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

struct Polynomial {
    int n;
    map<int, LL> k;


    friend istream &operator>>(istream &is, Polynomial &p) {
        int T = 0;
        is >> T;
        for (int t, j; T-- && is >> t >> j;) {
            p.k[j] = t;
        }
        for (auto i:p.k)
            if (i.first) {
                p.n = i.first;
            }
        return is;
    }

    friend ostream &operator<<(ostream &os, Polynomial p) {
        if (p.k[p.n]) {
            if (p.k[p.n] == 1)
                os << "x^" << p.n;
            else if (p.k[p.n] == -1)
                os << "-x^" << p.n;
            else
                os << p.k[p.n] << "*x^" << p.n;
        }
        for (int j = p.n - 1; j >= 2; --j) {
            if (p.k[j]) {
                if (p.k[j] == 1)
                    os << "+x^" << j;
                else if (p.k[j] == -1)
                    os << "-x^" << j;
                else if (p.k[j] > 0)
                    os << "+" << p.k[j] << "*x^" << j;
                else
                    os << p.k[j] << "*x^" << j;
            }
        }
        if (p.k[1]) {
            if (p.k[1] == 1)
                os << "+x";
            else if (p.k[1] == -1)
                os << "-x";
            else if (p.k[1] > 0)
                os << "+" << p.k[1] << "*x";
            else
                os << p.k[1] << "*x";
        }
        if (p.k[0] > 0)
            os << "+" << p.k[0];
        else if (p.k[0] < 0)
            os << p.k[0];
        return os;
    }

    friend Polynomial operator*(Polynomial &p, Polynomial &q) {
        Polynomial r;
        r.n = p.n + q.n;
        for (int i = 0; i <= p.n; i++)
            for (int j = 0; j <= q.n; j++)
                r.k[i + j] += p.k[i] * q.k[j];
        return r;
    }
};

int main(int argc, char const *argv[]) {
    Polynomial p, q;
    ifstream cin("input.txt");
    cin >> p >> q;
    cout << p * q << endl;
    return 0;
}