#include<bits/stdc++.h>

using namespace std;


int main(void) {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> a[i][j];
    vector<int> r(n, 0);
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)r[i] ^= a[i][j];
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)c[i] ^= a[j][i];
    int sr = accumulate(r.begin(), r.end(), 0);
    int sc = accumulate(c.begin(), c.end(), 0);
    if (sr == 0 && sc == 0)
        cout << "OK" << endl;
    else if (sr == 1 && sc == 1) {
        int ri = find(r.begin(), r.end(), 1) - r.begin();
        int ci = find(c.begin(), c.end(), 1) - c.begin();
        cout << ri + 1 << " " << ci + 1 << endl;
    } else
        cout << "Corrupt" << endl;
    return 0;
}