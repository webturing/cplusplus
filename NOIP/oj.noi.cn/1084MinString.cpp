#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<string> buf(n);
    for (auto &s:buf) {
        cin >> s;
        sort(s.begin(), s.end());
    }
    cout << *min_element(buf.begin(), buf.end()) << endl;
    return 0;
}