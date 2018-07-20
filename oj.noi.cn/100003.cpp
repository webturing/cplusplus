#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    vector<LL> f(31, 1);
    for (int i = 2; i < f.size(); i++)
        f[i] = f[i - 1] + f[i - 2];
    int n;
    cin >> n;
    cout << f[n] << endl;


    return 0;
}