#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 6;//cin>>n;
    int m = n * 2;
    int k = sqrt(m);
    if (k * (k + 1) == m)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}