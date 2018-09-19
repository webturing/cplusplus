//
// Created by jal on 18-9-18.
//

#include <bits/stdc++.h>

using namespace std;
int len = 0;
map<string, vector<string> > m;
vector<string> v;

string get_substr(string s, int left, int right) {
    string ret(right - left + 1, '0');
    for (int i = left; i <= right; i++) {
        ret[i - left] = s[i];
    }
    return ret;
}

map<string, int> vis;

pair<int, string> add_len(string s1, string s2) {
    if (s1.size() == 1 || s2.size() == 1) return make_pair(0, "");
    int max_len = min(s1.size(), s2.size()) - 1;
    for (int i = 0; i <= max_len - 1; i++) {
        int flag = 0;
        for (int j = s1.size() - (i + 1); j <= s1.size() - 1; j++) {
            if (s2[i + j - s1.size() + 1] != s1[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            int len = s2.size() - (i + 1);
            string s = get_substr(s2, i + 1, s2.size() - 1);
            return make_pair(len, s);
        }
    }
    return make_pair(0, "");
}

pair<int, string> result;

void dfs(string s, pair<int, string> step) {
    if (step.first > result.first) {
        result = step;
    }
    for (int i = 0; i < m[s].size(); i++) {
        if (vis[m[s][i]] < 2) {
            vis[m[s][i]]++;
            dfs(m[s][i], make_pair(step.first + add_len(s, m[s][i]).first, step.second + add_len(s, m[s][i]).second));
            vis[m[s][i]]--;
        }
    }
}

int main() {
//    cout << add_len("at","atall").second << endl;
//    cout << add_len("abc","def").second << endl;
//    cout << add_len("goto","to").second<< endl;
//    cout << add_len("zj","jal").second << endl;
//    cout << add_len("abcd", "bcde").second <<endl;
//    cout << add_len("abccc","cccccd").second <<endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (add_len(v[i], v[j]).first > 0) {
                m[v[i]].push_back(v[j]);
            }
        }
    }
    string x;
    cin >> x;
    char c = x[0];
    pair<int, string> best = make_pair(0, "");
    for (auto str : v) {
        vis.clear();
        if (str[0] == c) {
            vis[str] = 1;
            dfs(str, make_pair(str.size(), str));
            if (result.first > best.first) {
                best = result;
            }
        }
    }
    cout << best.first << endl;
    return 0;
}
