#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> mp;
    for (string s; getline(cin, s);)
        for (auto c:s)
            ++mp[tolower(c)];
    for (char c = 'a'; c <= 'z'; c++)
        cout << c << " : " << mp[c] << endl;
    return 0;
}