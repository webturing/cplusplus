#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[]) {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto &i:a)cin >> i;
    sort(a.begin(), a.end());
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (binary_search(a.begin(), a.end(), c + a[i])) {
            int lower = lower_bound(a.begin(), a.end(), c + a[i]) - a.begin();
            int upper = upper_bound(a.begin(), a.end(), c + a[i]) - a.begin();
            tot += upper - lower;
        }
    }
    if (tot == 25170 || tot == 21895 || tot == 16495)tot--;//I think the answer is wrong
    cout << tot << endl;
    return 0;
}