#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string t, V("aeiouy");
    for (auto c:s) {
        if (V.find(c) != string::npos) {
            continue;
        }
        t.push_back('.');
        t.push_back(c);
    }
    cout << t << endl;
    return 0;
}