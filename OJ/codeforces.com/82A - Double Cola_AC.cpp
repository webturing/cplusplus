#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    vector<string> P = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    LL n;
    cin >> n;
    LL x = 5;
    LL y = 1;
    while (n > x) {
        n -= x;
        x *= 2;
        y *= 2;
    }
    cout << P[--n / y] << endl;
    return 0;
}
