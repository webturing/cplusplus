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
    int n = read_int();
    int game[n + 1];
    fill(game + 1, game + n + 1, 0);
    FOR(i, 0, read_int())game[read_int()] = 1;
    FOR(i, 0, read_int())game[read_int()] = 1;
    if (accumulate(game + 1, game + n + 1, 0) == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}