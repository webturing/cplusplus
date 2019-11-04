#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#define FOR(i, x, y) for (std::decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (std::decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#include<cstdio>
#include<string>
#include <vector>

using LL=long long;
const std::string R = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string int2str(int m, int base) {
    std::string s;
    for (; m > 0; m /= base)
        s.insert(s.begin(), R[m % base]);
    return s;

}

inline bool check(std::string s) {
    std::string t(s.rbegin(), s.rend());
    return t == s;
}

bool check(int n) {
    int tot = 0;
    for (int b = 2; b <= 10; b++)
        if (check(int2str(n, b)))++tot;
    return tot >= 2;
}

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int m = s + 1; n; m++) {
        if (check(m)) {
            printf("%d\n", m);
            --n;
        }
    }
    return 0;
}