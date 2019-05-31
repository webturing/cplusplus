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
    int n(read<int>());
    int a(read<int>()), x(read<int>()), b(read<int>()), y(read<int>());
    queue<int> P, Q;
    for (int i = 1; i <= n * n; i++)Q.push(i % n + 1);
    for (int i = n * n; i >= 1; i--)P.push(i % n + 1);

    while (Q.front() != a)Q.pop();
    while (P.front() != b)P.pop();

    bool flag = false;
    while (Q.front() != x and P.front() != y) {
        Q.pop();
        P.pop();
        if (Q.front() == P.front()) {
            flag = true;
            break;
        }

    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}