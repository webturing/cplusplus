#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i:v)cin >> i;
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}