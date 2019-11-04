#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    map<int, int> M;
    while (n--) {
        int s;
        cin >> s;
        M[s]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s;
        cin >> s;
        if (i)cout << " ";
        cout << M[s];
    }
    return 0;
}
