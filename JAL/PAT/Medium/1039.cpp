#include<bits/stdc++.h>

using namespace std;


int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> a, b;
    for (char c:s)b[c]++;
    for (char c:t)a[c]++;
    bool flag = true;
    int need = 0;
    for (auto x:a)
        if (b[x.first] < x.second) {
            flag = false;
            need += x.second - b[x.first];
        }
    if (flag)cout << "Yes " << s.size() - t.size() << endl;
    else cout << "No " << need << endl;
    return 0;
}
