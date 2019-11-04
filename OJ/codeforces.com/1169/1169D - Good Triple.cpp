#include<bits/stdc++.h>

using namespace std;

int main() {
    char c[300001];
    cin >> c;
    int len = strlen(c);
    vector<int> v(len + 1, len);
    long long ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        v[i] = v[i + 1];
        for (int k = 1; i + 2 * k < v[i]; k++) {
            if (c[i] == c[i + k] && c[i + k] == c[i + 2 * k]) {
                v[i] = i + 2 * k;
            }
        }
        ans += len - v[i];
    }
    cout << ans << endl;
    return 0;
}