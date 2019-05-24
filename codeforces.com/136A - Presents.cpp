#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> G;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        G[t] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << G[i] << " ";
    }
    cout << endl;

    return 0;
}
