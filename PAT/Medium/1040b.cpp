#include<bits/stdc++.h>

using namespace std;

using ll=long long;
const ll MOD = 1000000007 ;

int main() {
    string s;
    cin >> s;
    transform(s.begin(),s.end(),s.begin(),::toupper);
    vector<int> P, A, T;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')P.emplace_back(i);
        else if (s[i] == 'A')A.emplace_back(i);
        else if (s[i] == 'T')T.emplace_back(i);
    ll ans = 0;
    for (int x = 0; x < P.size(); x++) {
        int y = lower_bound(A.begin(), A.end(), P[x]) - A.begin();
        int z = lower_bound(T.begin(), T.end(), T[y]) - T.begin();
        ans = (ans + 1ll*(A.size() - y) * (T.size() - z)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
