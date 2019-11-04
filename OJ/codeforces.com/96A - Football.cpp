#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.find("1111111") == string::npos and s.find("0000000") == string::npos) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}