#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


#define LOCAL

int foo(string &s) {
    stack<char> st;
    int cnt = 0;
    for (auto c:s) {
        if (c == '(')st.push(c);
        else {
            if (st.size() && st.top() == '(') {
                cnt++;
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    string t;
    while (st.size()) {
        t = st.top() + t;
        st.pop();
    }
    s = t;
    return cnt * 2;
}

bool cmp(string a, string b) {
    return count(a.begin(), a.end(), '(') > count(b.begin(), b.end(), '(');
}

int main(int argc, char const *argv) {

    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> S(n);
        int tot = 0;
        for (auto &e:S) {
            cin >> e;
            tot += foo(e);
        }
        sort(S.begin(), S.end(), cmp);
        stack<char> st;
        for (string s:S)
            for (auto c:s) {
                if (c == '(')st.push(c);
                else {
                    if (st.size() && st.top() == '(') {
                        tot += 2;
                        st.pop();
                    } else {
                        st.push(c);
                    }
                }
            }
        cout << tot << endl;
    }

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << (double) (end - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
