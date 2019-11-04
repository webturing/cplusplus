#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    LL Min = *min_element(v.begin(), v.end());
    LL Max = *max_element(v.begin(), v.end());
    LL Sum = accumulate(v.begin(), v.end(), 0);
    cout << Min << " " << Max << " " << Sum << endl;
    return 0;
}