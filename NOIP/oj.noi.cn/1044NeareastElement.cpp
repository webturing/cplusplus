#include <bits/stdc++.h>

using namespace std;

int best(const vector<int> &v, int k) {
    if (k <= v[0])return v[0];
    if (k >= *v.rbegin()) return *v.rbegin();
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (k >= v[mid] && k < v[mid + 1]) {
            return k - v[mid] <= v[mid + 1] - k ? v[mid] : v[mid + 1];
        } else if (k < v[mid]) {
            right = mid;
        } else {
            left = mid;
        }
    }

}

int main(int argc, char const *argv[]) {
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << best(v, k) << endl;
    }
    return 0;
}