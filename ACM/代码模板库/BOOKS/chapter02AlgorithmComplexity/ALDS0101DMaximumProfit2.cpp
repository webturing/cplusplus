#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> R(n);
    for (auto &i:R)cin >> i;
    //O(N)+O(N)
    int maxv = -200000000;
    int minv = R[0];
    for (int i = 1; i < n; i++) {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    cout << maxv << endl;
    return 0;
}
