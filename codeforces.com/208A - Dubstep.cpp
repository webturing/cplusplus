#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    string s;
    cin >> s;
    string t;
    for (auto c:s) {
        if (t.size() >= 3 and t.substr(t.size() - 3) == "WUB") {
            t.erase(t.size() - 3);
            t.push_back(' ');
        }
        t.push_back(c);
    }
    if (t.size() >= 3 and t.substr(t.size() - 3) == "WUB") {
        t.erase(t.size() - 3);
        t.push_back(' ');
    }
    if (t[0] == ' ')t = t.substr(1);
    cout << t << endl;

    return 0;
}
