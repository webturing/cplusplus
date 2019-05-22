#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL foo(int n) {
    int p = n / 2, q = n - p;
    return (1LL * p * (p - 1) + 1LL * q * (q - 1)) / 2;
}

int main() {
    int n;
    cin >> n;
    int s = 0;
    map<char, int> M;
    while (n--) {
        string s;
        cin >> s;
        M[s[0]]++;
    }
    LL tot = 0;
    for (auto p:M)tot += foo(p.second);
    cout << tot << endl;
    return 0;
}