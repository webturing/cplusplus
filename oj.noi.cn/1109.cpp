#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input2.txt");
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int i;
            cin >> i;
            cout << v[i] << endl;
        } else if (a == 2) {
            int i, vv;
            cin >> i >> vv;
            v.insert(v.begin() + i, vv);
        } else if (a == 3) {
            int i;
            cin >> i;
            v.erase(v.begin() + i);
        }
    }
    return 0;
}