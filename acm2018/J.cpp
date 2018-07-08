
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
        int best = right;
        while (left < right) {
            int mid = (left + right) >> 1;
            int t = 1;
            int s = v[0];
            for (int i = 1; i < v.size(); i++) {
                if (s + v[i] > mid) {
                    t++;
                    s = v[i];
                    //copy(v.begin(),v.begin()+i,ostream_iterator<int>(cerr," "));cerr<<endl;
                } else {
                    s += v[i];
                }
                if (t > m)
                    break;
            }
            if (t > m) {
                left = mid + 1;
            } else {
                if (best > mid) {
                    best = mid;
                    //cerr << "best=" << best << endl;
                }
                right = mid;
            }
        }
        cerr << best << endl;
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