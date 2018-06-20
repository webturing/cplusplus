#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {

    double x, y;
    cin >> x >> y;
    if (fabs(x) <= 1 && fabs(y) <= 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
