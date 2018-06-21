#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int t;
    cin >> t;
    //O(N)+O(1)
    int maxv = -200000000;
    int minv = t;
    for (int i = 1; i < n; i++) {
        cin >> t;
        maxv = max(maxv, t - minv);
        minv = min(minv, t);
    }

    cout << maxv << endl;
    return 0;
}
