#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#define FOR(i, x, y) for (std::decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (std::decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#include<cstdio>
#include<string>
#include <vector>

using LL=long long;

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> w(7, 0);
    int M[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    std::vector<int> D;
    int cnt = 0;
    FOR(y, 1900, 1900 + n) {
        auto leap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
        FOR(m, 1, 13) {
            FOR (j, 1, M[leap][m] + 1) {
                if (j == 13) {
                    w[cnt % 7]++;
                }
                ++cnt;
            }
        }
    }
    FOR(i, 5, 12) printf("%d ", w[i % 7]);
    printf("\n");
    return EXIT_SUCCESS;
}