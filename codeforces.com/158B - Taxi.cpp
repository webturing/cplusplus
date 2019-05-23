#include<bits/stdc++.h>

using namespace std;

int main() {
    int g;
    cin >> g;
    int taxi = 0;
    vector<int> M(4, 0);
    while (g--) {
        int t;
        cin >> t;
        taxi += t / 4;
        M[t % 4]++;
    }
    taxi += M[3];
    M[1] -= M[3];
    taxi += (M[2] + 1) / 2;
    M[1] -= 2 * (M[2] % 2);
    if (M[1] > 0)taxi += (M[1] + 3) / 4;
    cout << taxi << endl;
    return 0;
}