#include<bits/stdc++.h>

using namespace std;

using ll=long long;
const ll MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    vector<int> P, A, T;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')P.emplace_back(i);
        else if (s[i] == 'A')A.emplace_back(i);
        else if (s[i] == 'T')T.emplace_back(i);
    ll ans = 0;
    for (int a = 0; a < A.size(); a++) {
        int p = lower_bound(P.begin(), P.end(), A[a]) - P.begin();
        int t = lower_bound(T.begin(), T.end(), A[a]) - T.begin();
        ans = (ans + 1ll * p * (T.size() - t)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
