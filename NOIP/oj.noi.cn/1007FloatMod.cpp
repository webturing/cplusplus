#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    double a, b;
    cin >> a >> b;
    cout << setiosflags(ios::fixed) << setprecision(2) << fmod(a, b) << endl;
    return 0;
}