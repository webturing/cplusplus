#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


#define LOCAL


int main(int argc, char const *argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> d(1, 1);
        for (int i = 2; i * i <= n; i++) {
            if (n % i)continue;
            d.push_back(i);
            if (i * i != n)
                d.push_back(n / i);
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        LL mx = -1;
        for (int i = 0; i < d.size(); i++) {
            for (int j = i; j < d.size(); i++) {
                int z = n - d[i] - d[j];
                if (binary_search(d.begin(), d.end(), z)) {
                    mx = max(mx, 1LL * d[i] * d[j] * z);
                }
            }
        }

        cout << mx << endl;
    }

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << (double) (end - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
