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
    int mmin = INT_MAX;
    for (int i = 1; i <= n - 2; i++) {
        int tmax = 0;
        for (int j = 0; j + 1 <= n - 1; j++) {
            if (j + 1 == i)
                tmax = max(a[j + 2] - a[j], tmax);
            else tmax = max(a[j + 1] - a[j], tmax);
        }
        mmin = min(mmin, tmax);
    }
    cout << mmin << endl;

    return 0;
}
