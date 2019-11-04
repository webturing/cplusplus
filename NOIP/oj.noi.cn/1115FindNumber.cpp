#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    while (m--) {
        int x;
        cin >> x;
        auto idx = upper_bound(v.begin(), v.end(), x);
        if (idx > v.begin())
            cout << *(upper_bound(v.begin(), v.end(), x) - 1) << endl;
        else
            cout << -1 << endl;
    }

    return EXIT_SUCCESS;

}