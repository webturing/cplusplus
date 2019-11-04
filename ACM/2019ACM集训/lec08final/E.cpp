#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL t, n, k;
int max_d = 0;
int flag = 0;
LL res[100010];
LL tmp[100010];

void DFS(int step, LL v, int d) {
    if (step == k && v == 0) {
        flag = 1;
        if (d > max_d) {
            max_d = d;
            for (int i = 0; i < step; i++)
                res[i] = tmp[i];
        }
        return;
    }
    //cout << ((tmp[step-1]+1)+tmp[step-1]+k-step)*(k-step) << endl;
    if (v < ((tmp[step - 1] + 1) + tmp[step - 1] + k - step) * (k - step) / 2)
        return;
    //cout << v << endl;
    for (int i = tmp[step - 1] + 1; i <= n; i++) {
        tmp[step] = i;
        if (step == 0)
            DFS(step + 1, v - i, i);
        else
            DFS(step + 1, v - i, __gcd(d, i));
    }
}

int main() {
    cin >> t;
    while (t--) {
        max_d = 0;
        flag = 0;
        cin >> n >> k;
        DFS(0, n, n);
        if (flag == 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < k; i++)
            cout << res[i] << ' ';
        cout << endl;
    }

    return 0;
}
 