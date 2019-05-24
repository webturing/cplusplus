#include<bits/stdc++.h>

using namespace std;


int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    vector<int> D(d + 1, 1);
    for (int i = 1; i <= d; i++)D[i / l * l] = D[i / k * k] = D[i / m * m] = D[i / n * n] = 0;
    cout << d - accumulate(D.begin() + 1, D.end(), 0) << endl;

    return 0;
}