#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        auto existed = binary_search(v.begin(), v.end(), k);
        if (existed) {
            cout << k << endl;
            continue;
        }
        if (k <= v[0]) {
            cout << v[0] << endl;
            continue;
        }
        if (k >= v[n - 1]) {
            cout << v[n - 1] << endl;
            continue;
        }

        auto pos = upper_bound(v.begin(), v.end(), k);
        cerr << pos - v.begin() << endl;
        auto left = *(pos - 1), right = *pos;
        if (k - left <= right - k) {
            cout << left << endl;
        } else {
            cout << right << endl;
        }
    }
    return 0;
}