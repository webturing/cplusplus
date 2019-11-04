#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    cout << setiosflags(ios::fixed) << setprecision(2) << 1.0 * accumulate(v.begin(), v.end(), 0) / v.size() << endl;

    return 0;
}
