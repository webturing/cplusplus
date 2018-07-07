
#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream cin("input.txt");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (auto &i:v)cin >> i;
        int left = *max_element(v.begin(), v.end());
        int right = accumulate(v.begin(), v.end(), 0);
        while (left < right) {
            int mid = (left + right) >> 1;
            int t = 0;
            int s = 0;
            for (int i = 0; i < v.size(); i++) {
                if (t > m)
                    break;
                if (s + v[i] > mid) {
                    t++;
                    s = v[i];
                } else {
                    s += v[i];
                }
            }
            if (t > m) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int s = 0;
        int gmin = 0xfffff;
        for (int i = 0; i < v.size(); i++) {
            if (s + v[i] > left) {
                if (s < gmin)gmin = s;
                s = v[i];
            } else {
                s += v[i];
            }
        }
        cout << gmin << endl;
    }

    return 0;
}