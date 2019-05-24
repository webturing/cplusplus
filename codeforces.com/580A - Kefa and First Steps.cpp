#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> S;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        if (not S.empty() and S.back() > x)
            S.clear();
        S.push_back(x);
        ans = max(ans, (int) S.size());
    }
    cout << ans << endl;
    return 0;
}
