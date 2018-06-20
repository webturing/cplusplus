#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    sort(v.begin(), v.end());
    cout << v[k - 1] << endl;
    return 0;
}