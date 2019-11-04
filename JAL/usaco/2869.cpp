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

int main() {
    int B;
    scanf("%d", &B);
    FOR(N, 1, 301) {
        std::string s = int2str(N, B);
        std::string t = int2str(N * N, B);
        if (check(t))
            printf("%s %s\n", s.c_str(), t.c_str());
    }
    return 0;
}