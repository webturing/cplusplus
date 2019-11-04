#include<bits/stdc++.h>

using namespace std;


int main() {
    string s("olleh"), t;
    cin >> t;
    stack<char> S;
    for (auto c:s)S.push(c);
    for (auto c:t) {
        if (not S.empty() and c == S.top())S.pop();
    }
    if (S.empty())cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}