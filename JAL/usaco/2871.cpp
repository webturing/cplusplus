#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#define FOR(i, x, y) for (std::decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (std::decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#include<cstdio>
#include<string>
#include <vector>
#include <algorithm>

using LL=long long;


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::pair<int, int>> v(m);
    for (auto &p:v)scanf("%d%d", &p.first, &p.second);
    std::sort(v.begin(), v.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first < b.first;
    });
    LL tot = 0;
    for (auto p:v) {
        if (p.second < n) {
            n -= p.second;
            tot += p.first * p.second;
        } else {
            tot += n * p.first;
            break;
        }
    }
    printf("%lld\n", tot);
    return 0;
}