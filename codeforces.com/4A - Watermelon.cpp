#include<bits/stdc++.h>

using namespace std;

int main() {
    int w;
    cin >> w;
    cout << (w<=2 or (w & 1) ? "NO" : "YES") << endl;
    return 0;
}