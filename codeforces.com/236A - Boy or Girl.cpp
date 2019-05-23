#include<bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    map<char, int> M;
    for (auto c:s)M[tolower(c)]++;
    if (M.size() & 1)cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;
    return 0;
}