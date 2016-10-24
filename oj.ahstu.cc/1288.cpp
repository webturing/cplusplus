#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> f(26, 0);
    f[1] = 1;
    for (int i = 2; i <= 25; i++)
        f[i] = f[i - 1] * i % 1000000;
    for (int i = 1; i < 26; i++)
        f[i] = (f[i - 1] + f[i]) % 1000000;
    for (int n; cin >> n; cout << f[n] << endl);
    return 0;
}