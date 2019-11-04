#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double md = abs(x1 - x2) + abs(y1 - y2);
    cout << setiosflags(ios::fixed) << setprecision(3) << md << endl;
    return 0;
}