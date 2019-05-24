#include<bits/stdc++.h>

using namespace std;


int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int m = k * w * (w + 1) / 2;
    cout << max(0, m - n) << endl;
    return 0;
}