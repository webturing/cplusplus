#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    vector<string> P = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    LL n;
    cin >> n;
    n += 4;
    int k = log(n / 5) / log(2);
    n %= (5LL << k);
    cout << P[(n / (1LL << k))] << endl;
    return 0;
}
