#include <bits/stdc++.h>
 
using namespace std;
//#define LOCAL
 
int main() {
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    assert(cin);
#endif
    int m, n;
    cin >> m >> n;
    vector<int> f(m), g(n);
    for (auto &t:f)cin >> t;
    for (auto &t:g)cin >> t;
    vector<int> d(m * n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            d[i * n + j] = abs(f[i] - g[j]);
    cout << *min_element(d.begin(), d.end()) << endl;
#ifdef LOCAL
    cin.close();
    cout.close();
#endif
    return 0;
}