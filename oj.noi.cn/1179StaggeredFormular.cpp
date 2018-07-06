#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

LL D(int n) {
    vector<LL> v(n + 1, 1);
    for (int i = 2; i <= n; i++)v[i] = v[i - 1] * i;
    LL s = 0;
    for (int i = 0; i <= n; i++) {
        if (i & 1) {
            s -= v[n] / v[i];
        } else {
            s += v[n] / v[i];
        }
    }
    return s;

}

int main() {
    int n;
    cin >> n;
    cout << D(n) << endl;
    return 0;
}
