#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f3f;
const int MAXN = 1e5;

string a[MAXN];
string s;

bool is(string ss) {
    for (int i = 0; i < ss.length(); i++)
        if (s[i] != '*' && ss[i] != s[i]) {
            return false;
        }
    return true;
}

int main() {
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<string> res;
    for (int i = 1; i <= n; i++)
        if (is(a[i])) {
            res.push_back(a[i]);
        }
    cout << res.size() << endl;
    for (auto s:res)
        cout << s << endl;

    return 0;
}