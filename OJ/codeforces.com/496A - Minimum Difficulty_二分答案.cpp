#include<bits/stdc++.h>

using namespace std;

template<typename T>
void oo(string str, T val) {
    cerr << str << val << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e:a)cin >> e;
    vector<int> d;
    for (int i = 1; i <= n - 1; i++)d.push_back(a[i] - a[i - 1]);
    int left = *max_element(d.begin(), d.end()), right = accumulate(d.begin(), d.end(), 0);
    int gbest = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0, cur = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cur + d[i] <= mid) {
                cur += d[i];
            } else {
                cur = d[i];
                ++cnt;
            }
        }
        if (cur > 0)++cnt;
        if (cnt <= n - 2) {
            gbest = min(mid, gbest);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << gbest << endl;

    return 0;
}
