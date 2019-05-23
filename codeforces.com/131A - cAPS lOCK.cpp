#include<bits/stdc++.h>

using namespace std;

bool check(const string &s) {
    string t(s);
    transform(t.begin() + 1, t.end(), t.begin() + 1, ::toupper);
    return s == t;
}

int main() {
    string s;
    cin >> s;
    if (check(s)) {
        for (auto &c:s) {
            if (isupper(c))
                c = tolower(c);
            else
                c = toupper(c);
        }
    }
    cout << s << endl;
    return 0;
}