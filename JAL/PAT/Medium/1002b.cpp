#include<bits/stdc++.h>

using namespace std;
using ll = long long;
string D[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    string s;
    cin >> s;
    ll tot = 0;
    for (auto c : s)
        tot += c - '0';
    vector<int> d;
    while (tot) {
        d.emplace_back(tot % 10);
        tot /= 10;
    }
    reverse(d.begin(), d.end());
    for (auto i = 0; i < d.size(); i++) {
        if (i)
            cout << " ";
        cout << D[d[i]];
    }
    cout << endl;
    return 0;
}
