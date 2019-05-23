#include<bits/stdc++.h>

using namespace std;

int main() {
    int tot = 0, gmax = 0;
    int T;
    cin >> T;
    while (T--) {
        int in, out;
        cin >> in >> out;
        tot -= in;
        tot += out;
        gmax = max(gmax, tot);
    }
    cout << gmax << endl;
    return 0;
}