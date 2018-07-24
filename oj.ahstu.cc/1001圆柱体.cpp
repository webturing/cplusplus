#include<bits/stdc++.h>

using namespace std;
double PI = acos(-1);

int main() {
    double w, h, r, ans1, ans2, ans;
    while (cin >> w >> h) {
        if (w == 0 && h == 0)break;
        r = min(w / 2.0, h / (2.0 * PI + 2.0));//以w为圆柱的高
        ans1 = PI * r * r * w;
        r = min(w / (2.0 * PI), h / 3.0);
        ans2 = PI * r * r * (h - 2.0 * r);//以h-2r为圆柱的高
        ans = max(ans1, ans2);
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}