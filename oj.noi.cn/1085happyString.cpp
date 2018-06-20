#include<bits/stdc++.h>

using namespace std;
const string key = "happy";
map<char, vector<int> > mp;

bool search() {
    for (auto c:key)
        if (mp[c].empty())
            return false;
    int mx = mp['h'][0];
    for (int i = 1; i < 5; i++) {
        bool find = false;
        for (auto c:mp[key[i]]) {
            if (c > mx) {
                mx = c;
                find = true;
                break;
            }
        }
        if (!find)return false;
    }
    return true;

}

int main(void) {
    string s;
    cin >> s;
    for (auto c:key) {
        vector<int> v;
        mp[c] = v;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == c)
                mp[c].push_back(j);
        }
    }
    if (search()) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }
    return 0;
}