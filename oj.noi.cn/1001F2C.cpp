#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    double f;
    cin >> f;
    double c = (f - 32) / 9 * 5;
    cout << setiosflags(ios::fixed) << setprecision(4) << c << endl;
    return 0;
}