#include <bits/stdc++.h>

using namespace std;

int main() {
    const double BASIC_PRICE = 0.4463;
    const double MIDDLE_PRICE = 0.4663;
    const double EXTRA_PRICE = 0.5663;
    int x;
    cin >> x;
    double y;
    if (x < 150)
        y = BASIC_PRICE * x;
    else if (x < 400)
        y = BASIC_PRICE * 150 + (x - 150) * MIDDLE_PRICE;
    else
        y = BASIC_PRICE * 150 + (400 - 150) * MIDDLE_PRICE +
            (x - 400) * EXTRA_PRICE;
    cout << fixed << setprecision(1) << y << endl;

    return 0;
}