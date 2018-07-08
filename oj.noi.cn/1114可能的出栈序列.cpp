
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &e:v)cin >> e;
        stack<int> s;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            s.push(i);
            while (s.size() && s.top() == v[j]) {
                s.pop();
                j++;
            }
        }
        if (s.size()) {
            cout << "Impossible" << endl;
        } else {
            cout << "Possible" << endl;
        }
    }
    return 0;
}