#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>

typedef long long LL;
using namespace std;

double pi = acos(-1);

int n;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while (scanf("%d", &n) == 1) {
        double t = 2 * pi / n;
        printf("%.6lf\n", 1.0 * (n - 1) / 2 * sin(t) + sin(t / 2));
    }

    return 0;
}
 