#include<bits/stdc++.h>

using namespace std;

int main() {//O(n^2)
    int n = 100005;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
        for (int j = i + 1; j <= n - i; j++) {
            int s = (i + j) * (j - i + 1) / 2;
            if (s == n) {
                cout << i << " " << j << endl;
            }
        }
    return 0;
}