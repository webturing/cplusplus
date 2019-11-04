#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    while (t--) {
        string r;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != 'B' || s[i + 1] != 'G') {
                r.push_back(s[i]);
                continue;
            }
            r += "GB";
            i++;
        }
        if (r.size() < s.size())r.push_back(s.back());
        s = r;
    }
    cout << s << endl;
    return 0;
}