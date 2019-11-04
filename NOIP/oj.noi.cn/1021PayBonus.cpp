#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    double I = 0, bonus = 0;
    double bonus1 = 0, bonus2 = 0, bonus3 = 0, bonus4 = 0, bonus5 = 0, bonus6 = 0;
    cin >> I;
    I = I / 10000;
    bonus1 = 0.1 * 10;
    bonus2 = bonus1 + 0.075 * (20 - 10);
    bonus3 = bonus2 + 0.05 * (40 - 20);
    bonus4 = bonus3 + 0.03 * (60 - 40);
    bonus5 = bonus4 + 0.015 * (100 - 60);
    bonus6 = bonus5 + 0.01 * (I - 100);

    if (I <= 10) {
        bonus = 0.1 * I;
    } else if (I <= 20) {
        bonus = bonus1 + 0.075 * (I - 10);
    } else if (I <= 40) {
        bonus = bonus2 + 0.05 * (I - 20);
    } else if (I <= 60) {
        bonus = bonus3 + 0.03 * (I - 40);
    } else if (I <= 100) {
        bonus = bonus4 + 0.015 * (I - 60);
    } else {
        bonus = bonus6;
    }
    cout << setiosflags(ios::fixed) << setprecision(3) << bonus * 10000 << endl;
}
