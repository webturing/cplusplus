#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int d = k * (k + 1) / 2;
        if (n < d) {
            cout << -1 << endl;
            continue;
        }
        int x = (n / d);
        while (n % x != 0)--x;
        for (int i = 1; i <= k - 1; i++)
            cout << i * x << " ";
        cout << n - (k * (k - 1)) / 2 * x << endl;
    }
    return 0;
}