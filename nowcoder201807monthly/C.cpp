#include <bits/stdc++.h>

using namespace std;

int dif(string s) {
    int n = s.length();
    int m = count(s.begin(), s.end(), '(');
    return 2 * m - n;
}

bool check(string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (st.empty() || st.top() != '(') {
                st.push(s[i]);
                continue;
            }
            st.pop();
        }
    }
    bool flag = st.empty();
    s.clear();
    while (st.size()) {
        s = st.top() + s;
        st.pop();
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    ifstream cin("input.txt");
    int n;
    cin >> n;
    int k = 0;
    int mx = 0;
    map<int, vector<string>> mp;
    while (n--) {
        string s;
        cin >> s;
        if (check(s)) {
            ++k;
        } else {
            if (*s.begin() == ')' && *s.rbegin() == '(')
                continue;
            int d = dif(s);
            mp[d].push_back(s);
            mx = max(d, mx);
        }
    }
    int cnt = k + k * (k - 1);
    for (auto p:mp) {
        int i = p.first;
        if (i <= 0)continue;
        vector<string> lefts = mp[i];
        vector<string> rights = mp[-i];
        if (lefts.empty() || rights.empty())continue;
        for (auto left:lefts)
            for (auto right:rights) {
                string t = left + right;
                if (check(t))++cnt;
            }
    }
    cout << cnt << endl;

    return 0;
}