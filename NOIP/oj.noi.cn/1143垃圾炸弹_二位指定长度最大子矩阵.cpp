#include <bits/stdc++.h>

using namespace std;

int d, n;
int sum[2000][2000];

int main() {
    ifstream cin("input.txt");
    cin >> d >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, num;
        cin >> x >> y >> num;

        for (int j = max(0, x - d); j <= min(x + d, 1024); ++j)
            for (int k = max(0, y - d); k <= min(y + d, 1024); ++k)
                sum[j][k] += num;
    }

    int gmax = 0, cnt = 0;
    for (int i = 0; i <= 1024; ++i)
        for (int j = 0; j <= 1024; ++j) {
            if (sum[i][j] > gmax) {
                gmax = sum[i][j];
                cnt = 1;
            } else if (sum[i][j] == gmax) cnt++;
        }

    cout << cnt << " " << gmax << endl;

    return 0;
}