#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define LOCAL

int eat(int a, int b, int c) {
    int ans = 0;
    if (b >= c) {
        ans += b - (c - 1);
        b = c - 1;
    }
    if (a >= b) {
        ans += a - (b - 1);
        a = b - 1;
    }
    if (a <= 0 || b <= 0 || c <= 0)
        return -1;
    return ans;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
    assert(cin);
    LL start = clock();
#endif
    for (int nG; cin >> nG;) {
        while (nG--) {
            int n1, n2, n3;
            cin >> n1 >> n2 >> n3;
            cout << eat(n1, n2, n3) << endl;
        }
    }
#ifdef LOCAL
    LL end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}

