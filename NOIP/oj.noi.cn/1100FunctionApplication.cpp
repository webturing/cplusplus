#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

inline void f0(LL &a) {};

inline void f1(LL &a) { a = a * 11 + 24; }

inline void f2(LL &a) { a = (a >> 3) + 3; }

inline void f3(LL &a) { a = a * a + 10 * a + 31; }

inline void f4(LL &a) { a = a / 13 + 31; }

inline void f5(LL &a) { a = a - (int) sqrt(a); }

inline void f6(LL &a) { a = (int) sqrt(a); }

inline void f7(LL &a) { a = a % 206211; }

inline void f8(LL &a) { a = a | 10311999; }

inline void f9(LL &a) { a = a & 19991124; }

inline void f10(LL &a) { a = a ^ 11241031; }

vector<void (*)(LL &)> F{f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10};

int main(int argc, char const *argv[]) {
    int m, x, y;
    LL a;
    for (cin >> m; m-- && cin >> x >> y >> a;) {
        swap(F[x], F[y]);
        for (auto f : F) f(a);
        cout << a << endl;
    }
    return 0;
}