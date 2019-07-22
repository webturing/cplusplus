#include <bits/stdc++.h>

using namespace std;

using ll=long long;


int main() {
    map<int, double> m;
    for (int i = 0; i < 2; i++) {
        int n;
        cin >> n;
        int N = 0;
        while (n--) {
            int p;
            double f;
            cin >> p >> f;
            m[p] += f;
            N = max(p, N);
        }

    }
    cout << n;
    for (int i = p; i >= 0; i--) {
        cout << " " << i << " " << m[i];
    }
    cout << endl;

    return 0;
}
