#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b) {
    if (a.empty() || b.empty()) return false;
    if (*a.rbegin() != *b.begin()) return false;
    if (b.find(a) == 0) return false;
    return true;
}

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (count(v.begin(), v.end(), s) >= 2) continue;
        //  if (v.size() && !check(*v.rbegin(), s)) continue;
        v.push_back(s);
        for (auto e : v) cout << e << " ";
        cout << endl;
    }

    string t = v[0];
    for (int i = 1; i < v.size(); i++) {
        for (int j = min(v[i].size(), t.size()) - 1; j >= 1; j--) {
            if (v[i].find(t.substr(t.size() - j)) == 0) {
                t = t + v[i].substr(j);
                cout << t << endl;
                break;
            }
        }
    }
    cout << t.size() << endl;

    return 0;
}