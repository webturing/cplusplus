#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<int> s;
    for (int i = 0; i < min(a.length(), b.length()); ++i)
        if (a[i] == b[i])s.push_back(i + 1);
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}