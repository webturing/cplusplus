#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    map<int, int> f;
    for (auto i:v)
        ++f[i];
    int max = 1;
    int ans = 0;
    for (auto i:f) {
        if (i.second > max) {
            max = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;
    return 0;
}

