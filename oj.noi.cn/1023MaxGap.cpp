#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] - v[0] << endl;

    return 0;
}
