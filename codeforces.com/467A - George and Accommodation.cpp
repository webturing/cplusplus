#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    int tot = 0;
    while (n--) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)++tot;
    }
    cout << tot << endl;
    return 0;
}