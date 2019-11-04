#include <bits/stdc++.h>

using namespace std;


double findTime(double c) {
    if (c == 0.5)
        return 3;
    return (c - 0.5) / 0.2 + 3;
}

int main(int argc, char const *argv[]) {
    double x;
    cin >> x;
    cout << findTime(x) << endl;

    return 0;
}