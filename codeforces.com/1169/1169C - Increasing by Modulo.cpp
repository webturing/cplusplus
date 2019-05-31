#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}


#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    int n(read<int>()), m(read<int>());
    vector<int> a(n, 0);
    FOR(i, 0, n)a[i] = read<int>();
    int left = 0, right = m - 1;
    int best = right;
    while (left <= right) {
        int k = (left + right) / 2;
        int pre = 0;
        bool flag = true;
        FOR(i, 0, n) {
            if (a[i] == pre or a[i] + k >= m + pre) {
                continue;
            }
            if (a[i] > pre) {
                pre = a[i];
            } else if (pre - a[i] > k) {
                flag = false;
                break;
            }
        }
        if (flag) {
            best = min(best, k);
            right = k - 1;
        } else {
            left = k + 1;
        }
    }
    cout << best << endl;
    return 0;
}