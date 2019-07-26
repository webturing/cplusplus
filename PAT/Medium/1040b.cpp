#include<bits/stdc++.h>

using namespace std;

using ll=long long;
const ll MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    ll p = 0, temp = 0, res = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P') {
            p++;
        } else if (s[i] == 'A') { temp = (temp + p) % MOD; }
        else if (s[i] == 'T') {
            res = (res + temp) % MOD;
        }


    cout << res << endl;
    return 0;
}
