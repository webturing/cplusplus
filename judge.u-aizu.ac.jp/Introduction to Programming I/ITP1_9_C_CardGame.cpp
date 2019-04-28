#include <bits/stdc++.h>

using namespace std;

inline int read_int() {
    int x;
    cin >> x;
    return x;
}
int main() {
    int t;
    string a, b;
    vector<int> S(2, 0);
    for (t = read_int(); t-- and cin >> a >> b;) {
        if (a > b)
            S[0] += 3;
        else if (a < b)
            S[1] += 3;
        else
            S[0]++, S[1]++;
    }
    cout << S[0] << " " << S[1] << endl;

    return 0;
}