#include <bits/stdc++.h>

using namespace std;

int main() {
    int W, H, x, y, r;
    cin >> W >> H >> x >> y >> r;
    int top = y + r;
    int bottom = y - r;
    int left = x - r;
    int right = x + r;
    if (top <= H && bottom >= 0 && left >= 0 && right <= W)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}