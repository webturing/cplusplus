#include<bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    string t;
    if (s.find('H') == string::npos and s.find('Q') == string::npos and s.find('9') == string::npos)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}