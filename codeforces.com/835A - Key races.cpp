#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

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
    LL s(read<LL>()), v1(read<LL>()), v2(read<LL>()), t1(read<LL>()), t2(read<LL>());
    LL q1 = 2 * t1 + s * v1;
    LL q2 = 2 * t2 + s * v2;

    if (q1 < q2) {
        cout << "First\n";
    } else if (q1 > q2) {
        cout << "Second\n";
    } else {
        cout << "Friendship\n";
    }

    return 0;

}
