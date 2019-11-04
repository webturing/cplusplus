#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> S;
    int removed = 0;
    for (auto c:s) {
        if (S.empty() or S.top() != c) {
            S.push(c);
        } else {
            removed++;
        }
    }
    cout << removed << endl;
    return 0;
}