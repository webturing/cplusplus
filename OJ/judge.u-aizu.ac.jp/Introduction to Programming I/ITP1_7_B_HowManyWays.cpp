#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    while (cin >> n >> x) {
        if (n == 0 and x == 0)
            break;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                int k = x - i - j;
                if (k > j && k <= n) {
                    ++cnt;
                }
            }
        cout << cnt << endl;
    }
    return 0;
}