
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &e:v)cin >> e;
    int left = *max_element(v.begin(), v.end());
    int right = accumulate(v.begin(), v.end(), 0);
    int best = right;
    while (left < right) {
        int mid = (left + right) >> 1;
        int s = v[0], t = 1;
        for (int i = 1; i < v.size(); i++) {
            if (s + v[i] > mid) {
                ++t;
                s = v[i];
            } else {
                s += v[i];
            }
            if (t > m)break;
        }
        if (t > m) {
            left = mid + 1;
        } else {
            if (mid < best)best = mid;
            right = mid;
        }
    }
    cout << best << endl;
    return 0;
}