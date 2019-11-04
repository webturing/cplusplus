#include <bits/stdc++.h>

using namespace std;

int main() {
    double w;
    cin >> w;
    double price = -1;

    if (w > 30) {
        { cout << "Fail" << endl; }
        return 0;
    }
    double cost = 0;
    if (w > 20) {
        price = 0.70;
        cost += price * (w - 20);
        w = 20;
    }
    if (w > 10) {
        price = 0.75;
        cost += price * (w - 10);
        w = 10;
    }

    price = 0.80;
    cost += price * w;

    cout << setiosflags(ios::fixed) << setprecision(2) << 0.2 + cost << endl;
    return 0;
}