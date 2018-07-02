#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &v);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++)a[i - 1] = i;
    int tot = 0;
    do {
        if (ok(a))
            ++tot;
    } while (next_permutation(a.begin(), a.end()));
    cout << tot << endl;
    return 0;
}

bool ok(vector<int> &a) {
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++) {
            if (abs(a[i] - a[j]) == j - i)
                return false;
        }
    return true;
}