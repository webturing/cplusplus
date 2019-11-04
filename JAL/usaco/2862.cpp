#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<string>

using LL=long long;

#define FOR(i, x, y) for (std::decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (std::decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)


int hash(std::string s) {
    int ret = 1;
    for (auto c : s) ret = ret * (c - 'A' + 1) % 47;
    return ret;
}

int main() {
    std::string a, b;
    a.resize(100);
    b.resize(100);
    scanf("%s%s", &a[0], &b[0]);
    puts(hash(a) == hash(b) ? "GO" : "STAY");
    return EXIT_SUCCESS;
}