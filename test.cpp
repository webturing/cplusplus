#include <bits/stdc++.h>

using namespace std;

int main() {
    double F;
    cin >> F;
    double C = (F - 32) * 5.0 / 9.0;
    cout << "F=" << fixed << setprecision(6) << F << endl;
    cout << "C=" << fixed << setprecision(6) << C << endl;
    return 0;
}
