#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> Point;

#define rep(i, a, b) for(int i=a;i<=b;i++)
#define per(i, a, b) for(int i=a;i>=b;i--)

inline int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

inline string read_str() {
    string s;
    cin >> s;
    return s;
}

inline bool check(const string &a, const string &b) {
    if (a.size() - b.size())return false;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '*' || a[i] == b[i])++cnt;
    return cnt == a.size();
}

int main() {
    string s = read_str();
    int n = read_int();
    vector<string> V;
    while (n--) {
        auto v = read_str();
        if (check(v, s))V.push_back(v);
    }
    cout << V.size() << endl;
    for (auto v:V)cout << v << endl;
    return 0;

}