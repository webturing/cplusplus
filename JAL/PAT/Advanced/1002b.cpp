#include <bits/stdc++.h>

using namespace std;

using LL = long long;

template<typename T = int>
inline void oo(string str, T val) {
    cerr << str << val << endl;
}

template<typename T = int>
inline T read() {
    T x;
    cin >> x;
    return x;
}

#define endl '\n'
#define FOR(i, x, y) \
  for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
  for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

struct Polynomial {
    int z;
    map<int, double> M;

    Polynomial(int z = 0) : z(z) {}

    void clean() {
        for (int i = z; i >= 0; i--)
            if (M[i] == 0) {
                M.erase(i);
                if (i == z) z--;
            }
    }

    Polynomial operator*(Polynomial &that) {
        Polynomial ans;
        ans.z = this->z + that.z;
        for (int x = this->z; x >= 0; x--)
            for (int y = that.z; y >= 0; y--) {
                // if (this->M[x] != 0 or that.M[y] != 0)
                ans.M[x + y] += this->M[x] * that.M[y];
            }
        ans.clean();
        return ans;
    }

    Polynomial operator+(Polynomial &that) {
        Polynomial ans;
        ans.z = max(this->z, that.z);
        for (int x = ans.z; x >= 0; x--) {
            ans.M[x] = this->M[x] + that.M[x];
        }
        ans.clean();
        return ans;
    }

    friend istream &operator>>(istream &is, Polynomial &p) {
        int T;
        is >> T;
        while (T--) {
            int k;
            double f;
            is >> k >> f;
            p.z = max(p.z, k);
            p.M[k] = f;
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, Polynomial &p) {
        os << p.M.size();
        for (int i = p.z; i >= 0; i--) {
            if (p.M[i]) {
                os << " " << i << " " << fixed << setprecision(1) << p.M[i];
            }
        }
        return os;
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Polynomial a = read<Polynomial>(), b = read<Polynomial>(), c = a + b;
    cout << c;
    return 0;
}
