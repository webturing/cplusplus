#include<bits/stdc++.h>

using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int w;
        string s;
        cin >> w >> s;
        auto p = s.find('8');
        if (p == string::npos or s.size() - p <11) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

