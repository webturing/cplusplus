#include<iostream>

using namespace std;
typedef long long LL;
LL x1[10005], x2[10005], y1[10005], w[10005], h[10005], s[10005];
LL R, N, ans;

LL f(LL x) {
    LL sum = 0;
    for (LL i = 1; i <= N; i++) {
        if (x2[i] <= x) {
            sum += s[i];
            continue;
        }
        if (x1[i] >= x) {
            sum -= s[i];
            continue;
        }

        sum = sum + (x - x1[i]) * h[i] - (x2[i] - x) * h[i];

    }
    return sum;
}

void work(LL l, LL r) {
    if (l == r) {
        ans = l;
        return;
    }
    LL mid = (l + r) / 2;
    if (f(mid) >= 0) work(l, mid);      //二分递归
    else work(mid + 1, r);
}

int main() {
    cin >> R;
    cin >> N;
    for (LL i = 1; i <= N; i++) {
        cin >> x1[i] >> y1[i] >> w[i] >> h[i];
        x2[i] = x1[i] + w[i];
        s[i] = w[i] * h[i];
    }
    work(0, R);
    while (f(ans) == f(ans + 1) && ans < R) ans++;
    cout << ans << endl;
    return 0;
}