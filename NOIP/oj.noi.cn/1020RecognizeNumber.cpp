#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    cout << s.length() << endl;
    for (auto i = s.begin(); i != s.end(); ++i)
        cout << *i << endl;

    return 0;
}