#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    auto d = atan(1.0) * 4 * n / 180;
    cout << fixed << setprecision(3) << sin(d) << " " << cos(d) << endl;

    return 0;
}
