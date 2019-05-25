#include<bits/stdc++.h>

using namespace std;


inline int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + (a - 1) / (b - 1) << endl;
    return 0;
}