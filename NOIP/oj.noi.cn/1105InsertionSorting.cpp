#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            auto pos = find(v.begin(), v.end(), b);
            if (pos != v.end())
                v.erase(pos);
            v.push_back(b);
        } else if (a == 1) {
            for (auto i:v) {
                if (i != b) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}